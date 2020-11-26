#include "../headers/general.hpp"

double calcVars(double means[])
{
    double var;
    for (int i = 0; i < 9; i++)
    {
        var += means[i+1] - means[i];
    }
    return var;
}

double meanVars(double vars[])
{
    double meanVar;
    for (int i = 0; i < 10; i++)
    {
        meanVar += vars[i];
    }
    return meanVar / 10;
}

void* sizeBread(void* arg) {
    dados *growth = (dados*) arg;
    double variation = 0, mean;
    if (growth->quantityMeasures<11)
    {
        growth->previousValues[growth->quantityMeasures - 1] = growth->sizeX;
        growth->quantityMeasures++;
    }
    else
    {
        growth->previousValues[growth->quantityMeasures - 11] = growth->sizeX;
        if (growth->quantityMeasures < 20) growth->quantityMeasures++;
        else {
            growth->quantityMeasures = 11;
            for (int i = 0; i < 10; i++)
            {
                mean += growth->previousValues[i];
            }
            mean /= 10;
            if (growth->quantityMeans < 11)
            {
                growth->valueMean[growth->quantityMeans - 1] = mean;
                growth->quantityMeans++;
            }
            else
            {
                growth->valueMean[growth->quantityMeans - 11] = mean;
                if (growth->quantityMeans < 20) growth->quantityMeans++;
                else 
                {
                    growth->quantityMeans = 11;
                    if (growth->quantityVars < 11)
                    {
                        variation = calcVars(growth->valueMean);
                        growth->previousVariations[growth->quantityVars - 1] = variation;
                        growth->quantityVars++;
                    }
                    else
                    {
                        variation = calcVars(growth->valueMean);
                        growth->previousVariations[growth->quantityVars - 11] = variation;
                        if (growth->quantityVars < 20)
                        {
                            growth->quantityVars++;
                        }
                        else
                        {
                            growth->quantityVars = 11;
                            if (variation < meanVars(growth->previousVariations)) growth->growthStop = 0;
                        }
                    }
                }
            }
            mean = 0;
        }
    }
    return NULL;
}