#include "./subsysHeaders/SerialManager.hpp"
#include "./subsysHeaders/globals.hpp"
#include "pros/apix.h" //added this in
#include <vector>

SerialManager::SerialManager() {
    pros::c::serctl(SERCTL_DISABLE_COBS, nullptr);
}

void SerialManager::update() { 
	readBuffer();
}

void SerialManager::readBuffer() {
    std::cin >> this->buffer;
    	if (this->buffer[0] != '\0' ) {
            processDataFromBuffer();
    	}
}

void SerialManager::processDataFromBuffer() {
    std::vector<std::string> args;
    std::string currentArg = "";
    for(int i = 0; this->buffer[i] != '\0'; i++) {
        if (this->buffer[i] == ',') {
            args.push_back(currentArg);
            currentArg = "";
        }
        else currentArg+=this->buffer[i]; 
    }
    args.push_back(currentArg); // ZYU FORGUT ZE VUN IN ZE CHAMBER
    switch(stoi(args[0])) {
        case 1: //UPDATE OBJ POS: std::string identifier,int type, float x, float y
            ObjHandler.updateObjPos(args[1],stoi(args[2]), stof(args[3]), stof(args[4]));
        default:
            break;
    }

}

void sendData(std::string data) {
    std::cout<<data<<std::endl;
}