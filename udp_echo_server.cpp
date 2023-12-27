#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <memory>

using namespace boost::asio;
 
struct UdpServer {
    explicit UdpServer(io_context& io_context, const ip::udp::endpoint& endpoint) : socket(io_context, endpoint) { read(); }
    
    void read() {
        socket.async_receive_from(boost::asio::buffer(data, max_length), sender_endpoint,
            [this](boost::system::error_code ec, size_t length) {
                if (!ec && length > 0) {
                    message = std::string(data, length);
                    boost::algorithm::to_upper(message);
                    write();
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