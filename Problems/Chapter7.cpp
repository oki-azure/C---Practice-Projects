/******************************************************************************************  
7-1. Create an UnsignedBigInteger class that can handle numbers bigger than a long. 

You can use a byte array as the internal representation (for example, uint8_t[] or char[]). 

Implement operator overloads for operator+ and operator-. 

Perform runtime checks for overflow. 

For the intrepid, also implement operator*, operator/, and operator%. 

Make sure that your operator overloads work for both int types and UnsignedBigInteger types. 

Implement an operator int type conversion. 

Perform a runtime check if narrowing would occur.
******************************************************************************************/

#include <cstdio>
#include <cstdint>
#include <string>
#include <stdexcept>
#include <cstddef>
#include <new>
#include <limits>

/* 
struct UnsignedBigInteger {
    UnsignedBigInteger(long long value) : value{value} {}

    const long long value; 

    UnsignedBigInteger operator+(long long other) const {
        UnsignedBigInteger result{value + other}; 
        if (result.value < value) throw std::runtime_error{"Overflow!"}; 
        return result; 
    }

    UnsignedBigInteger operator-(long long other) const {
        UnsignedBigInteger result{value - other}; 
        if (result.value < value) throw std::runtime_error{"Overflow!"}; 
        return result; 
    }

    UnsignedBigInteger operator*(long long other) const {
        UnsignedBigInteger result{value * other}; 
        if (result.value < value) throw std::runtime_error{"Overflow!"}; 
        return result; 
    }

    UnsignedBigInteger operator/(long long other) const {
        UnsignedBigInteger result{value / other}; 
        if (result.value < value) throw std::runtime_error{"Overflow!"};         
        return result; 
    }

    UnsignedBigInteger operator%(long long other) const {
        UnsignedBigInteger result{value % other}; 
        if (result.value < value) throw std::runtime_error{"Overflow!"};         
        return result; 
    }
};

int main() {
    UnsignedBigInteger a{1000}; 
    auto b = a + 500; 
    printf("a = %lld\n", a); 
    printf("a + 500 = %lld\n", b.value); 
    try { auto c = a + std::numeric_limits<long long>::max(); }
    catch (const std::runtime_error& e) { printf("(a + max) Exception: %s\n", e.what()); }
    printf("\n\n"); 

    UnsignedBigInteger d{100};
    auto e = d * 100;
    printf("d = %lld\n", d); 
    printf("d * 100 = %lld\n", e.value);  
    try { auto f = d * std::numeric_limits<long long>::max(); }
    catch (const std::runtime_error& excpt) { printf("(d * max) Exception: %s\n", excpt.what()); }
}
*/




/*********************************************************************************  
7-2
Create a LargeBucket class that can store up to 1MB of data. 

Extend the Heap class so it gives out a LargeBucket for allocations greater than 4096 bytes. 

Make sure that you still throw std::bad_alloc whenever the Heap is unable to allocate 
an appropriately sized bucket.
*********************************************************************************/

 
struct Bucket {
    const static size_t data_size{4096}; 
    std::byte data[data_size]; 
};

struct LargeBucket {
    const static size_t data_size{1'000'000}; 
    std::byte data[data_size]; 
};

struct Heap {
    void* allocate(size_t bytes) {
        if (bytes > LargeBucket::data_size) throw std::bad_alloc{}; 
        
        else if (bytes > Bucket::data_size) {
            for (size_t i{}; i < n_heap_buckets; i++) {
                if (!large_bucket_used[i]) {
                    large_bucket_used[i] = true; 
                    printf("Allocated largeBucket to heap\n"); 
                    return buckets[i].data; 
                }
            } 
        }

        else if (bytes <= Bucket::data_size) {
            for (size_t i{}; i < n_heap_buckets; i++) {
                if (!bucket_used[i]) {
                    bucket_used[i] = true; 
                    printf("Allocated a bucket to heap\n"); 
                    return buckets[i].data; 
                }
            }
        }
        return buckets;
    }

    void free(void* p) {
        for (size_t i{}; i < n_heap_buckets; i++) {
            if (buckets[i].data == p) {
                bucket_used[i] = false; 
                return; 
            }

            else if (largeBuckets[i].data == p) {
                large_bucket_used[i] = false; 
                return; 
            }
        }
    }

    static const size_t n_heap_buckets{10}; 
    Bucket buckets[n_heap_buckets]; 
    bool bucket_used[n_heap_buckets]; 
    LargeBucket largeBuckets[n_heap_buckets]; 
    bool large_bucket_used[n_heap_buckets]; 
};

Heap heap; 

void* operator new(size_t n_bytes) { return heap.allocate(n_bytes); }
void operator delete(void* p) { return heap.free(p); }

int main() {
    printf("Bucket address starts here: 0x%x\n", heap.buckets); 
    printf("LargeBucket address starts here: 0x%x\n", heap.largeBuckets); 

    try {     
        while (true) {
            new Bucket; 
            new LargeBucket; 
        }
    }
    catch (const std::bad_alloc) { printf("std::bad_alloc caught!\n"); }
}
