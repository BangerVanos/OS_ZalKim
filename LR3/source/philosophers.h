//
// Created by daniil on 19.10.22.
//

#ifndef OS_LAB_3_PHILOSOPHERS_H
#define OS_LAB_3_PHILOSOPHERS_H

#include <string>
#include <utility>
#include <stdlib.h>
#include "stick.h"

//There 5 attributes of the class 'Philosopher':
// name, think_t (time of thinking), eat_t (time of eating),
// l_stick, r_stick(both of the two previous  attributes -
// variables which would be shared with other philosophers )

class Philosopher{
private:
    std::string name;
    size_t think_t;
    size_t eat_t;
    Stick *l_stick{}, *r_stick{};
public:
    Philosopher(std::string name, size_t think_t,
                size_t eat_t):name(std::move(name)), think_t(think_t), eat_t(eat_t){}
    void set_l_stick(Stick* l_stick);
    void set_r_stick(Stick* r_stick);

    Stick* get_l_stick();
    Stick* get_r_stick();
    void think();
    void eat();
    std::string get_name();

    void occupy_sticks();
    void release_sticks();


};
#endif