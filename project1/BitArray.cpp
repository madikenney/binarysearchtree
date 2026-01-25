#include "BitArray.hpp"

BitArray::BitArray() {
    // TODO
    current_size = 8;
    arr = new int[current_size];

    for(int i=0; i<current_size; i++){
        arr[i] = 0;
    }
    
    valid = true;
}

BitArray::BitArray(intmax_t init_size) {
    // TODO
    if (init_size <= 0){
        valid = false;
        return;
    }
    
    current_size = init_size;
    arr = new int[current_size];

    for(int i=0; i<current_size; i++){
        arr[i] = 0;
    }
    
    valid = true;
}

BitArray::BitArray(const std::string & value) {
    // TODO
    if(value.length()<=0){
        valid = false;
        return;
    }

    current_size = value.length();
    arr = new int[current_size];

    for(int i=0; i<current_size; i++){
        if(i != 0 && i != 1){
            valid = false;
            return;
        }
        arr[i] = stoi(value.substr(i,1));
    }
    
    valid = true;
}

BitArray::~BitArray() {
    // TODO
    delete arr;
}

// TODO: other methods

intmax_t BitArray::size() const
{
    return current_size;
}

bool BitArray::good() const
{
    return valid;
}

void BitArray::set(intmax_t index)
{
    if(index<0 || index>current_size){
        valid = false;
        return;
    }
    arr[current_size-index-1] = 1;
}

void BitArray::reset(intmax_t index)
{
    if(index<0 || index>current_size){
        valid = false;
        return;
    }
    arr[current_size-index-1] = 0;
}

void BitArray::toggle(intmax_t index)
{
}

bool BitArray::test(intmax_t index)
{
    return false;
}

std::string BitArray::asString() const
{
    std::string result = "";
    for(int i=0; i<current_size; i++){
        result = result + std::to_string(arr[i]);
    }
    return result;
}
