#ifndef UART_H
#define UART_H

#include <string>

class UART {
public:
    UART(int baudRate);
    ~UART();

    void sendData(const std::string& data);
    std::string receiveData();
    
private:
    int baudRate;
};

#endif
