#include <experiment.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

int main()
{
    std::vector<unsigned int> buffer;
    unsigned int cashSizeMin = 256, cashSizeMax = 6144;
    unsigned int power = 0;
    while(pow(2, power) <= cashSizeMin)
    {
        ++power;
    }
    while(pow(2, power) < cashSizeMax * 1.5)
    {
        buffer.push_back(pow(2, power));
        ++power;
    }
    std::vector<clock_t> forward;
    std::vector<clock_t> backward;
    std::vector<clock_t> random;
    for(unsigned int i = 0; i < buffer.size(); ++i)
    {
        forward.push_back(experiment::forwardExperiment(buffer[i]));
        backward.push_back(experiment::backwardExperiment(buffer[i]));
        random.push_back(experiment::randomExperiment(buffer[i]));
    }
    for(unsigned int i = 0; i < buffer.size(); ++i)
    {
        std::cout << forward[i] << std::endl;
    }
    std::cout << std::endl << std::endl;
    for(unsigned int i = 0; i < buffer.size(); ++i)
    {
        std::cout << backward[i] << std::endl;
    }
    std::cout << std::endl << std::endl;
    for(unsigned int i = 0; i < buffer.size(); ++i)
    {
        std::cout << random[i] << std::endl;
    }
    std::cout << std::endl << std::endl;
}
