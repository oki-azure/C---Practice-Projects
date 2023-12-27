/***************************************************************************************************************************************  
11-1
Reimplement Listing 11-12 to use a std::shared_ptr rather than a std::unique_ptr. 

Notice that although you’ve relaxed the ownership requirements from exclusive to non-exclusive, you’re still transferring ownership 

to the say_hello function
***************************************************************************************************************************************/

#include <cstdio>
#include <memory>

/*  
auto my_deleter = [](int* x) {
    printf("Deleting an int at 0x%x", x);
    delete x;
};


int main() {
    std::shared_ptr<int> my_up{new int, my_deleter};

    // for shared_ptr, you only pass the type of the 
    // owned object as a template parameter
}
*/

using FileGuard = std::shared_ptr<FILE>;

void say_hello(FileGuard file) { fprintf(file.get(), "Hello Azure!\n"); }

/*  
int main() {
    auto file = fopen("HAL9000(1).txt", "w");

    if (!file) return errno;

    FileGuard file_guard{file, fclose};

    // File is open here

    say_hello(std::move(file_guard));

    // File is closed here
}
*/


/***************************************************************************************************************************************  
11-2
Remove the std::move from the call to say_hello. 

Then make an additional call to say_hello. 

Notice that the ownership of file_guard is no longer transferred to say_hello. This permits multiple calls.
***************************************************************************************************************************************/

/*  
int main() {
    auto file = fopen("HAL9000.txt", "a");

    if (!file) return errno;

    FileGuard file_guard{file, fclose};

    say_hello(file_guard);

    say_hello(file_guard);

    say_hello(file_guard);
}
*/


/***************************************************************************************************************************************  
11-3. Implement a Hal class that accepts a std::shared_ptr<FILE> in its constructor. 

In Hal’s destructor, write the phrase Stop, Azure to the file handle held by your shared pointer. 

Implement a write_status function that writes the phrase I'm completely operational. to the file handle. 

Here’s a class declaration you can work from:
struct Hal {
    Hal(std::shared_ptr<FILE> file);
    ~Hal();
    void write_status();
    std::shared_ptr<FILE> file;
};
***************************************************************************************************************************************/

struct Hal {
    Hal(std::shared_ptr<FILE> file) : file{file} { fprintf(file.get(), "\nHello Azure!\n"); }

    ~Hal() { fprintf(file.get(), "Stop, Azure!\n"); }

    void write_status() { fprintf(file.get(), "I'm completely operational!\n"); }

    std::shared_ptr<FILE> file;
};

/*  
int main() {
    auto file = fopen("HAL9000.txt", "a");

    if (!file) return errno;
    
    std::shared_ptr<FILE> file_ptr{file, fclose};

    Hal hal{file_ptr};

    hal.write_status();
}
*/


/***************************************************************************************************************************************  
11-4
Create several Hal instances and invoke write_status on them. 

Notice that you don’t need to keep track of how many Hal instances are open: file 

management gets handled via the shared pointer’s shared ownership model.
***************************************************************************************************************************************/

/*  
int main() {
    auto file = fopen("HAL9000.txt", "a");

    if (!file) return errno;

    std::shared_ptr<FILE> file_ptr{file, fclose};

    Hal hal1{file_ptr};
    hal1.write_status();

    Hal hal2{file_ptr};
    hal2.write_status();

    Hal hal3{file_ptr};
    hal3.write_status();

    Hal hal4{file_ptr};
    hal4.write_status();

    Hal hal5{file_ptr};
    hal5.write_status();
} 
*/