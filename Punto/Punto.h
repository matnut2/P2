#include <cmath>
#include <iostream>

class Punto{
    private:
        double _x, _y, _z;

    public:
        Punto(int=0, int=0, int=0);
        double getX() const;
        double getY() const;
        double getZ() const;
        void negate();
        double norm() const;
};

