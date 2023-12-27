// This is a program that mocks cmd's dir(list directories command)

#include <iostream>
#include <filesystem>
#include <iomanip>

using namespace std;
using namespace std::filesystem;
using namespace std::chrono;


void describe(const directory_entry& entry) {
    try {
        if (entry.is_directory()) cout << "           *";   // width 12

        else cout << setw(12) << entry.file_size();

        auto ftime = entry.last_write_time();

        auto sctp = time_point_cast<system_clock::duration>(ftime - file_time_type::clock::now() + system_clock::now());

        const auto lw_time = system_clock::to_time_t(sctp);

        cout << setw(12) << lw_time
            << " " << entry.path().filename().string()
            << "\n";
    }

    catch(const std::exception& e) { 
        cout << "Error accessing " << entry.path().string()
            << ": " << e.what() << endl; 
    }
    
}

int main(int argc, const char** argv) {
    if (argc != 2) {
        cerr << "Usage: file_name PATH";

        return -1;
    }

    const path sys_path{argv[1]};

    cout << "Size         Last Write  Name\n";

    cout << "------------ ----------- ------------\n";

    for (const auto& entry : directory_iterator{sys_path}) describe(entry);
} 