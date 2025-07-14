#ifndef VEC_HPP_INCLUDED
#define VEC_HPP_INCLUDED

#include <cstdint>
#include <cmath>
#include <vector>

#define vec(x, y) Vec2(x, y)

template <typename T>
class Vec2 {
public:
    const static std::size_t DIM = 2;

    T x, y;

    Vec2(T x, T y): x(x), y(y) {};

    friend Vec2<T> operator+(const Vec2<T>& lhs, const Vec2<T>& rhs) { return vec(lhs.x + rhs.x, lhs.y + rhs.y); };
    friend Vec2<T> operator-(const Vec2<T>& lhs, const Vec2<T>& rhs) { return vec(lhs.x - rhs.x, lhs.y - rhs.y); };
    friend Vec2<T> operator*(const Vec2<T>& lhs, const T& rhs) { return vec(lhs.x * rhs, lhs.y * rhs); };
    friend Vec2<T> operator*(const T& lhs, const Vec2<T>& rhs) { return lhs * rhs; };
    friend Vec2<T> operator/(const Vec2<T> lhs, const T& rhs) { return vec(lhs.x / rhs, lhs.y / rhs); };
    friend Vec2<T> operator%(const Vec2<T> lhs, const T& rhs) { return vec(lhs.x % rhs, lhs.y % rhs); };

    void operator+=(const Vec2<T>& rhs) { x += rhs.x; y += rhs.y; };
    void operator-=(const Vec2<T>& rhs) { x -= rhs.x; y -= rhs.y; };
    void operator*=(const T& rhs) { x *= rhs; y *= rhs; };
    void operator/=(const T& rhs) { x /= rhs; y /= rhs; };
    void operator%=(const T& rhs) { x %= rhs; y %= rhs; };

    bool operator==(const T& v) const { return x==v.x && x==v.y; };

    T& operator[](std::size_t i) { return i == 0 ? x : y; };

    T dot(const Vec2<T>& rhs) { return x * rhs.x + y * rhs.y; };
    T squared_len() { return dot(this); };
    T len() { return sqrt(squared_len()); };
};

template<typename T>
struct std::hash<Vec2<T>> {
    std::size_t operator()(const Vec2<T>& s) const noexcept {
        return std::hash<T>{}(s.x) ^ (std::hash<T>{}(s.y));
    }
};

#endif
