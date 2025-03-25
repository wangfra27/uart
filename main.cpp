#include <iostream>
#include "ring_buffer.h"

using namespace std;

void startBuffer(RingBuffer<char, 5>& buffer) {
    const char* data = "ABCDE";
    for (int i = 0; data[i] != '\0'; i++) {
        buffer.push(data[i]);
        cout << "Added: " << data[i] << endl;
    }
}

void addData(RingBuffer<char, 5>& buffer, char c) {
    buffer.push(c);
    cout << "Added: " << c << endl;
}

void removeData(RingBuffer<char, 5>& buffer) {
    char c;
    buffer.pop(c);
    cout << "Received: " << c << endl;
}

int main() {
    RingBuffer<char, 5> buffer;

    cout << "Start buffer" << endl;
    startBuffer(buffer);

    cout << "Process buffer" << endl;
    removeData(buffer);
    removeData(buffer);
    removeData(buffer);

    cout << "Overwrite buffer" << endl;
    buffer.push('F');
    buffer.push('G');
    
    cout << "Process buffer" << endl;
    removeData(buffer);
    removeData(buffer);

    buffer.push('H');
    buffer.push('I');
    
    cout << "Process buffer" << endl;
    removeData(buffer);
    removeData(buffer);

    buffer.push('J');

    cout << "Process buffer" << endl;
    removeData(buffer);
    removeData(buffer);

    return 0;
}

