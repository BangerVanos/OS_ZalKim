#include "fs.h"
#include <iostream>


int main(){
    FileSystem file_system(2097152);
    file_system.fcreate("test", 40960, "Hello, worl!");
    file_system.flookup();
    file_system.fread("test");
    return 0;
}