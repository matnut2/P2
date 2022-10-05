#include <iostream>

class orario{
    private:
        int sec;

    public:
        int Ore();
        int Minuti();
        int Secondi();
};

int orario::Ore(){
    return sec / 3600;
}

int orario::Minuti(){
    return ( sec / 60 ) % 60;
}

int orario::Secondi(){
    return sec % 60;
}

int main(){

}