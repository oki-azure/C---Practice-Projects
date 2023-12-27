// This program is used to execute CLI commands, w/o directly interfacing with the CLI

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;
using namespace literals::chrono_literals;

/* 
int main() {
    std::string command{"ping -n 20 google.com"};

    const auto result = std::system(command.c_str());

    std::cout << "The command \'" << command << "\' returned " << result << std::endl;
} 
*/

int main() {
    std::ostringstream ss;
    
    std::string command;

    {
        ss << "tree C:\\Users\\Kelvin\\Downloads";

        command = ss.str();

        ss.str("");

        const auto result = std::system(command.c_str());

        cout << "The command \'" << command << "\' returned " << result << std::endl;
    }

    this_thread::sleep_for(5000ms); 

     
    {
        ss << "cls";

        command = ss.str();

        ss.str("");

        const auto result = std::system(command.c_str());

        cout << "The command \'" << command << "\' returned " << result << std::endl;
    }    
}