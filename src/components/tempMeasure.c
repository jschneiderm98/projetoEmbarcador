#include <stdio.h>
#include <stdlib.h>

#define redundancy 2

void* tempMeasure(void* arg){
    float *temperatura = (float*) arg;
    system("sudo modprobe w1-gpio");
    system("sudo modprobe w1-therm");
    int i=0;
    //char holder[20];
    float temp, total = 0;
    FILE  *fp;
    while(i < redundancy)
    {
        /*system("cat /sys/bus/w1/devices/28-3c01a81664b5/w1_slave > temperature.txt");
        fp=fopen("temperature.txt","r");*/
        fp=fopen("/sys/bus/w1/devices/28-3c01a81664b5/w1_slave","r");
        if(fp == NULL) return NULL;
        fscanf(fp, "%*[^\n]\n");
        fscanf(fp,"%*29c%f", &temp);
        //temp = strtof(holder, NULL);
        temp /= 1000;
        total += temp;
        fclose(fp); 
        i++;
    }
    *temperatura = total/redundancy;
}

