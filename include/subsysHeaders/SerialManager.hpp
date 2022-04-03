#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <string>
class SerialManager {
    public:
    char buffer[50];

    SerialManager();
    void update();
    void readBuffer();
    void processDataFromBuffer();
    void sendData(std::string data);
};


#endif