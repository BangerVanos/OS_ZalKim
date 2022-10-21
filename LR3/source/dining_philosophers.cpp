//
// Created by daniil on 19.10.22.
//
#include "dining_philosophers.h"
#include <thread>
#include <iostream>
#include <unistd.h>

void add_phil(const std::string& name, int think_t, int eat_t)
{
    //emplace_back is something like constructor.
    //In this method we create an attribute of the class
    //Philosopher with all the needed values
    std::cout << "Adding " << name << "\n";;
    phils.emplace_back(name, think_t, eat_t);
    //creating new sticks for the first philosopher
    if(phils.size() == 1)
    {
        phils[0].set_l_stick(new Stick);
        phils[0].set_r_stick(new Stick);

        return;
    }
    //we should have only 5 sticks
    if(phils.size() == 5)
    {
        phils[4].set_l_stick((phils[3]).get_r_stick());
        phils[4].set_r_stick(phils[0].get_l_stick());
        return;
    }

    std::vector<Philosopher>::iterator phil = phils.end();

    (phil - 1)->set_l_stick((phil - 2)->get_r_stick());
    (phil - 1)->set_r_stick(new Stick);

}

void start_phil(size_t i)
{
    while(true)
    {
        phils[i].think();
        phils[i].occupy_sticks();
        phils[i].eat();
        phils[i].release_sticks();
    }
}

void start_dinner(size_t time_ms)
{
    std::vector<std::thread> p_threads;
    for(size_t i = 0; i < phils.size(); i++)
    {
        p_threads.push_back(std::thread(start_phil, i));
    }

    std::thread timer(usleep, time_ms*1000);
    //join() waits until a thread completes
    timer.join();
    //detach() is mainly useful when you have a task that has to be done in background, but you don't care about its execution.
    // This is usually a case for some libraries. They may silently create a background worker
    // thread and detach it so you won't even notice it.
    for(std::thread & th : p_threads)
    {
        th.detach();
    }

    std::cout << "Dinner finished";
}