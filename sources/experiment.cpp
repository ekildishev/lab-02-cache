#include <cstdlib>
#include "experiment.hpp"
#include <random>
#include <vector>
#include <algorithm>

clock_t experiment::forwardExperiment(unsigned int cashSize)
{
    clock_t start, finish;
    int *a = new int[cashSize * 256];
    for(unsigned int i = 0; i < cashSize * 256; ++i)
    {
        a[i] = rand();
    }
    int newA=0;
    start = clock();
    for(unsigned int i = 0; i < 1000; ++i)
    {
       for(unsigned int j = 0; j < cashSize * 256; ++j)
       {
           newA = a[j];
       }
    }
    finish = clock();
    a[0]=newA;
    delete[]a;
    return finish - start;
}

clock_t experiment::backwardExperiment(unsigned int cashSize)
{
    clock_t start, finish;
    int *a = new int[cashSize * 256];
    for(unsigned int i = 0; i < cashSize * 256; ++i)
    {
        a[i] = rand();
    }
    int newA = 0;
    start = clock();
    for(unsigned int i = 0; i < 1000; ++i)
    {
        for(unsigned int j = cashSize * 256; j >= 1; --j)
        {
            newA = a[j-1];
        }
    }
    finish = clock();
    a[0]=newA;
    delete []a;
    return finish - start;
}

clock_t experiment::randomExperiment(unsigned int cashSize)
{
    clock_t start, finish;
    int *a = new int[cashSize * 256];
    std::vector<unsigned int> index;
    for(unsigned int i = 0; i < cashSize * 256; ++i)
    {
        index.push_back(i);
    }
    std::shuffle(index.begin(), index.end(), std::mt19937(std::random_device()()));
    for(unsigned int i = 0; i < cashSize * 256; ++i)
    {
        a[i] = rand();
    }
    int newA = 0;
    start = clock();
    for(unsigned int i = 0; i < 1000; ++i)
    {
        for(unsigned int j = 0; j < cashSize * 256; ++j)
        {
            newA = a[index[j]];
        }
    }
    finish = clock();
    a[0]=newA;
    delete []a;
    return finish - start;
}
