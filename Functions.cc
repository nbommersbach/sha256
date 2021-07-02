#include <iostream>
#include <bitset>
#include <string>
#include <iomanip>

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

unsigned long ch(unsigned long xl, unsigned long yl, unsigned long zl)
{
    std::bitset<32> x(xl);
    std::bitset<32> y(yl);
    std::bitset<32> z(zl);

    return ((x & y) ^ ((~x) & z)).to_ulong();
}

unsigned long maj(unsigned long xl, unsigned long yl, unsigned long zl)
{
    std::bitset<32> x(xl);
    std::bitset<32> y(yl);
    std::bitset<32> z(zl);

    return ((x & y) ^ (x & z) ^ (y & z)).to_ulong();
}

unsigned long bsig0(unsigned long xl)
{
    std::bitset<32> x(xl);
    return (rotright(x, 2) ^ rotright(x, 13) ^ rotright(x, 22)).to_ulong();
}

unsigned long bsig1(unsigned long xl)
{
    std::bitset<32> x(xl);
    return (rotright(x, 6) ^ rotright(x, 11) ^ rotright(x, 25)).to_ulong();
}

unsigned long ssig0(unsigned long xl)
{
    std::bitset<32> x(xl);
    return (rotright(x, 7) ^ rotright(x, 18) ^ ((x) >> 3)).to_ulong();
}

unsigned long ssig1(unsigned long xl)
{
    std::bitset<32> x(xl);
    return (rotright(x, 17) ^ rotright(x, 19) ^ ((x) >> 10)).to_ulong();
}

std::string hex_return(unsigned long input)
{
    std::bitset<32> s(input);
    std::stringstream sstream;
    sstream << std::hex <<std::setw(8) <<std::setfill('0') << s.to_ulong();
    return sstream.str();    
}

std::string digest_block(std::vector<std::bitset<32>> &m)
{
    unsigned long h0 = 0x6a09e667;
    unsigned long h1 = 0xbb67ae85;
    unsigned long h2 = 0x3c6ef372;
    unsigned long h3 = 0xa54ff53a;
    unsigned long h4 = 0x510e527f;
    unsigned long h5 = 0x9b05688c;
    unsigned long h6 = 0x1f83d9ab;
    unsigned long h7 = 0x5be0cd19;

    uint32_t k[64] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

    std::vector<unsigned long> w(64, 0);
    unsigned long mod = static_cast<unsigned long>(std::pow(2, 32));

    for(unsigned int t = 0; t < 16; ++t)
    {
        w[t] = m[t].to_ulong();
    }

    for(unsigned int t = 16; t < 64; ++t)
    {
        unsigned long pre_w = ssig1(w[t-2]) + w[t-7] + ssig0(w[t-15]) + w[t-16];
        
        pre_w = pre_w % mod;
        w[t] = pre_w;
    }

    unsigned long a = h0;
    unsigned long b = h1;
    unsigned long c = h2;
    unsigned long d = h3;
    unsigned long e = h4;
    unsigned long f = h5;
    unsigned long g = h6;
    unsigned long h = h7;
    unsigned long t1;
    unsigned long t2;

    for(int t = 0; t < 64; ++t)
    {
        t1 = (h + bsig1(e) + ch(e, f, g) + k[t] + w[t]) % mod;
        t2 = (bsig0(a) + maj(a, b, c)) % mod;
        h = g;
        g = f;
        f = e;
        e = (d + t1) % mod;
        d = c;
        c = b;
        b = a;
        a = (t1 + t2) % mod;
    }

    h0 = h0 + a % mod;
    h1 = h1 + b % mod;
    h2 = h2 + c % mod;
    h3 = h3 + d % mod; 
    h4 = h4 + e % mod;
    h5 = h5 + f % mod;
    h6 = h6 + g % mod;
    h7 = h7 + h % mod;    

    std::cout << hex_return(h0) << std::endl;
    std::cout << hex_return(h1) << std::endl;
    std::cout << hex_return(h2) << std::endl;
    std::cout << hex_return(h3) << std::endl;
    std::cout << hex_return(h4) << std::endl;
    std::cout << hex_return(h5) << std::endl;
    std::cout << hex_return(h6) << std::endl;
    std::cout << hex_return(h7) << std::endl;


    return hex_return(h0) + hex_return(h1) + hex_return(h2) + hex_return(h3) +
           hex_return(h4) + hex_return(h5) + hex_return(h6) + hex_return(h7);
}