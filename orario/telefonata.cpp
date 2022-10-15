#include "telefonata.h"

telefonata::telefonata(const orario& i, const orario& f, const int& n) : inizio(i), fine(f), numero(n){};

telefonata::telefonata() : numero(0){};

orario telefonata::Inizio() const { return inizio;}
orario telefonata::Fine() const { return fine;}
int telefonata::Numero() const { return numero;}
bool telefonata::operator==(const telefonata& t) const{
    return inizio == t.inizio && fine == t.fine && numero == t.numero;
}

std::ostream& operator<<(std::ostream& s, const telefonata& t){
    return s << "INIZIO: " << t.Inizio() << std::endl << "FINE: " << t.Fine() << std::endl << "NUMERO: " << t.Numero();
}