#include <iostream>
#include <bitset>
#include <string>

#include "Functions.h"

//names according to NIST

std::bitset<32> rotright(std::bitset<32> &input, const unsigned int rots)
{
    std::bitset<32> result;
    
    for(int i = 0; i < 32; ++i)
    {
        result[i] = input[(i + rots) % 32];
    }
    return result;
}

std::bitset<32> rotleft(std::bitset<32> &input, const unsigned int rots)
{
    std::bitset<32> result;
    
    for(int i = 0; i < 32; ++i)
    {
        result[i] = input[(i - rots) % 32];
    }
    return result;
}

std::bitset<32> ch(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z)
{
    return (x & y) ^ ((~x) & z);
}

std::bitset<32> maj(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z)
{
    return (x & y) ^ (x & z) ^ (y & z);
}

std::bitset<32> bsig0(std::bitset<32> x)
{
    return rotright(x, 2) ^ rotright(x, 13) ^ rotright(x, 22);
}

std::bitset<32> bsig1(std::bitset<32> x)
{
    return rotright(x, 6) ^ rotright(x, 11) ^ rotright(x, 25);
}

std::bitset<32> ssig0(std::bitset<32> x)
{
    return rotright(x, 7) ^ rotright(x, 18) ^ ((x) >> 3);
}

std::bitset<32> ssig1(std::bitset<32> x)
{
    return rotright(x, 17) ^ rotright(x, 19) ^ ((x) >> 10);
}