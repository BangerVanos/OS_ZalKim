#include <iostream>
#include "source/dining_philosophers.h"

int main(int argc, char** argv)
{
    std::cout << "Adding philosophers...\n";
    //adding 5 philosophers
    add_phil("Plato", 1, 3);
    add_phil("Kant", 2, 2);
    add_phil("Nietzsche", 3, 1);
    add_phil("p1", 1, 3);
    add_phil("p2", 2, 3);
    std::cout << "Philosophers added. Starting dinner...\n";
    //30 - a period of time for dinner
    start_dinner(30);
    return 0;
}