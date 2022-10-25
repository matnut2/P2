// QUALI CHIAMATE A FUNZIONE NEL MAIN COMPILANO E QUALI NO:
class C {
    private:
        int x;
    public:
        C(int n = 0) { x = n; }
        C F(C obj) {C r; r.x = obj.x + x; return r;}
        C G(C obj) const {C r; r.x = obj.x + x; return r;}
        C H(C& obj) {obj.x += x; return obj;}
        C I(const C& obj) {C r; r.x = obj.x + x; return r;}
        C J(const C& obj) const {C r; r.x = obj.x + x; return r;}
};
int main() {
    C x, y (1), z(2); const C v(2);
    z=x.F(y);                           // COMPILA
    v.F(y);                             // NON COMPILA, F NON E' MARCATA COSTANTE
    v.G(y);                             // COMPILA
    (v.G(y)).F(x);                      // COMPILA    
    (v. G(y)).G(x);                     // COMPILA
    x.H(v);                             // NON COMPILA PERCHE' NON PROMETTE IL CONST PER V, CHE INVECE E' COSTANTE
    x.H(z.G(y));                        // NON COMPILA PERCHE' CIO' CHE RESTITUISCE Z.G(H) E' UN OGGETTO SENZA L-VALUE
    x.I(z.G(y));                        // COMPILA (C'E' IL CONST, QUINDI VA BENE ANCHE SE NON HA L-VALUE)
    x.J(z.G(y));                        // COMPILA
    v.J(z.G(y));                        // COMPILA
}