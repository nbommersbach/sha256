#include <iostream>
#include <bitset>

//names according to NIST

std::bitset<32> rotright(std::bitset<32> &input, const unsigned int rots);
std::bitset<32> rotleft(std::bitset<32> &input, const unsigned int rots);

std::bitset<32> ch(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z);
std::bitset<32> maj(std::bitset<32> x, std::bitset<32> y, std::bitset<32> z);
std::bitset<32> bsig0(std::bitset<32> x);
std::bitset<32> bsig1(std::bitset<32> x);
std::bitset<32> ssig0(std::bitset<32> x);
std::bitset<32> ssig1(std::bitset<32> x);
