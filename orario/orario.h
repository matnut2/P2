#ifndef ORARIO_H
#define ORARIO_H

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
        /*std::ostream& operator<<(std::ostream& os) const;*/
};

#endif