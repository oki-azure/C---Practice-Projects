/***************************************************************************************************************************************
17-1
Implement a program that takes two arguments: a path and an extension.

The program should search the given path recursively and print any file with the specified extension.
***************************************************************************************************************************************/

#include <iostream>
#include <filesystem>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using namespace std::filesystem;
using namespace std::chrono;

/* 
void match_extension(const directory_entry& entry, string_view extension) {
   if (entry.path().extension() == extension) cout << entry.path().filename() << endl;
}

int main(int argc, const char** argv) {
    if (argc != 3) {
        cerr << "Usage: file_name PATH .extension";
        return -1;
    }

    const path sys_path{argv[1]};

    for (const auto& entry : recursive_directory_iterator{sys_path}) match_extension(entry, argv[2]);            
}
*/


/***************************************************************************************************************************************
17-2
Improve the program in Listing 17-8 so it can take an optional second argument. 

If the first argument begins with a hyphen (-), the program reads all contiguous letters immediately following the hyphen and parses
each letter as an option. 

The second argument then becomes the path to search. 

If the list of options contains an R, perform a recursive directory. 

Otherwise, don't use a recursive directory iterator.
***************************************************************************************************************************************/

/* 
struct Attributes {
    Attributes& operator+=(const Attributes& other) {
        this->size_bytes += other.size_bytes;

        this->n_directories += other.n_directories;

        this->n_files += other.n_files;

        return *this;
    }
   
    size_t size_bytes, n_directories, n_files;
};

void print_line(const Attributes& attributes, path path) {
    cout << setw(12) << attributes.size_bytes << setw(6) << attributes.n_files << setw(6) << attributes.n_directories << " " << path.filename().string() << "\n";
}

Attributes explore(const directory_entry& directory) {
    Attributes attributes{};

    for (const auto& entry : recursive_directory_iterator{directory.path()}) {
        if (entry.is_directory()) attributes.n_directories++;

        else {
            attributes.n_files++;

            attributes.size_bytes += entry.file_size();
        }
    }

    return attributes;
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        cerr << "Usage: file_name -[OPTIONS] PATH";

        return -1;
    }

    Attributes root_attributes{};

    if (argv[1][0] == '-') {
        string options{argv[1]};

        const path sys_path{argv[2]};

        for (size_t i{}; i < options.length(); ++i) {
            if (argv[1][i] == 'R') {
                cout << "-----Recursive Directory Iteration------" << endl;

                cout << "Size         Files Dirs  Name\n";

                cout << "------------ ----- ----- ------------------------------------------\n"; 

                for (const auto& entry : directory_iterator{sys_path}) {
                    try {
                        if (entry.is_directory()) {
                            const auto attributes = explore(entry);

                            root_attributes += attributes;

                            print_line(attributes, entry.path().string());

                            root_attributes.n_directories++;
                        }

                        else {
                            root_attributes.n_files++;

                            error_code ec;

                            root_attributes.size_bytes += entry.file_size(ec);

                            if (ec) cerr << "Error reading file size: " << entry.path().string() << endl;

                            cout << setw(12) << entry.file_size() << setw(6) << '*' << setw(6) << '*' << " " << entry.path().filename().string() << "\n";
                        }
                    }

                    catch (const exception&) {}
                }

            }
        }

        print_line(root_attributes, argv[2]);
    }

    else {
        const path sys_path{argv[1]};

        cout << "-----Directory Iteration------" << endl;

        cout << "Size           Name\n";

        cout << "------------  ------------------------------------------------\n";

        for (const auto& entry : directory_iterator{sys_path}) {
            if (entry.is_directory()) cout << setw(12) << "*";

            else {
                root_attributes.size_bytes += entry.file_size();

                cout << setw(12) << entry.file_size();

                error_code ec;

                if (ec) cerr << "Error reading file size: " << entry.path().string() << endl;
            }

            cout << "  " << entry.path().filename().string() << "\n";
        }

        cout << setw(12) << root_attributes.size_bytes << "  " << argv[1] << endl;
    }
  
    
        
}
*/


/***************************************************************************************************************************************
17-3
Refer to the documentation for the dir or ls command and implement as many of the options as possible in your new, improved version 
of Listing 17-8.
***************************************************************************************************************************************/

struct Attributes {
    size_t size_bytes, n_directories, n_files;

    Attributes& operator+=(const Attributes& other) {
        this->size_bytes += other.size_bytes;

        this->n_directories += other.n_directories;

        this->n_files += other.n_files;

        return *this;
    }
};

