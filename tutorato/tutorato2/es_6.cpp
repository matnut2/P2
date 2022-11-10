// Cosa stampa?
#include <iostream>
using namespace std;
class C {
    public:
    C() { cout << "CO ";}
    C(const C&) { cout << "Cc ";}
};
class D {
    public:
    C c;
    D() { cout << "DO ";}
};
class D2 {
    public:
    C c;
    D2 () { cout << "D0 ";}
    D2(const D&) { cout <<  "Dc ";}
};

int main() {
    D x;            // C0 D0
    cout << endl;
    D y(x);         // Cc
    cout << endl;

    D2 xx;          // C0 D0
    cout << endl;
    D2 yy(xx);      // C0 Dc
    cout << endl;
}