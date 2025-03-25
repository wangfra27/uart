#include "ring_buffer.h"
#include <iostream>

RingBuffer::RingBuffer(int cap) : head(0), tail(0), size(0), capacity(cap) {
    buffer.resize(capacity);
}

RingBuffer::~RingBuffer() {}

void RingBuffer::push(int value) {
    if (isFull()) {
        std::cerr << "Buffer is full!\n";
        return;
    }
    buffer[tail] = value;
    tail = (tail + 1) % capacity;
    size++;
}

int RingBuffer::pop() {
    if (isEmpty()) {
        std::cerr << "Buffer is empty!\n";
        return -1;
    }
    int value = buffer[head];
    head = (head + 1) % capacity;
    size--;
    return value;
}

bool RingBuffer::isEmpty() const {
    return size == 0;
}

bool RingBuffer::isFull() const {
    return size == capacity;
}
