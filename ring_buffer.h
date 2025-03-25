#include <iostream>
#include <array>
#include <atomic>

template <typename T, size_t Size>
class RingBuffer {
public:
    RingBuffer() : head(0), tail(0), count(0) {}

    void push(T value) {
        if (count == Size) {
            tail = (tail + 1) % Size;
        } else {
            count++;
        }
        buffer[head] = value;
        head = (head + 1) % Size;
    }

    bool pop(T& value) {
        if (count == 0) {
            return false;
        }
        value = buffer[tail];
        tail = (tail + 1) % Size;
        count--;
        return true;
    }

    bool isEmpty() const {
        return count == 0;
    }
    
    bool isFull() const {
        return count == Size;
    }

private:
    std::array<T, Size> buffer;
    size_t head, tail;
    std::atomic<size_t> count;
};
