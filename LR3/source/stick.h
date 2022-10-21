//
// Created by daniil on 19.10.22.
//

#ifndef OS_LAB_3_STICK_H
#define OS_LAB_3_STICK_H
#include <mutex>

class Stick{
public:
    void unlock();
    bool try_lock();
private:

    //we have only the object of the class 'mutex'
    std::mutex m;
};

#endif //OS_LAB_3_STICK_H
