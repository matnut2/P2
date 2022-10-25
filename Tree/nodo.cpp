#include "nodo.h"

nodo* tree::copia(nodo* r){
    if(r != nullptr){
        return new nodo(r->info, copia(r->sx), copia(r->dx));
    }
    else{
        return nullptr;
    }
}

void tree::distruggi(nodo* r){
    if(r != nullptr){
        distruggi(r->sx);
        distruggi(r->dx);
        delete r;
    }
}

tree& tree::operator=(const tree& t){
    if(this != &t){
        distruggi(root);
        root=copia(t.root);
    }

    return *this;
}

tree::tree(const tree& t) : root(copia(t.root)){}

tree::~tree(){
    distruggi(root);
}