/***********************************************************************************  
4-1. Create a struct TimerClass. In its constructor, record the current time in a 
field called timestamp (compare with the POSIX function gettimeofday).

4-2. In the destructor of TimerClass, record the current time and subtract the 
time at construction. This time is roughly the age of the timer. Print this value.

4-3. Implement a copy constructor and a copy assignment operator for 
TimerClass. The copies should share timestamp values.

4-4. Implement a move constructor and a move assignment operator for 
TimerClass. A moved-from TimerClass shouldn’t print any output to the console 
when it gets destructed.

4-5. Elaborate the TimerClass constructor to accept an additional const char* 
name parameter. When TimerClass is destructed and prints to stdout, include 
the name of the timer in the output.
***********************************************************************************/

#include <iostream>
#include <chrono>
#include <utility>

struct TimerClass {
    TimerClass(const char* name) : timestamp{std::chrono::system_clock::now()}, name{name} {
        std::time_t currentTime = std::chrono::system_clock::to_time_t(timestamp); 

        std::cout << "Constructed \'"<< name << "\' at " << std::ctime(&currentTime) << std::endl; 
    }

    ~TimerClass() {
        auto currentTime = std::chrono::system_clock::now(); 

        std::chrono::duration<double> elasped_time = currentTime - timestamp; 

        if (moved_from == false) printf("Lifetime of '%s': %f\n", name, elasped_time.count()); 
    }

    // Copy constructor 
    TimerClass(const TimerClass& copy) : timestamp{copy.timestamp}, name{copy.name} {}

    // Copy assignment 
    TimerClass& operator=(const TimerClass& copy) {
        if (this == &copy) return *this; 

        timestamp = copy.timestamp; 

        name = copy.name; 

        return *this; 
    }

    // Move constructor 
    TimerClass(TimerClass&& move) noexcept : timestamp{move.timestamp}, name{move.name} {
        move.name = nullptr; 

        move.moved_from = true; 
    }

    // Move assignment 
    TimerClass& operator=(TimerClass&& move) noexcept {
        if (this == &move) return *this; 

        timestamp = move.timestamp; 

        name = move.name; 

        move.name = nullptr; 

        move.moved_from = true; 

        return *this; 
    }

    private:
        std::chrono::time_point<std::chrono::system_clock> timestamp; 
        const char* name; 
        bool moved_from = false; 
}; 

void expensive_computation(TimerClass&& timer) {
    int n{1}; 

    for (int i = 0; i < 10000000; i++) n = (n*i*i) % 2021;    
}

int main() {
    TimerClass timer1{"Timer 1"}; 

    TimerClass timer2{"Timer 2"}; 

    TimerClass timer3 = std::move(timer1); // move assignment

    TimerClass timer4 = timer2; // copy assignment

    expensive_computation(std::move(timer3)); 
}