#ifndef RAZIONALE_H
#define RAZIONALE_H
#include <iostream>

class Raz{
    private:
        int num, den;

    public:
        Raz(int n = 0, int d = 1);
        Raz inverso() const;
        operator double() const;
        Raz operator++(int);
        bool operator==(const Raz&) const;
        static Raz unTerzo();
        Raz operator+(const Raz&) const;
        Raz operator*(const Raz&) const;

};

std::ostream& operator<<(std::ostream&, const Raz&);

#endif