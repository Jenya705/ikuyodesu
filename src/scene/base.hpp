#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual void update() = 0;
    virtual void render(float angle) = 0;
};

#endif
