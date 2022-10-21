#include "stick.h"
//There only two methods:
//1. unlock - unlocking the memory area by the thread
//2. try_lock - trying to occupy the memory area
void Stick::unlock() {
    m.unlock();
}

bool Stick::try_lock() {
    return m.try_lock();
}