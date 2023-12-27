/***************************************************************************************************************************************
20-1
Use the Boost Asio documentation to investigate the UDP class analogs to the TCP classes you've learned about in this chapter. 
Rewrite the uppercasing echo server in Listing 20-14 as a UDP service.
***************************************************************************************************************************************/

/*  
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <array>

using namespace boost::asio;
 
struct UdpServer {
    explicit UdpServer(io_context& io_context, const ip::udp::endpoint& endpoint) : socket(io_context, endpoint) { read(); }
    
    void read() {
        socket.async_receive_from(boost::asio::buffer(data, max_length), sender_endpoint,
            [this](boost::system::error_code ec, size_t length) {
                if (!ec && length > 0) {
                    this->message = std::string(data,length);

                    boost::algorithm::to_upper(message);

                    this->write();
                }

                else socket.close();
            
            }
        );
    }

    void write() {
        socket.async_send_to(buffer(message), sender_endpoint,
            [this](boost::system::error_code ec, size_t length ) {
                if (ec) return;

                this->message.clear();

                this->read();
            }
        );
    }

    private:
        ip::udp::socket socket;  
        ip::udp::endpoint sender_endpoint;  
        std::string message; 
        size_t max_length{1024};
        char data[1024];
};

int main() {
    try {
        io_context io_context;  

        ip::udp::endpoint endpoint(ip::udp::v4(), 1896);

        if (!endpoint.address().is_unspecified() || endpoint.port() == 0) {
            std::cerr << "Error opening endpoint" << std::endl;
            return 1;
        }
        
        UdpServer udpServer(io_context, endpoint);

        io_context.run();
    } 
    
    catch (std::exception& e) { std::cerr << e.what() << std::endl; }
}   
*/


/***************************************************************************************************************************************
20-2
Use the Boost Asio documentation to investigate the ICMP classes. 
Write a program that pings all hosts on a given subnetwork to perform network analysis.
***************************************************************************************************************************************/

#include <boost/asio.hpp>
#include <boost/asio/ip/icmp.hpp>
#include <iostream>
#include <string>

using boost::asio::ip::icmp;
using boost::asio::deadline_timer;
using boost::asio::io_service;

struct Pinger {
    Pinger(io_service& io_service, const std::string& subnet) : resolver(io_service), socket(io_service, icmp::v4()), timer(io_service), subnet(subnet) {
        start_send();
        start_receive();
    }

    void start_send() {
        std::string body("\"Request from Boost.Asio\"");
        icmp::endpoint destination(boost::asio::ip::address::from_string(subnet), 1896);
        icmp::socket::message_flags flags = 0;
        socket.send_to(boost::asio::buffer(body), destination, flags);
        timer.expires_at(timer.expires_at() + boost::posix_time::seconds(1));
        timer.async_wait([this](boost::system::error_code ec) { start_send(); });
    }

    void start_receive() {
        socket.async_receive_from(boost::asio::buffer(receipt_buffer), sender_endpoint,
            [this](boost::system::error_code ec, size_t length) {
                if (!ec) std::cout << "Received reply from " << sender_endpoint.address().to_string() << std::endl;
                
                start_receive();
            }
        );
    }

    icmp::resolver resolver;
    icmp::socket socket;
    deadline_timer timer;
    icmp::endpoint sender_endpoint;
    char receipt_buffer[128];
    std::string subnet;
};

int main() {
    try {
        io_service io_service;
        Pinger pinger(io_service, "192.168.8.1"); 
        io_service.run();
    } 
    
    catch (std::exception& e) { std::cerr << "Exception: " << e.what() << std::endl; }
}