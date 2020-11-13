#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include "headers/tempMeasure.hpp"
#include "headers/display.hpp"

int control = 1;

void endProgram (int sig)
{
    control = 0;
}

int main() {
    
    float temp;
    double size;
    pthread_t p_temp, p_size;
    signal (SIGINT, endProgram); 
    while(control){
        pthread_create(&p_temp, NULL, &tempMeasure, &temp);
        pthread_create(&p_size, NULL, &webcamShot, &size);
        pthread_join(p_temp, NULL);
        pthread_join(p_size, NULL);
        system("clear");
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "|     Bread Area: " << size << "         |" << std::endl;
        std::cout << "|     Temperature: " << temp << "        |" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
        usleep(500000);
    }
    return 0;
}
