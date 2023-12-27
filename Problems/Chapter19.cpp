/***************************************************************************************************************************************
19-1
Write your own spin lock-based mutex called SpinLock. 

Expose a lock, a try_lock, and an unlock method. 

Your class should delete the copy constructor. 

Try using a std::lock_guard<SpinLock> with an instance of your class.
***************************************************************************************************************************************/

#include <atomic>
#include <future>
#include <iostream>

/* 
struct SpinLock {
    SpinLock() {};

    SpinLock(const SpinLock&) = delete;    
    
    std::atomic<bool> locked{false};

    void lock() { while (locked.exchange(true, std::memory_order_acquire)); }

    bool try_lock() { return !locked.exchange(true, std::memory_order_acquire); }

    void unlock() { locked.store(false, std::memory_order_release); }
};
*/

/***************************************************************************************************************************************
This code defines a SpinLock struct that uses an std::atomic<bool> to implement a spin lock. 
The lock method will spin in a loop until it can acquire the lock. 
The try_lock method will attempt to acquire the lock and return immediately with a boolean indicating whether it was successful. 
The unlock method releases the lock. 
***************************************************************************************************************************************/

using namespace std;

/* 
void goat_rodeo() {
    const size_t iterations{1'000'000};

    int tin_cans_available{};

    SpinLock tin_can_mutex;

    auto eat_cans = async(launch::async, [&] {
        for (size_t i{}; i < iterations; i++) {
            lock_guard<SpinLock> guard{tin_can_mutex};

            tin_cans_available--;

        }
    }); 

    auto deposit_cans = async(launch::async, [&] {
        for (size_t i{}; i < iterations; i++) {
            lock_guard<SpinLock> guard{tin_can_mutex};

            tin_cans_available++;

        }
    });

    eat_cans.get();

    deposit_cans.get();

    cout << "Tin cans: " << tin_cans_available << endl;
}

int main() {
    goat_rodeo();

    goat_rodeo();

    goat_rodeo();
} 
*/


/***************************************************************************************************************************************
19-3
reate a thread-safe queue class. 

This class must expose an interface like std::queue (see [queue.defn]). 

Use a std::queue internally to store elements. 

Use a std::mutex to synchronize access to this internal std::queue.
***************************************************************************************************************************************/

#include <queue>
#include <mutex>
#include <condition_variable>

 
template <typename T>
struct SafeQueue {
    queue<T> queue;

    mutable mutex mtx;

    condition_variable cond;

    void push(T value) {
        std::lock_guard<std::mutex> lock(mtx);

        queue.push(value);

        cond.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lock(mtx);

        cond.wait(lock, [this]{ return !queue.empty(); });

        T value = queue.front();

        queue.pop();

        return value;
    }

    T wait_and_pop(); // To be used in the next problem

    bool empty() const {
        std::lock_guard<std::mutex> lock(mtx);

        return queue.empty();
    }
};

void producer(SafeQueue<int>& queue) {
    for (int i{1}; i <= 1000; ++i) {
        queue.push(i);

        this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

/* 
void consumer(SafeQueue<int>& queue) {

    cout << "Consumer popped: ";

    for (int i{0}; i < 1000; ++i) {
        int value = queue.pop();

        if (value < 1000) cout << value << ", ";

        else cout << value;
    }

    cout << endl;

}
*/

/* 
int main() {
    SafeQueue<int> queue;

    thread producerThread(producer, ref(queue));

    thread consumerThread(consumer, ref(queue));

    producerThread.join(); // make the main porgram wait for the thread to complete execution

    consumerThread.join();
}
*/


/***************************************************************************************************************************************
19-4
Add a wait_and_pop method and a std::condition_variable member to your thread-safe queue. 

When a user invokes wait_and_pop and the queue contains an element, it should pop the element off the queue and return it. 

If the queue is empty, the thread should block until an element becomes available and then proceed to pop an element. 
***************************************************************************************************************************************/


template <typename T>
T SafeQueue<T>::wait_and_pop() {
    std::unique_lock<std::mutex> lock(mtx);

    cond.wait(lock, [this]{ return !queue.empty(); });

    T value = queue.front();

    queue.pop();

    return value;
}

void consumer(SafeQueue<int>& queue) {
    cout << "Consumer popped: "; 
    
    for (int i = 0; i < 1000; ++i) {
        int value = queue.wait_and_pop();

        if (value < 1000) cout << value << ", ";

        else cout << value;
    }

    cout << endl;
}

int main() {
    SafeQueue<int> queue;

    thread producerThread(producer, ref(queue));

    thread consumerThread(consumer, ref(queue));

    producerThread.join();

    consumerThread.join();
}