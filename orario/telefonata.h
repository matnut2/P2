#ifndef TELEFONATA_H
#define TELEFONATA_H
#include "orario.h"

class telefonata{
    orario inizio, fine;
    const int numero;

    public:
    telefonata(const orario&, const orario&, const int&);
    telefonata();
    orario Inizio() const;
    orario Fine() const;
    int Numero() const;
    bool operator==(const telefonata&) const;
    
};

std::ostream& operator<<(std::ostream&, const telefonata&);


#endif