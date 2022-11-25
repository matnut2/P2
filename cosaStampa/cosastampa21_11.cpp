#include <iostream>
using std::cout; using std::endl;

class A{
    private:
        void h() {cout << " A::h ";}
    public:
        virtual void g() {cout << " A::g ";}
        virtual void f() {cout << " A::f "; g(); h();}
        void m() {cout << " A::m "; g(); h();}
        virtual void k() {cout << " A::k "; g(); h(); m();}
        A* n(){cout << " A::n "; return this;}
};

class B : public A{
    private:
        void h(){cout << " B::h ";}

    public:
        virtual void g(){ cout<< " B::g ";}
        void m() { cout<< " B::m "; g(); h();}
        void k() { cout<< " B::K "; g(); h(); m();}
        B* n() { cout<< " B::n "; return this;}
};

B* b = new B();
A* a = new B();

int main(void){
    b->f();                 // A::f B::g A::h
    cout << endl;
    b->m();                 // B::m B::g B::h
    cout << endl;
    b->k();                 // B::k B::g B::h B::m B::g B::h
    cout << endl;
    a->f();                 // A::f B::g A::h
    cout << endl;
    a->m();                 // A::m B::g A::h
    cout << endl;
    a->k();                 // B::k B::g B::h B::m B::g B::h //non ho capito perchè
    cout << endl;
    (b->n())->g();          // B::n B::g
    cout << endl;
    (b->n())->n()->g();     // B::n B::n B::g
    cout << endl;
    (a->n())->g();          // A::n B::g //non ho capito perchè
    cout << endl;
    (a->n())->m();          // A::n A::m B::g A::h
}