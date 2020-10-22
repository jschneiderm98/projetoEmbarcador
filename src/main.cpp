#include <iostream>
#include <unistd.h>
#include "headers/tempMeasure.h"
#include "headers/display.hpp"

int main() {
    float temp, size;
    while(1){
        temp = tempMeasure();
        size = webcamShot();
        std::cout << "Bread Area: " << size << "Temperature: " << temp << std::endl;
        sleep(1);
    return 0;
}
