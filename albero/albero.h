#ifndef ALBERO_H
#define ALBERO_H

#include <iostream>

template <class T> class albero;
template <class T> std::ostream& operator<<(std::ostream& os, const albero<T>& a);


using std::cout; using std::endl;

template <class T> class albero{
    friend template <class T> std::ostream& operator<< <T> (std::ostream& os, const albero<T>& a);
    private:
        class nodo{     //template di classe annidato associato
            public:
                T info;
                nodo *sx, *cx, *dx;
                nodo(const T& t, nodo* s = nullptr, nodo* c = nullptr, nodo* d = nullptr) : info(t), sx(s), cx(c), dx(d){};

        };
        nodo<T>* root;
        static nodo<T>* copy(nodo<T>* p){
            if(p == nullptr) return nullptr;
            return new nodo(p->info, copy(p->sx), copy(p->cx), copy(p->dx));
        }
        static void destroy(nodo<T>* p){
            if(p != nullptr){
                destroy(p->sx);
                destroy(p->cx);
                destroy(p->dx);
                delete p;
            }
        }

        static bool search(const T& t, nodo<T>* p){
            if(p == nullptr) return false;
            return (t==p->info) || search(t, p->sx) || search(t, p->cx) || search(t, p->dx);   // UTILIZZO DI OR LAZY PER USCIRE SUBITO SE C'E' UN TRUE
        }

        static bool rec_eq(const nodo<T>* p1, const nodo<T>* p2){
            if(!p1 && !p2) return true;
            if(!p1 || !p2) return false;

            return p1->info == p2->info && rec_eq(p1->sx, p2->sx) && rec_eq(p1->cx, p2->cx) && rec_eq(p1->dx, p2->dx);
        }

        static void rec_print(sdt::ostream& os, nodo<T>* p){
            if(p != nullptr){
                os << p->info << ' ';
                rec_print(p->sx);
                rec_print(p->cx);
                rec_print(p->dx);
            }
        }

    public:
        albero() : root(nullptr) {};
        albero(const albero& a) : root(copy(a.root)) {};
        albero operator=(const albero& a){
            if(this != &a){ 
                destroy(root);
                root = copy(a.root);        
            }
            return *this
        };
        ~albero(){ if(root != nullptr) destroy(root) };

        void insert(const T& t){
            root = new nodo(t, copy(root), copy(root), root)
        }

        bool search(const T& t) const{
            return search(t, root);
        }

        bool operator==(const albero& a) const{
            return rec_eq(root, a.root);
        }
};

template <class T> std::ostream& operator<<(std::ostream& os, const albero<T>& a){
    albero<T>::rec_print(os, a.root);
    return os;
}
#endif