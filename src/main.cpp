#include <iostream>
#include <array>
#include <fstream>
#include "../include/bytesbits.h"

int main()
{
    const char *filepath = "../docs/NS.txt";
    PRINT_TYPE_INFO(int, std::cout);

    std::ofstream ofs(filepath);
    if (!ofs)
        return -1;

    int val = 314;
    IMD::LITTLE_ENDIAN::modify_bit(val, 1, 1);

    ofs << "Source value: " << val << std::endl;
    ofs << "Sign: " << IMD::sign(val) << std::endl;

    ofs << "Bits: ";
    IMD::BIG_ENDIAN::println_bits(val, " ", ofs);

    ofs << "Bytes in oct: ";
    IMD::BIG_ENDIAN::println_oct_bytes(val, " ", ofs);
    ofs << "Bytes in dec: ";
    IMD::BIG_ENDIAN::println_dec_bytes(val, " ", ofs);
    ofs << "Bytes in hex: ";
    IMD::BIG_ENDIAN::println_hex_bytes(val, " ", ofs);

    return 0;
}