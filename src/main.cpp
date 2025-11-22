#include <iostream>
#include <array>
#include <fstream>
#include "../include/bytesbits.h"

#define PRINT_TYPE_INFO(T)                                             \
    std::cout << "Type: " << typeid(T).name() << std::endl             \
              << "Byte amount: " << IMD::byte_amount<T>() << std::endl \
              << "Bit amount: " << IMD::bits_amount<T>() << std::endl

int main()
{
    const char *filepath = "../docs/NS.txt";
    std::ofstream ofs(filepath);
    if (!ofs)
        return -1;

    PRINT_TYPE_INFO(int);

    bool val = true;
    ofs << "Source value: " << val << std::endl;

    ofs << "Bits: ";
    IMD::BIG_ENDIAN::println_bits(val, " ", ofs);

    ofs << "Bytes in oct: ";
    IMD::BIG_ENDIAN::println_oct_bytes(val, " ", ofs);
    ofs << "Bytes in dec: ";
    IMD::BIG_ENDIAN::println_dec_bytes(val, " ", ofs);
    ofs << "Bytes in hex: ";
    IMD::BIG_ENDIAN::println_hex_bytes(val, " ", ofs);

    std::array<std::byte, 4> bytes = {std::byte(0x78), std::byte(0x56),
                                      std::byte(0x34), std::byte(0x12)};

    std::cout << "Little endian restore value: " << IMD::LITTLE_ENDIAN::restore_value<int>(bytes.begin(), bytes.end()) << std::endl
              << "Big endian restore value: " << IMD::BIG_ENDIAN::restore_value<int>(bytes.begin(), bytes.end()) << std::endl;

    return 0;
}