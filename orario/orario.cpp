#include <iostream>

class orario{
    private:
        int sec;

    public:
        orario(int=0, int=0, int=0);
        int Ore() const;
        int Minuti() const;
        int Secondi() const;
        operator int(){return sec;};
        orario unOraPiuTardi();
        void avantiDiUnOra();
        void StampaSecondi() const;
        static orario OraDiPranzo();
        static const int Sec_di_un_Ora = 3600;
        static const int Sec_di_un_Giorno = 86400;
        orario Somma(orario) const;
        /*orario operator+(orario) const;*/
        orario operator-(orario) const;
        bool operator==(orario) const;
        bool operator>(orario) const;
        bool operator<(orario) const;
        std::ostream& operator<<(std::ostream& os) const;
};

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

std::ostream& orario::operator<<(std::ostream& os) const{
    return os << Ore() << ':' << Minuti() << ':' << Secondi();
}

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

int main(){
    orario ora(14, 38);
    orario ora2(ora);
    
    std::cout << (ora == ora2) << std::endl;
    orario somma(ora+ora2);
    std::cout << (somma > ora2) << std::endl;
    std::cout << (somma < ora2) << std::endl; 
    std::cout << orario::OraDiPranzo() << std::endl;
    std::cout << ora << std::endl;
    ora.avantiDiUnOra();
    std::cout << ora << std::endl;

}