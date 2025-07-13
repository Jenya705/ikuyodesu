#ifndef MAT_HPP_INCLUDED
#define MAT_HPP_INCLUDED

#include "alg/vec.hpp"

template<typename T>
class Mat2x2 {
public:
    Vec2<T> r1, r2;

    Mat2x2(): r1(vec((T)0,(T)0)), r2(vec((T)0, (T)0)) {}
    Mat2x2(Vec2<T> r1, Vec2<T> r2): r1(r1), r2(r2) {}
    Mat2x2(T v00, T v10, T v01, T v11): r1(vec(v00, v10)), r2(vec(v01, v11)) {}
    Mat2x2(Mat2x2 mat): r1(mat.r1), r2(mat.r2) {}

    Vec2<T> c1() const {
        return vec(r1.x, r2.x);
    }

    Vec2<T> c2() const {
        return vec(r1.y, r2.y);
    }

    friend Vec2<T> operator*(const Mat2x2<T>& lhs, const Vec2<T>& rhs) { return vec(lhs.r1.dot(rhs), lhs.r2.dot(rhs)); }
    friend Mat2x2<T> operator*(const Mat2x2<T>& lhs, const Mat2x2<T>& rhs) { 
        return Mat2x2(
            lhs.r1.dot(rhs.c1()),
            lhs.r1.dot(rhs.c2()),
            lhs.r2.dot(rhs.c1()),
            lhs.r2.dot(rhs.c2()),
        );
    }
    friend Mat2x2<T> operator*(const Mat2x2<T>& lhs, const T& rhs) { return Mat2x2<T>(lhs.r1 * rhs, lhs.r2 * rhs); }

    void operator*=(const Mat2x2<T>& rhs) {
        Mat2x2<T> res = this * rhs;
        *this = res;
    }
};  

Mat2x2<float> rot_mat(float angle) {
    float c = cos(angle);
    float s = sin(angle);
    return Mat2x2<float>(vec(c, -s), vec(s, c));
}

#endif