#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <algorithm>
#include <string.h>

#define BLOCK_SIZE 4096
#define CODE_SUCCESS 0
#define CODE_ERROR -1
#define NOT_ENOUGH_SPACE 1
#define FILE_NOT_FOUND 2
#define FILE_ALREADY_EXISTS 3


/*
Each file - sequence of blocks
That struct contains block size(4096 bytes)
and data, which is just plain text of 4096 symbols.
Also contains bool is_empty, which indicates, whether block is free or not
*/
struct Block{
    const uint16_t SIZE = BLOCK_SIZE;
    char *data = new char[BLOCK_SIZE];
    bool is_empty = true;
    Block();    
    Block(const Block& ref_block);    
    Block& operator=(const Block& ref_block);
};

/*
File class. Contains only info about
files's first block index and amount of blocks.
Also there is file name
*/
class File{
public:
    std::string file_name;
    uint32_t start_block_index;
    uint16_t block_amount;
    File(std::string file_name, uint32_t start_block_index, uint16_t block_amount);
    File(const File& ref_file);
    bool operator ==(const File& ref_file);
};

/*
Disk class. Includes array of blocks and vector of files(cause they can be added)
*/
class Disk{
public:
    Block* blocks = nullptr;
    std::vector<File> files;
    Disk();
    Disk(uint32_t size);    
};

/*
File system itself. Creating, deleting, changing, copying and renaming files.
Files can't be moved - that file system is one-level.
Also you can lookup your files with their names, data and sizes.
flookup - only file names + sizes

get_block_index - returns index of block if there are free enough blocks for file or
smth else. Otherwise, -1.

Wanna create FileSystem? Use constructor in which declare how many bytes you want
to use in disk
*/
class FileSystem{
public:
    Disk* disk = nullptr;
    uint32_t disk_block_amount;
    FileSystem();
    FileSystem(uint32_t disk_size);    
    int fcreate(std::string file_name, uint32_t size, std::string data);
    int fdelete(std::string file_name);
    int fchange(std::string file_name, std::string new_data);
    int fcopy(std::string file_name);
    int fread(std::string file_name);
    int flookup();
private:
    int get_block_index(uint32_t size);
    bool check_file_for_existence(std::string file_name);
    File& find_file(std::string file_name);    
};