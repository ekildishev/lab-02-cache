// Copyright 2018 Your Name <your_email>
#pragma once

#include <ctime>
class experiment
{
    /*enum direction
    {
        forward,
        backward,
        random
    };*/
public:
    static clock_t forwardExperiment(unsigned int cashSize);
    static clock_t backwardExperiment(unsigned int cashSize);
    static clock_t randomExperiment(unsigned int cashSize);
};

