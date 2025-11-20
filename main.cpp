#include <iostream>
#include "include/bytesbits.h"

#define PRINT_TYPE_INFO(T)                                             \
    std::cout << "Type: " << typeid(T).name() << std::endl             \
              << "Byte amount: " << IMD::byte_amount<T>() << std::endl \
              << "Bit amount: " << IMD::bits_amount<T>() << std::endl

int main()
{
    PRINT_TYPE_INFO(int);

    int val = 314;

    std::cout << "Value: " << val << std::endl;

    IMD::BIG_ENDIAN::println_bits(val);
    IMD::BIG_ENDIAN::println_oct_bytes(val);
    IMD::BIG_ENDIAN::println_dec_bytes(val);
    IMD::BIG_ENDIAN::println_hex_bytes(val);

    std::cout << "One bit amount: " << IMD::one_bit_amount(val) << std::endl;

    return 0;
}