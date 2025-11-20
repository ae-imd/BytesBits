#include <ostream>
#include <iomanip>

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

        template <typename T>
        void print_oct_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(bytes); i-- > 0;)
            {
                os << "0" << std::setw(3) << std::setfill('0') << std::oct << static_cast<short>(static_cast<unsigned char>(ptr[i]));
                if (i != 0)
                    os << sep;
            }

            os << std::dec;
        }

        template <typename T>
        void print_dec_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(bytes); i-- > 0;)
            {
                os << static_cast<short>(static_cast<unsigned char>(ptr[i]));
                if (i != 0)
                    os << sep;
            }
        }

        template <typename T>
        void print_hex_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(bytes); i-- > 0;)
            {
                os << "0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<short>(static_cast<unsigned char>(ptr[i]));
                if (i != 0)
                    os << sep;
            }

            os << std::dec;
        }

        template <typename T>
        void println_bits(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_bits(val, sep, os);
            os << std::endl;
        }

        template <typename T>
        void println_oct_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_oct_bytes(val, sep, os);
            os << std::endl;
        }

        template <typename T>
        void println_dec_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_dec_bytes(val, sep, os);
            os << std::endl;
        }

        template <typename T>
        void println_hex_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_hex_bytes(val, sep, os);
            os << std::endl;
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

        template <typename T>
        void print_oct_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(0); i < bytes; ++i)
            {
                os << "0" << std::setw(3) << std::setfill('0') << std::oct << static_cast<short>(static_cast<unsigned char>(ptr[i]));
                if (i != bytes - 1)
                    os << sep;
            }

            os << std::dec;
        }

        template <typename T>
        void print_dec_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(0); i < bytes; ++i)
            {
                os << static_cast<short>(static_cast<unsigned char>(ptr[i]));
                if (i != bytes - 1)
                    os << sep;
            }
        }

        template <typename T>
        void print_hex_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            if (sep == NULL)
                throw std::invalid_argument("sep is NULL");

            auto ptr = reinterpret_cast<const byte *>(&val);
            auto bytes = byte_amount<T>();

            for (size_t i(0); i < bytes; ++i)
            {
                os << "0x" << std::setw(2) << std::setfill('0') << std::hex << static_cast<short>(static_cast<unsigned char>(ptr[i]));
                if (i != bytes - 1)
                    os << sep;
            }

            os << std::dec;
        }

        template <typename T>
        void println_bits(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_bits(val, sep, os);
            os << std::endl;
        }

        template <typename T>
        void println_oct_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_oct_bytes(val, sep, os);
            os << std::endl;
        }

        template <typename T>
        void println_dec_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_dec_bytes(val, sep, os);
            os << std::endl;
        }

        template <typename T>
        void println_hex_bytes(const T &val, const char *sep = " ", std::ostream &os = std::cout)
        {
            print_hex_bytes(val, sep, os);
            os << std::endl;
        }

    }

    template <typename T>
    bool all_bits_one(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);

        for (size_t i(0); i < byte_amount<T>(); ++i)
            for (size_t j{BITS_PER_BYTE}; j-- > 0;)
                if (((static_cast<unsigned char>(ptr[i]) >> j) & 1) == 0)
                    return false;
        return true;
    }

    template <typename T>
    bool all_bits_zero(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);

        for (size_t i(0); i < byte_amount<T>(); ++i)
            for (size_t j{BITS_PER_BYTE}; j-- > 0;)
                if (((static_cast<unsigned char>(ptr[i]) >> j) & 1) == 1)
                    return false;
        return true;
    }

    template <typename T>
    bool any_bits_zero(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);

        for (size_t i(0); i < byte_amount<T>(); ++i)
            for (size_t j{BITS_PER_BYTE}; j-- > 0;)
                if (((static_cast<unsigned char>(ptr[i]) >> j) & 1) == 0)
                    return true;
        return false;
    }

    template <typename T>
    bool any_bits_one(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);

        for (size_t i(0); i < byte_amount<T>(); ++i)
            for (size_t j{BITS_PER_BYTE}; j-- > 0;)
                if (((static_cast<unsigned char>(ptr[i]) >> j) & 1) == 1)
                    return true;
        return false;
    }
}
