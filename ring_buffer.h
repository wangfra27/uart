#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <vector>

class RingBuffer {
private:
    std::vector<int> buffer;
    int head, tail, size, capacity;

public:
    RingBuffer(int cap);
    ~RingBuffer();

    void push(int value);
    int pop();
    bool isEmpty() const;
    bool isFull() const;
};

#endif
