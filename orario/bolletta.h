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

    public:
        bolletta();
        bool Vuota() const;
        void Aggiungi_Telefonata(const telefonata&);
        void Togli_Telefonata(const telefonata&);
        telefonata Estrai_Una();
};

#endif