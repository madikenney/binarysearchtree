#include "BitArray.hpp"

BitArray::BitArray() {
    // TODO
    BitArray(8);
}

BitArray::BitArray(intmax_t init_size) {
    // TODO
    size = init_size;
    arr = new int[size];

    for(int i=0; i<size; i++){
        arr[i] = 0;
    }
    
    valid = true;
}

BitArray::BitArray(const std::string & value) {
    // TODO
}

BitArray::~BitArray() {
    // TODO
}

// TODO: other methods
