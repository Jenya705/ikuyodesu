#ifndef MAT_HPP_INCLUDE
#define MAT_HPP_INCLUDE

#include <cstdint>
#include <array>

template <typename T, std::size_t C, std::size_t R>
class Mat {
private:
    constexpr static Mat<T, C, R> _calc_zero() {
        Mat<T, C, R> v;
        for (std::size_t i = 0; i < C; i++) for (std::size_t j = 0; j < R; j++) v.arr[i][j]=(T)0;
        return v;
    }

public:
    std::array<std::array<T, C>, R> arr;

    constexpr static Mat<T, C, R> ZERO = _calc_zero();

    Mat() {}
    Mat(std::array<std::array<T, C>, R> arr): arr(arr) {}

    friend Mat<T, C, R> operator+(Mat<T, C, R> lhs, const Mat<T, C, R>& rhs) {
        for (std::size_t i = 0; i < R; i++) for (std::size_t j = 0; j < C; j++) lhs.arr[i][j] += rhs.arr[i][j];
        return lhs;
    }
};

template <typename T, std::size_t L>
using Vec = Mat<T, 1, L>;

#endif