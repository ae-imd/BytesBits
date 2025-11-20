

namespace IMD
{
    constexpr size_t BITS_PER_BYTE(8);

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

}
