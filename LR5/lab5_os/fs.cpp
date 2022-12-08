#include "fs.h"

Block::Block(const Block& ref_block){
    data = ref_block.data;
    is_empty = ref_block.is_empty;    
}

Block::Block(){

}

Block::~Block(){
    delete data;    
}

Block Block::operator=(const Block& ref_block){
    Block new_block = ref_block;
    return new_block;
}

File::File(std::string file_name, uint32_t start_block_index, uint16_t block_amount){
    this->file_name = file_name;
    this->start_block_index = start_block_index;
    this->block_amount = block_amount;
}

bool File::operator==(const File& ref_file){
    return this->file_name == ref_file.file_name;
}

Disk::Disk(){

}

Disk::Disk(uint32_t size){
    blocks = new Block[size/BLOCK_SIZE];
}

Disk::~Disk(){
    delete blocks;
}

FileSystem::FileSystem(){

}

FileSystem::FileSystem(uint32_t disk_size){
    disk = new Disk(disk_size);
}

FileSystem::~FileSystem(){
    delete disk;
}


int FileSystem::get_block_index(uint32_t size){
    uint16_t block_amount = size/BLOCK_SIZE > int(size/BLOCK_SIZE) ? int(size/BLOCK_SIZE) + 1 : int(size/BLOCK_SIZE);
    int return_index = -1;
    int block_in_row = 0;
    for(int i = 0; i < sizeof(disk->blocks)/sizeof(disk->blocks[0]); i++){
        if(block_in_row >= block_amount) return return_index;        
        if(disk->blocks[i].is_empty){
            if(!block_in_row){
                return_index = i;                
            }
            block_in_row++;
        }
        else{
            return_index = -1;
            block_in_row = 0;
        }
    }
}

File& FileSystem::find_file(std::string file_name){
    for(auto file : disk->files){
        if(file.file_name == file_name){
            return file;
        }
    }    
}

bool FileSystem::check_file_for_existence(std::string file_name){
    for(auto file : disk->files){
        if(file.file_name == file_name){
            return true;
        }
    }
    return false;
}

int FileSystem::fcreate(std::string file_name, uint32_t size, std::string data){
    if(FileSystem::check_file_for_existence(file_name)){
        return FILE_ALREADY_EXISTS;
    }
    else if(!get_block_index(size)){
        return NOT_ENOUGH_SPACE;
    }
    int block_index = get_block_index(size);
    uint16_t block_amount = size/BLOCK_SIZE > int(size/BLOCK_SIZE) ? int(size/BLOCK_SIZE) + 1 : int(size/BLOCK_SIZE);    
    File new_file(file_name, block_index, block_amount);
    disk->files.push_back(new_file);
    std::string::iterator str_it = data.begin();
    for(int i = block_index; i < block_index + block_amount; i++){
        disk->blocks[i].is_empty = false;
        for(int j = 0; j < disk->blocks[i].SIZE; j++){
            if(str_it != data.end()){
                disk->blocks[i].data[j] = *str_it;
                str_it++;
            }
            else{
                disk->blocks[i].data[j] = '\0';
                continue;
            }
        }
    }
    return CODE_SUCCESS;
}


int FileSystem::fdelete(std::string file_name){
    if(!FileSystem::check_file_for_existence(file_name)){
        return FILE_NOT_FOUND;
    }
    File& del_file = find_file(file_name);
    for(int i = del_file.start_block_index; i < del_file.start_block_index + del_file.block_amount; i++){
        disk->blocks[i].is_empty = true;
        disk->blocks[i].data[0] = '\0';
    }
    disk->files.erase(std::remove(disk->files.begin(), disk->files.end(), del_file), disk->files.end());
    return CODE_SUCCESS;
}


int FileSystem::fchange(std::string file_name, std::string new_data){
    if(!FileSystem::check_file_for_existence(file_name)){
        return FILE_NOT_FOUND;
    }
    File& change_file = find_file(file_name);
    std::string::iterator str_it = new_data.begin();
    for(int i = change_file.start_block_index; i < change_file.start_block_index + change_file.block_amount; i++){
        for(int j = 0; j < disk->blocks[i].SIZE; j++){
            if(str_it != new_data.end()){
                disk->blocks[i].data[j] = *str_it;
                str_it++;
            }
            else{
                disk->blocks[i].data[j] = '\0';
                continue;
            }
        }
    }
    return CODE_SUCCESS;
}


int FileSystem::fcopy(std::string file_name){
    if(!FileSystem::check_file_for_existence(file_name)){
        return FILE_NOT_FOUND;
    }
    File& copy_file = find_file(file_name);
    if(!get_block_index(copy_file.block_amount*BLOCK_SIZE)){
        return NOT_ENOUGH_SPACE;
    }
    std::string new_name = file_name + " - copy";
    int start_block_index = get_block_index(copy_file.block_amount*BLOCK_SIZE);
    File new_file(new_name, start_block_index, copy_file.block_amount);
    for(int i = copy_file.start_block_index, j = start_block_index; i < copy_file.start_block_index + copy_file.block_amount; i++, j++){
        disk->blocks[j] = disk->blocks[i];
    }
    return CODE_SUCCESS;
}


int FileSystem::fread(std::string file_name){
    if(!FileSystem::check_file_for_existence(file_name)){
        return FILE_NOT_FOUND;
    }
    File& read_file = find_file(file_name);
    for(int i = read_file.start_block_index; read_file.start_block_index + read_file.block_amount; i++){
        std::cout << disk->blocks[i].data;
    }
    std::cout << std::endl;
    return CODE_SUCCESS;
}

int FileSystem::flookup(){
    for(auto file : disk->files){
        std::cout << file.file_name << " Size: " << file.block_amount*BLOCK_SIZE << " b";
    }
    return CODE_SUCCESS;
}
