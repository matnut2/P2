#ifndef BOLLETTA_H
#define BOLLETTA_H

#include "telefonata.h"

class bolletta{
    private:
        class nodo{
            public:
                nodo();
                nodo(const telefonata&, nodo*);
                telefonata info;
                nodo* next;
        };
        nodo* first;
        static nodo* copia(nodo*);
        static void distruggi(nodo*);
    
    public:
        bolletta();
        ~bolletta();
        bolletta(const bolletta&);
        bool Vuota() const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata Estrai_Una();
        bolletta& operator=(const bolletta&);
        friend std::ostream& operator<<(std::ostream&, const bolletta&);

        class iteratore{
            friend class bolletta;

            public:
                bool operator==(const iteratore&) const;
                bool operator!=(const iteratore&) const;
                iteratore& operator++();
                iteratore operator++(int);
                telefonata* operator->() const{return &(punt->info);}
                telefonata& operator*() const {return punt->info;}

            private:
                bolletta::nodo* punt;
        };

        iteratore begin() const;
        iteratore end() const;
        telefonata& operator[](const iteratore&) const;

        orario Somma_Durate(const bolletta&);


};

orario Somma_Durata(bolletta b);
bolletta Chiamate_A(int, bolletta&);

#endif