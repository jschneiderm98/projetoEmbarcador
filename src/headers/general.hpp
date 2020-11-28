#include <iostream>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>

typedef struct dados {
    double sizeX, previousValues[10], previousVariations[10], valueMean[10];
    int growthStop=1, quantityMeasures=1, quantityMeans=1, quantityVars=1;
}dados;