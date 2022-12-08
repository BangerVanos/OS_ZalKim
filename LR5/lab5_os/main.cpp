#include "fs.h"
#include <iostream>


class Tester {
private:
    static uint16_t test_number;
public:
    static bool test_function(int result, int pass_result) {        
        return result == pass_result;
    }
    static void print_test(bool test_result) {
        test_number++;
        std::string test_word = test_result ? "Passed" : "Failed";
        std::cout << "Test " << test_number << "........." << test_word << "\n";
    }
};

uint16_t Tester::test_number = 0;

int main(){
    FileSystem file_system(16384);
    Tester::print_test(Tester::test_function(file_system.fcreate("test1", 4096, "Hello, world!"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fcreate("test2", 4096, "Ogryzok i oguzok"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fcreate("test2", 4096, "Ogryzok i oguzok"), FILE_ALREADY_EXISTS));
    Tester::print_test(Tester::test_function(file_system.fcreate("test3", 4096, "Sample text"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fcreate("test4", 4096, "Bla-bla"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.flookup(), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fread("test1"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fread("test2"), CODE_SUCCESS));    
    Tester::print_test(Tester::test_function(file_system.fcreate("test5", 4096, "Test file no 5"), NOT_ENOUGH_SPACE));
    Tester::print_test(Tester::test_function(file_system.fread("test5"), FILE_NOT_FOUND));
    Tester::print_test(Tester::test_function(file_system.fdelete("test2"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fdelete("test4"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fread("test2"), FILE_NOT_FOUND));
    Tester::print_test(Tester::test_function(file_system.fread("test4"), FILE_NOT_FOUND));
    Tester::print_test(Tester::test_function(file_system.fcreate("test6", 8192, "Bla-bla that is file test6"), NOT_ENOUGH_SPACE));
    Tester::print_test(Tester::test_function(file_system.fcreate("test7", 4096, "Bla-bla that is file test7"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.flookup(), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fread("test7"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fcopy("test7"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.flookup(), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fread("test7 - copy"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fcopy("test7"), NOT_ENOUGH_SPACE));
    Tester::print_test(Tester::test_function(file_system.fchange("test7", "New text for file test7"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.fread("test7"), CODE_SUCCESS));
    Tester::print_test(Tester::test_function(file_system.flookup(), CODE_SUCCESS));
    return 0;
}