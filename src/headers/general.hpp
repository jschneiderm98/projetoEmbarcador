#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

struct dados {
    float sizeX, previousValues[10], previousVariation;
    int growthStop=1, quantityMeasures=0;
};