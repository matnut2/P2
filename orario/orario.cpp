#include "orario.h"

orario::orario(int o, int m, int s){
    
    if( o >= 0 && o <= 24 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
        sec = o * 3600 + m * 60 + s;
    else sec = 0;
}

int orario::Ore() const{
    return sec / 3600;
}

int orario::Minuti() const{
    return ( sec / 60 ) % 60;
}

int orario::Secondi() const{
    return sec % 60;
}

orario orario::unOraPiuTardi(){
    orario aux;
    aux.sec = (sec + 3600) % 86400;
    return aux;
}

void orario::avantiDiUnOra(){
    sec = (sec + 3600) % 86400;
}

void orario::StampaSecondi() const{
    std::cout << sec << std::endl;
}

orario orario::OraDiPranzo(){
    return orario(13, 15);
}

orario orario::Somma(orario o) const{
    orario aux;
    aux.sec = sec + o.sec;

    return aux;
}
/*
orario orario::operator+(orario o) const{
    orario aux;
    aux.sec = (sec + o.sec) % 86400;

    return aux;
}
*/

orario orario::operator-(orario o) const{
    orario aux;
    aux.sec = (sec - o.sec) % 86400;
    return aux;
}

bool orario::operator==(orario o) const{
    return sec == o.sec ? true : false;
}

bool orario::operator>(orario o) const{
    return sec > o.sec ? true : false;
}

bool orario::operator<(orario o) const{
    return sec < o.sec ? true : false;
}

/*
std::ostream& orario::operator<<(std::ostream& os) const{
    return os << Ore() << ':' << Minuti() << ':' << Secondi();
}
*/

std::ostream & operator<<(std::ostream& os, const orario& o){
    return os << o.Ore() << ':' << o.Minuti() << ':' << o.Secondi();
}

orario operator+(const orario& t, const orario& s){
    int sec = t.Secondi() + s.Secondi();
    int min = t.Minuti() + s.Minuti() + sec / 60;
    sec = sec % 60;
    int ore = t.Ore() + s.Ore() + min / 60;
    min = min % 60;
    ore = ore % 24;

    return orario(ore, min, sec);
}

