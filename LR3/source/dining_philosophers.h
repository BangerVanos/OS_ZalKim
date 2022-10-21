//
// Created by daniil on 19.10.22.
//

#ifndef OS_LAB_3_DINING_PHILOSOPHERS_H
#define OS_LAB_3_DINING_PHILOSOPHERS_H

#include <vector>
#include <string>
#include <stdlib.h>
#include "philosophers.h"

static std::vector<Philosopher> phils;

// add_phil adds a philosopher in vector 'phils'.
void add_phil(const std::string& name, int think_t, int eat_t);

// start_dinner starts threads of dining philosophers.
void start_dinner(size_t time_ms);
#endif //OS_LAB_3_DINING_PHILOSOPHERS_H
