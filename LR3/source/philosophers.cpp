//
// Created by daniil on 19.10.22.
//
#include "philosophers.h"
#include <iostream>
#include <ctime>
#include <mutex>
#include <unistd.h>

static std::mutex log_mtx;

void Philosopher::set_l_stick(Stick* l_stick)
{
    this->l_stick = l_stick;
}

void Philosopher::set_r_stick(Stick* r_stick)
{
    this->r_stick = r_stick;
}

Stick* Philosopher::get_l_stick()
{
    return l_stick;
}

Stick* Philosopher::get_r_stick()
{
    return r_stick;
}

void Philosopher::think()
{
    //we have to lock the definite memory are to write something into
    //the console
    log_mtx.lock();
    std::cout << name << " is thinking now\n";
    log_mtx.unlock();

    usleep(think_t*1000);
}

void Philosopher::eat()
{
    log_mtx.lock();
    std::cout << name << " is eating now\n";
    log_mtx.unlock();

    usleep(eat_t*1000);
}

std::string Philosopher::get_name()
{
    return name;
}

void Philosopher::occupy_sticks()
{
    log_mtx.lock();
    std::cout << name << " tries to take sticks.\n";
    log_mtx.unlock();

    std::clock_t start_t;
    start_t = std::clock()*1000;
    //each philosopher has to occupy two sticks in one period of time
    //otherwise he should wait for the next opportunity
    //to occupy sticks
    while(true)
    {
        if(l_stick->try_lock())
        {
            if(!r_stick->try_lock())
            {
                l_stick->unlock();
                continue;
            }

            log_mtx.lock();
            std::cout << name << " was hungry for " << (std::clock()*1000. - start_t)/CLOCKS_PER_SEC << "\n";
            log_mtx.unlock();

            return;
        }
    }

}

//unlocking the memory area by the philosopher(thread)
void Philosopher::release_sticks()
{
    log_mtx.lock();
    std::cout << name << " putting down his sticks.\n";
    log_mtx.unlock();

    l_stick->unlock();
    r_stick->unlock();
}
