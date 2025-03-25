#include <iostream>
#include "ring_buffer.h"
#include "uart.h"

int main() {
    RingBuffer rb(5);
    UART uart(9600);

    rb.push(10);
    rb.push(20);
    std::cout << "Popped: " << rb.pop() << std::endl;

    uart.sendData("Hello, UART!");
    std::cout << "Received: " << uart.receiveData() << std::endl;

    return 0;
}
