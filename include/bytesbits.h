#include <ostream>

namespace IMD
{
    constexpr size_t BITS_PER_BYTE(8);
    using byte = std::byte;

    template <typename T>
    constexpr size_t byte_amount() noexcept
    {
        return sizeof(T);
    }

    template <typename T>
    constexpr size_t bits_amount() noexcept
    {
        return byte_amount<T>() * BITS_PER_BYTE;
    }

    namespace BIG_ENDIAN
    {
        template <typename T>
        void print_bits(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(bytes); i-- > 0;)
            {
                for (size_t j(BITS_PER_BYTE); j-- > 0;)
                    os << ((static_cast<unsigned char>(ptr[i]) >> j) & 1);
                if (sep && i != 0)
                    os << sep;
            }
        }
    }

    namespace LITTLE_ENDIAN
    {
        template <typename T>
        void print_bits(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(0); i < bytes; ++i)
            {
                for (size_t j(BITS_PER_BYTE); j-- > 0;)
                    os << ((static_cast<unsigned char>(ptr[i]) >> j) & 1);
                if (sep && i != bytes - 1)
                    os << sep;
            }
        }
    }

}
