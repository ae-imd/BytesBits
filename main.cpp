#include <iostream>
#include "include/bytesbits.h"

#define PRINT_TYPE_INFO(T)                                             \
    std::cout << "Type: " << typeid(T).name() << std::endl             \
              << "Byte amount: " << IMD::byte_amount<T>() << std::endl \
              << "Bit amount: " << IMD::bits_amount<T>() << std::endl

int main()
{
    PRINT_TYPE_INFO(int);

    return 0;
}