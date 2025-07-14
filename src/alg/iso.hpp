#ifndef ISO_HPP_INCLUDED
#define ISO_HPP_INCLUDED

#include "../alg/vec.hpp"
#include "../alg/mat.hpp"

class Iso2 {
public:
    Vec2<float> t;
    Mat2x2<float> rs;

    Iso2(Vec2<float> t, Mat2x2<float> rs): t(t), rs(rs) {}
    Iso2(): Iso2(vec((float)0,(float)0), Mat2x2<float>()) {}
    Iso2(Vec2<float> t): Iso2(t, Mat2x2<float>()) {}
    Iso2(Mat2x2<float> rs): Iso2(vec((float)0, (float) 0), rs) {}

    void scale(float s) { rs *= s; }
    void rotate(float a) { rs *= rot_mat(a); }
    Vec2<float> apply(Vec2<float> p) { return rs * (p - t); }
};

#endif
