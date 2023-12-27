#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::filesystem;

static size_t n_files_discovered;

void match_extension(const directory_entry& entry, string_view extension) {
    if (entry.path().extension() == extension) {
        cout << entry.path().filename() << endl;
        ++n_files_discovered;
    }  
}

int main(int argc, const char** argv) {
    if (argc != 3) {
        cerr << "Usage: file_name PATH .extension";
        return -1;
    }

    const path sys_path{argv[1]};

    for (const auto& entry : recursive_directory_iterator{sys_path}) match_extension(entry, argv[2]); 

    cout << "Discovered " << n_files_discovered << " " << argv[2] << " files" << endl;           
}

// This program is used to search for a file extension given a CLI argument