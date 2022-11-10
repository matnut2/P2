// Si considerino le seguenti definizioni, la cui compilazione non provoca errori.

class C {
public:
static void f(const C& x) {}
};
class D {
public:
D(C x = C()) {}
void g() const {}
};
class E {
public:
E(D x = D()) {}
operator C() const {return C();}
static void h(const E& x) {C::f(x);}
void i() const {C::f(*this);}
};
C c; D d; E e;

// Delle seguenti istruzioni, quali compilano e quali no?

E::h(c); // NON COMPILA 
c.g(); // NON COMPILA 
E::h(d); // COMPILA
e.i(); // COMPILA
C::f(d); // NON COMPILA
C::f(e); // COMPILA
d.i(); // NON COMPILA
E e1(c); // COMPILA
D d1(c); // COMPILA
C c1(e); // COMPILA
C c2(d); // NON COMPILA