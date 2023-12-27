#include <iostream>
#include <string>
#include <fstream>
#include <boost/program_options.hpp>

// This program mocks the linux program grep, string and pattern matching utility that displays matching lines from multiple files
int main(int argc, char** argv) {
    using namespace boost::program_options;

    bool is_recursive{}, is_help{};

    options_description description{"mgrep [options] pattern paths..."};

    description.add_options() 
        ("help,h", bool_switch(&is_help), "display a help dialog")
        ("threads,t", value<int>()->default_value(4), "number of threads to use")
        ("recursive,r", bool_switch(&is_recursive), "search subdirectories recursively")
        ("pattern", value<std::string>(), "pattern to search for")
        ("paths", value<std::vector<std::string>>(), "paths to search");

    positional_options_description positional;

    positional.add("pattern", 1);
    positional.add("paths", -1);

    command_line_parser parser{argc, argv};

    parser.options(description);
    parser.positional(positional);

    variables_map vm;

    try {
        auto parsed_result = parser.run();

        store(parsed_result, vm);

        notify(vm);
    }

    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return -1;
    }

    if (is_help) {
        std::cout << description;
        return 0;
    }

    if (vm.count("pattern") == 0) {
        std::cerr << "You must provide a pattern\n";
        return -1;
    }

    if (vm.count("paths") == 0) {
        std::cerr << "You must provide at least one path\n";
        return -1;
    }
        
    const auto threads = vm["threads"].as<int>();

    const auto& pattern = vm["pattern"].as<std::string>();
    
    const auto& paths = vm["paths"].as<std::vector<std::string>>();    
    
    // Search for the pattern in each file
    for (const auto& path : paths) {
        std::ifstream file(path);
        if (!file) {
            std::cerr << "Failed to open file: " << path << '\n';
            continue;
        }

        std::string line;
        while (std::getline(file, line)) {
            if (line.find(pattern) != std::string::npos) {
                std::cout << "Found pattern \"" << pattern << "\" in file " << path << '\n';
            }
        }
    }

    std::cout << "Search completed" << std::endl;    
}