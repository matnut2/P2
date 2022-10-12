#include "Punto.h"

Punto::Punto(int x, int y, int z){
    _x = x;
    _y = y;
    _z = z;
}

double Punto::getX() const { return _x;}
double Punto::getY() const{ return _y;}
double Punto::getZ() const{ return _z;}
void Punto::negate(){
    _x = _x*-1;
    _y = _y*-1;
    _z = _z*-1;
}

double Punto::norm() const{
    return sqrt(-_x*-_x - _y*-_y) ;
}

std::ostream & operator<<(std::ostream& os, const Punto& p){
    return os << '(' << p.getX() << ',' << p.getY() << ',' << p.getZ() << ')';
}

Punto operator+(const Punto& p, const Punto& s) {
    double x = p.getX() + s.getX();
    double y = p.getY() + s.getY();
    double z = p.getZ() + s.getZ();

    return Punto(x, y, x);
}