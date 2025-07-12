#ifndef MAT_HPP_INCLUDE
#define MAT_HPP_INCLUDE

#include <cstdint>
#include <array>
#include <cassert>

template <typename T, std::size_t C, std::size_t R>
class Mat {
public:
    std::array<std::array<T, C>, R> arr;

    Mat() {
        for (std::size_t i = 0; i < R; i++) for (std::size_t j = 0; j < C; j++) arr[i][j] = (T)0;
    }
    Mat(std::array<T, C * R> arr) {
        for (std::size_t i = 0; i < C * R; i++) this->operator[](i) = arr[i];
    }
    Mat(std::array<std::array<T, C>, R> arr): arr(arr) {}

    T& operator[](std::size_t r, std::size_t c) {
        assert(r < R && c < C);
        return arr[r][c];
    }

    const T& operator[](std::size_t r, std::size_t c) const {
        assert(r < R && c < C);
        return arr[r][c];
    }

    T& operator[](std::size_t i) {
        assert(i < R * C);
        return arr[i / R][i % R];
    }

    const T& operator[](std::size_t i) const {
        assert(i < R * C);
        return arr[i / R][i % R];
    }

    friend Mat<T, C, R> operator+(Mat<T, C, R> lhs, const Mat<T, C, R>& rhs) {
        for (std::size_t i = 0; i < C * R; i++) lhs[i] += rhs[i];
        return lhs;
    }

    friend Mat<T, C, R> operator-(Mat<T, C, R> lhs, const Mat<T, C, R>& rhs) {
        for (std::size_t i = 0; i < C * R; i++) lhs[i] -= rhs[i];
        return lhs;
    }

    friend Mat<T, C, R> operator-(Mat<T, C, R> lhs) {
        for (std::size_t i = 0; i < C * R; i++) lhs[i] = -lhs[i];
        return lhs;
    }

    template<std::size_t C1>
    friend Mat<T, C1, R> operator*(const Mat<T, C, R>& lhs, const Mat<T, C1, C>& rhs) {
        Mat<T, C1, R> result;
        for (std::size_t i = 0; i < C1; i++) {
            for (std::size_t j = 0; j < R; j++) {
                for (std::size_t k = 0; k < C; k++) {
                    result[j,i]+=lhs[j,k]*rhs[k,i];
                }
            }
        }
        return result;
    }
};

template <typename T, std::size_t L>
using Vec = Mat<T, 1, L>;

#endif