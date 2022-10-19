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