#include "../headers/general.hpp"
#define redundancy 8
double calcVars(double means[])
{
    double var;
    for (int i = 0; i < redundancy - 1; i++)
    {
        var += means[i+1] - means[i];
    }
    return var;
}

double meanVars(double vars[])
{
    double meanVar;
    for (int i = 0; i < redundancy; i++)
    {
        meanVar += vars[i];
    }
    return meanVar / redundancy;
}

/*void printVector(double* vetor, char* name, int max)
{   
    if(max > redundancy + 1)
    {
        std::cout << name << ": ";
        for (int i = 0; i < redundancy; i++)
        {
            std::cout << vetor[i] << "  ";
        }
        std::cout << std::endl;
    }
    else{
        std::cout << name << ": ";
        for (int i = 0; i < max - 1; i++)
        {
            std::cout << vetor[i] << "  ";
        }
        std::cout << std::endl;
    }
    
}*/

void* sizeBread(void* arg) {
    dados *growth = (dados*) arg;
    double variation = 0, mean;
    //std::cout << "quantityMeasures" << growth->quantityMeasures << std::endl;
    if (growth->quantityMeasures<redundancy+1)
    {
        growth->previousValues[growth->quantityMeasures - 1] = growth->sizeX;
        growth->quantityMeasures++;
        //std::cout << "quantityMeasures" << growth->quantityMeasures << std::endl;
        //printVector(growth->previousValues, "previous values", growth->quantityMeasures);
    }
    else
    {
        growth->previousValues[growth->quantityMeasures - (redundancy+1)] = growth->sizeX;
        //printVector(growth->previousValues, "previous values", growth->quantityMeasures);
        if (growth->quantityMeasures < 2*redundancy) growth->quantityMeasures++;
        else {
            growth->quantityMeasures = (redundancy+1);
            for (int i = 0; i < redundancy; i++)
            {
                mean += growth->previousValues[i];
            }
            mean /= redundancy;
            if (growth->quantityMeans < (redundancy+1))
            {
                growth->valueMean[growth->quantityMeans - 1] = mean;
                growth->quantityMeans++;
                if (growth->quantityMeans == redundancy+1)
                {
                    variation = calcVars(growth->valueMean);
                    growth->previousVariations[growth->quantityVars - 1] = variation;
                    growth->quantityVars++;
                }
                //printVector(growth->valueMean, "valueMean", growth->quantityMeans);
            }
            else
            {
                growth->valueMean[growth->quantityMeans - (redundancy+1)] = mean;
                //printVector(growth->valueMean, "valueMean", growth->quantityMeans);
                if (growth->quantityMeans < 2*redundancy) growth->quantityMeans++;
                else 
                {
                    growth->quantityMeans = redundancy+1;
                    if (growth->quantityVars < redundancy+1)
                    {
                        variation = calcVars(growth->valueMean);
                        growth->previousVariations[growth->quantityVars - 1] = variation;
                        growth->quantityVars++;
                        if (growth->quantityVars == redundancy+1)
                        {
                            if (variation < meanVars(growth->previousVariations)) growth->growthStop = 0;
                            //std::cout << "if (" << variation << " < " << meanVars(growth->previousVariations) << ") growth->growthStop = 0;" << std::endl;
                        }
                        //printVector(growth->previousVariations, "previousVariation", growth->quantityVars);
                    }
                    else
                    {
                        variation = calcVars(growth->valueMean);
                        growth->previousVariations[growth->quantityVars - (redundancy+1)] = variation;
                        //printVector(growth->previousVariations, "previousVariation", growth->quantityVars);
                        if (growth->quantityVars < 2*redundancy)
                        {
                            growth->quantityVars++;
                        }
                        else
                        {
                            growth->quantityVars = redundancy+1;
                            if (variation < meanVars(growth->previousVariations)) growth->growthStop = 0;
                            //std::cout << "if (" << variation << " < " << meanVars(growth->previousVariations) << ") growth->growthStop = 0;" << std::endl; 
                        }
                    }
                }
            }
            mean = 0;
        }
    }
    return NULL;
}
