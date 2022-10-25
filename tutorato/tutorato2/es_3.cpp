/*Definire una classe 'Persona' i cui oggetti rappresentano anagraficamente un
personaggio storico caratterizzato da nome, anno dI nascita e anno di morte.
Includere opportuni costruttori, metodi di accesso ai campi e l'overloading
dell'operatore di output come funzione esterna. Separare interfaccia ed
implementazione della classe.
Si definisca inoltre un esempio al metodo 'main() che usa tutti i metodi della
classe e l'operatore di output. */

 #include <iostream>
 #include <string>

class data{
    private:
        unsigned int giorno;
        unsigned int mese;
        unsigned int anno;

    public:
        data(unsigned int g = 1, unsigned int m = 1, unsigned int a = 0) : giorno(g), mese (m), anno(a) {
            if(g > 30 || m > 12 || anno > 2022)
                giorno = 0;
                mese = 0;
                anno = 0;
        }

        unsigned int Anno() const { return anno;}
        unsigned int Mese() const { return mese;}
        unsigned int Giorno() const { return giorno;}
};

std::ostream& operator<<(std::ostream& os, const data& d){
    return os << d.Giorno() << '-' << d.Mese() << '-' << d.Anno();
}

class Persona{
    private:
        std::string nome;
        std::string cognome;
        data nascita;
        data morte;

    public:
};