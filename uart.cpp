#include "uart.h"
#include <iostream>

UART::UART(int baudRate) : baudRate(baudRate) {
    std::cout << "UART initialized at " << baudRate << " baud.\n";
}

UART::~UART() {
    std::cout << "UART connection closed.\n";
}

void UART::sendData(const std::string& data) {
    std::cout << "Sending data: " << data << std::endl;
}

std::string UART::receiveData() {
    std::string received = "Sample received data";
    std::cout << "Receiving data: " << received << std::endl;
    return received;
}
