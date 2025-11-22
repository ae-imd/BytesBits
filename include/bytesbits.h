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
                os << "0o" << std::setw(3) << std::setfill('0') << std::oct << static_cast<short>(static_cast<unsigned char>(ptr[i]));
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

        template <typename T, typename InputIt>
        T restore_value(InputIt beg, InputIt end)
        {
            if (std::distance(beg, end) != sizeof(T))
                throw std::runtime_error("std::distance(beg, end) != sizeof(T)");

            T res;
            auto ptr = reinterpret_cast<std::byte *>(&res);
            size_t ind(byte_amount<T>() - 1);

            while (beg != end)
            {
                ptr[ind] = static_cast<std::byte>(*beg);
                --ind;
                ++beg;
            }

            return res;
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

        template <typename T, typename InputIt>
        T restore_value(InputIt beg, InputIt end)
        {
            if (std::distance(beg, end) != sizeof(T))
                throw std::runtime_error("std::distance(beg, end) != sizeof(T)");

            T res;
            auto ptr = reinterpret_cast<std::byte *>(&res);
            size_t ind(0);

            while (beg != end)
            {
                ptr[ind] = static_cast<std::byte>(*beg);
                ++ind;
                ++beg;
            }

            return res;
        }
    }

    template <typename T>
    bool all_bits_one(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);
        auto tmp = std::byte((1 << BITS_PER_BYTE) - 1);

        for (size_t i(0); i < byte_amount<T>(); ++i)
            if (ptr[i] != tmp)
                return false;
        return true;
    }

    template <typename T>
    bool all_bits_zero(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);

        for (size_t i(0); i < byte_amount<T>(); ++i)
            if (ptr[i] != std::byte(0))
                return false;
        return true;
    }

    template <typename T>
    bool any_bits_zero(const T &val)
    {
        return !all_bits_one(val);
    }

    template <typename T>
    bool any_bits_one(const T &val)
    {
        return !all_bits_zero(val);
    }

    template <typename T>
    size_t zero_bit_amount(const T &val)
    {
        auto ptr = reinterpret_cast<const byte *>(&val);
        size_t res{0}, bytes = byte_amount<T>();

        for (size_t i(bytes); i-- > 0;)
            for (size_t j(BITS_PER_BYTE); j-- > 0;)
                if (((static_cast<unsigned char>(ptr[i]) >> j) & 1) == 0)
                    ++res;

        return res;
    }

    template <typename T>
    size_t one_bit_amount(const T &val)
    {
        return bits_amount<T>() - zero_bit_amount(val);
    }

    template <typename T>
    void reverse_bytes(T &val)
    {
        auto ptr = reinterpret_cast<std::byte *>(&val);
        size_t bytes = byte_amount<T>();
        for (size_t i(0); i < bytes / 2; ++i)
            std::swap(ptr[i], ptr[bytes - 1 - i]);
    }

    template <typename T>
    void reverse_bits(T &val)
    {
        auto ptr = reinterpret_cast<std::byte *>(&val);
        size_t bytes = byte_amount<T>();

        for (size_t i(0); i < bytes; ++i)
        {
            unsigned char byte = static_cast<unsigned char>(ptr[i]);
            unsigned char reversed_byte = 0;
            for (size_t j(0); j < BITS_PER_BYTE; ++j)
                reversed_byte |= ((byte >> j) & 1) << (BITS_PER_BYTE - 1 - j);
            ptr[i] = static_cast<std::byte>(reversed_byte);
        }

        reverse_bytes(val);
    }

    template <typename T>
    void fill_one_bit(T &val)
    {
        auto ptr = reinterpret_cast<std::byte *>(&val);
        size_t bytes = byte_amount<T>();
        auto tmp = std::byte((1 << BITS_PER_BYTE) - 1);

        std::fill(ptr, ptr + bytes, tmp);
    }

    template <typename T>
    void fill_zero_bit(T &val)
    {
        auto ptr = reinterpret_cast<std::byte *>(&val);
        size_t bytes = byte_amount<T>();

        std::fill(ptr, ptr + bytes, std::byte(0));
    }

    template <typename T>
    constexpr T rotate_left(T value, int shift)
    {
        size_t bits = bits_amount<T>();
        shift %= bits;
        if (shift == 0)
            return T(0);
        return (value << shift) | (value >> (bits - shift));
    }

    template <typename T>
    constexpr T rotate_right(T value, int shift)
    {
        size_t bits = bits_amount<T>();
        shift %= bits;
        if (shift == 0)
            return T(0);
        return (value >> shift) | (value << (bits - shift));
    }
}
