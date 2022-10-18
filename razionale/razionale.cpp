#include "razionale.h"

Raz::Raz(int n = 0, int d = 1) : num(n), den(d){};

Raz Raz::inverso() const{
    return Raz(den, num);
}

Raz::operator double() const{
    return static_cast<double>(num)/static_cast<double>(den);
}

Raz Raz::operator++(int){
    Raz r(*this);
    num +=den;
    return r; 
}

bool Raz::operator==(const Raz& r) const{
    return num*r.den == r.num*den;
}

Raz Raz::unTerzo(){
    return Raz(1, 3);
}

Raz Raz::operator+(const Raz& r) const{
    return Raz(num*r.den + r.num*den,den*r.den);
}

Raz Raz::operator*(const Raz& r) const{
    return Raz(num*r.num,den*r.den);
}

std::ostream& operator<<(std::ostream& os, const Raz& r){
    return os << "Il numero razionale rappresentato come double risulta essere: " << r.operator double();
}
