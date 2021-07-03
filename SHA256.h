#include <iostream>
#include <cmath>
#include <bitset>
#include <vector>
#include <sstream>
#include <iomanip>

//names according to NIST

using byte = std::bitset<8>;

/**
 * @brief Converts a string into a vector of type byte using ascii code.
 * 
 * @param str Input message that is to be converted to bites.
 * @return Vector of output bites.
 */
std::vector<byte> to_ascii(std::string str);

/**
 * @brief Pads the messsage according to NIST specification.
 * 
 * @param input_binary Input vector of type bites that holds ascii coded message.
 * @return Returns padded message as binary string
 */
std::string padding_512bits(std::vector<byte> &input_binary);


/**
 * @brief Performs bitrotation to the right on bitset.
 * 
 * @param input Bitset that is to be rotated.
 * @param rots Number of rotation steps.
 * @return Rotated bitset.
 */
std::bitset<32> rotright(std::bitset<32> &input, const unsigned int rots);

/**
 * @brief CH-Function according to NIST specification.
 * 
 * @param xl input word x
 * @param yl input word y
 * @param zl input word z
 * @return result word
 */
unsigned long ch(unsigned long xl, unsigned long yl, unsigned long zl);

/**
 * @brief MAJ-Function according to NIST specification.
 * 
 * @param xl input word x
 * @param yl input word y
 * @param zl input word z
 * @return result word
 */
unsigned long maj(unsigned long xl, unsigned long yl, unsigned long zl);

/**
 * @brief BSIG0-Function according to NIST specification.
 * 
 * @param xl input word x
 * @param yl input word y
 * @param zl input word z
 * @return result word
 */
unsigned long bsig0(unsigned long xl);

/**
 * @brief BSIG1-Function according to NIST specification.
 * 
 * @param xl input word x
 * @param yl input word y
 * @param zl input word z
 * @return result word
 */
unsigned long bsig1(unsigned long xl);

/**
 * @brief SSIG0-Function according to NIST specification.
 * 
 * @param xl input word x
 * @param yl input word y
 * @param zl input word z
 * @return result word
 */
unsigned long ssig0(unsigned long xl);

/**
 * @brief SSIG1-Function according to NIST specification.
 * 
 * @param xl input word x
 * @param yl input word y
 * @param zl input word z
 * @return result word
 */
unsigned long ssig1(unsigned long xl);

/**
 * @brief Converts input number to hexadecimal string 
 * 
 * @param input input number
 * @return hexadecimal string
 */
std::string hex_return(unsigned long input);

/**
 * @brief SHA256 function according to NIST specification
 * 
 * @param message string input message that is to be converted into hash
 * @return hash string3
 */
std::string sha256(std::string &message);

template <typename T>
void print_vec(std::vector<T> vec)
{
    for(const auto &val : vec)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
}