#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include "headers/tempMeasure.hpp"
#include "headers/display.hpp"


int main() {
    float temp;
    double size;
    pthread_t p_temp, p_size;
    pthread_create(&p_temp, NULL, &tempMeasure, &temp);
    pthread_create(&p_size, NULL, &webcamShot, &size);
    pthread_join(p_temp, NULL);
    pthread_join(p_size, NULL);
    std::cout << "Bread Area: " << size << " Temperature: " << temp << std::endl;
   
    return 0;
}
