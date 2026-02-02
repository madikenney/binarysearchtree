#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <string>

class Bitset{
  public:

    virtual ~Bitset(){};
    
    /** 
     * @return current size of array
    */
    virtual intmax_t size() const = 0;
    
    /**
     * @return validity of array
     */
    virtual bool good() const = 0;
    
    /** Sets a given bit to 1
     * @param index of bit to set
     */
    virtual void set(intmax_t index) = 0;
    
    /** Sets a given bit to 0
     * @param index of bit to reset
     */
    virtual void reset(intmax_t index) = 0;
    
    /** Sets a given bit to the opposite of its value
     * @param index of bit to toggle
     */
    virtual void toggle(intmax_t index) = 0;

    /** Checks if a bit is 1
     * @param index of bit to test
     * @return if the bit is equal to 1
     */
    virtual bool test(intmax_t index) = 0;

    /**
     * @return array as a string
     */
    virtual std::string asString() const = 0;

};

#endif
