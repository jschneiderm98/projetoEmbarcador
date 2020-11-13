#include "../headers/general.hpp"

void* sizeBread(void* arg) {
    struct dados *growth = (struct dados*) arg;
    float variation = 0;
    if (growth->quantityMeasures<10){
        growth->previousValues[growth->quantityMeasures - 1] = growth->sizeX;
        growth->quantityMeasures++;
    }
    else{
        if (growth->quantityMeasures < 20) growth->quantityMeasures++;
        else growth->quantityMeasures = 11;
        
        for (int i = 0; i < 9; i++)
        {
            variation = growth->previousValues[i+1] - growth->previousValues[i];
        }
        
        if (variation < growth->previousVariation) growth->growthStop = 0;
        else growth->previousVariation = variation;
    }
}