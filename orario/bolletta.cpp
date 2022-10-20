#include "bolletta.h"

bolletta::nodo::nodo() : next(0) {} 
bolletta::nodo::nodo(const telefonata& t, nodo * s) : info(t), next(s) {}
bolletta::bolletta() : first(0) {}

bool bolletta::Vuota() const {
    return first == 0;
}

void bolletta::Aggiungi_Telefonata(const telefonata & t){
    first = new nodo(t, first);
}

void bolletta::Togli_Telefonata(const telefonata& t){
    nodo * p = first, *prec=nullptr;
    while( p && !(p->info == t)){
        prec = p;
        p = p->next;
    }
    if(p){
        if(prec==nullptr)
            first=p->next;
        else
            prec->next = p->next;
        
        delete p;
    }
}

telefonata bolletta::Estrai_Una(){
    nodo* p = first;
    first = first->next;
    telefonata aux = p->info;
    delete p;
    return aux;
}

bolletta& bolletta::operator=(const bolletta& b){
    if(this != &b){
        distruggi(first);
        first = copia(b.first);
    }
    return *this;
}

bolletta::nodo* bolletta::copia(nodo* p){
    if(!p) return nullptr;

    nodo* primo = new nodo(p->info, nullptr);
    nodo* q = primo;

    while(p->next){
        p= p->next;
        q->next = new nodo(p->info, nullptr);
        q = q->next;    
    }

    return primo;
}

void bolletta::distruggi(nodo* p){
    if(p!=nullptr){
        nodo* q = p;
        while (p!=nullptr){
            p = p->next;
            delete q;
            q = p;
        }
    }
}

bolletta::bolletta(const bolletta& b) : first(copia(b.first)){}

orario Somma_Bolletta(bolletta b){
    orario durata;
    while(!b.Vuota()){
        telefonata t = b.Estrai_Una();
        durata = durata + t.Fine() - t.Inizio();
    }

    return durata;
}

bolletta Chiamate_A(int num, bolletta& b){
    bolletta selezionate, resto;
    while(!b.Vuota()){
        telefonata t = b.Estrai_Una();
        if(t.Numero() == num)
            selezionate.Aggiungi_Telefonata(t);
        else
            resto.Aggiungi_Telefonata(t);
    }

    b = resto;
    return selezionate;
}

bolletta::~bolletta(){ if(first) delete first;}
bolletta::nodo::~nodo(){
    if(next != 0) delete next;
}