void print_line(const Attributes& attributes, path dir) {
    cout << setw(13) << attributes.size_bytes << setw(6) << attributes.n_files << setw(6) << attributes.n_directories << "  " << dir.filename().string() << "\n";
}

bool compareByName(const directory_entry& a, const directory_entry& b) {
    return a.path().filename().string() < b.path().filename().string();
}

bool compareBySize(const directory_entry& a, const directory_entry& b) {
    return a.file_size() < b.file_size();
}

bool compareByTime(const directory_entry& a, const directory_entry& b) {
    return last_write_time(a) < last_write_time(b);
}

Attributes explore(const directory_entry& directory) {
    Attributes attributes{};

    for (const auto& entry : recursive_directory_iterator{directory.path()}) {
        if (entry.is_directory()) {
            attributes.n_directories++;
        } 
        
        else {
            attributes.n_files++;

            attributes.size_bytes += entry.file_size();
        }
    }

    return attributes;
}

void list_directory(const path& sys_path, const string& options) {
    Attributes root_attributes{};

    cout << "-----Directory Iteration------" << endl;
    cout << "Size            Last Modified   Name                                        \n";
    cout << "-------------   -------------   --------------------------------------------\n";

    vector<directory_entry> entries, file_entries;

    for (const auto& entry : directory_iterator{sys_path}) entries.push_back(entry);
    
    // Sort entries based on options
    if (options.find('S') != string::npos) {
        for (const auto& entry : entries) if (entry.is_regular_file()) file_entries.push_back(entry);
        
        sort(file_entries.begin(), file_entries.end(), compareBySize);

        for (const auto& entry : file_entries) {
            root_attributes.size_bytes += entry.file_size();

            auto ftime = entry.last_write_time();

            auto sctp = time_point_cast<system_clock::duration>(ftime - file_time_type::clock::now() + system_clock::now());

            const auto lw_time = system_clock::to_time_t(sctp);

            cout << setw(13) << entry.file_size()
                << "   " << put_time(localtime(&lw_time), "%H:%M:%S") << "        " << entry.path().filename().string() << endl;
        }

        cout << setw(13) << root_attributes.size_bytes << "                   " << sys_path.string() << endl;

        return;
    } 
    
    else if (options.find('T') != string::npos) {
        sort(entries.begin(), entries.end(), compareByTime);
    } 
    
    else {
        sort(entries.begin(), entries.end(), compareByName);
    }

    for (const auto& entry : entries) {
        auto ftime = entry.last_write_time();

        auto sctp = time_point_cast<system_clock::duration>(ftime - file_time_type::clock::now() + system_clock::now());

        const auto lw_time = system_clock::to_time_t(sctp);

        if (entry.is_directory()) cout << setw(13) << "*";
                             
        else {            
            root_attributes.size_bytes += entry.file_size();

            cout << setw(13) << entry.file_size();
        }

        cout << "   " << put_time(localtime(&lw_time), "%H:%M:%S") << "        " << entry.path().filename().string() << endl;
    }

    cout << setw(13) << root_attributes.size_bytes << "                   " << sys_path.string() << endl;

}

void list_recursive_directory(const path& sys_path) {
    Attributes root_attributes{};

    cout << "-----Recursive Directory Iteration------" << endl;
    cout << "Size          Files Dirs   Name\n";
    cout << "------------- ----- -----  ------------------------------------------\n";

    vector<directory_entry> entries;
    for (const auto& entry : recursive_directory_iterator{sys_path}) entries.push_back(entry);
    

    // Sort entries by name by default
    sort(entries.begin(), entries.end(), compareByName);

    for (const auto& entry : entries) {
        try {
            if (entry.is_directory()) {
                const auto attributes = explore(entry);

                root_attributes += attributes;

                print_line(attributes, entry.path().string());

                root_attributes.n_directories++;
            } 
            
            else {
                root_attributes.n_files++;

                root_attributes.size_bytes += entry.file_size();
            }
        } 
        
        catch (const exception&) {}
    }

    print_line(root_attributes, sys_path.string());
}

int main(int argc, const char** argv) {
    if (argc < 2) {
        cerr << "Usage: treedir -[OPTIONS] PATH\n";

        return -1;
    }

    const path sys_path{argv[argc - 1]};

    if (argv[1][0] == '-') {
        string options{argv[1]};

        for (size_t i{}; i < options.length(); ++i) {
            if (options[i] == '-') continue;

            else if (options[i] == 'R') list_recursive_directory(sys_path);

            else if (options[i] == 'T') list_directory(sys_path, options);

            else if (options[i] == 'S') list_directory(sys_path, options);

            else cerr << "Unknown Operation" << endl;
        }
    } 
    
    else list_directory(sys_path, "");
       
}