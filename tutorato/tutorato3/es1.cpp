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

E::h(c); // NON COMPILA -> h chiede un const E& e non esiste un convertitore da C a E
c.g();   // NON COMPILA -> la classe C non ha metodi g
E::h(d); // 
e.i();   // COMPILA     -> il this dereferenziato viene convertito da E a C 
C::f(d); // NON COMPILA -> viene invocato D ma manca un convertitore da D a C
C::f(e); // COMPILA perchè c'è il convertitore di tipo
d.i();   // NON COMPILA -> la classe D non ha metodi i
E e1(c); // COMPILA     -> oggetto C convertito in oggetto D e poi da D a E
D d1(c); // COMPILA     -> oggetto C convertito in oggetto D
C c1(e); // COMPILA     -> non ci sono convertitori da E a C, ma c'è operator C() che fa al caso nostro
C c2(d); // NON COMPILA -> non ci sono convertitori da D a C