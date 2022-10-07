#include <iostream>

class orario{
    private:
        int sec;

    public:
        orario(int=0, int=0, int=0);
        int Ore();
        int Minuti();
        int Secondi();
};

orario::orario(int o, int m, int s){
    
    if( o >= 0 && o <= 24 && m >= 0 && m <= 60 && s >= 0 && s <= 60)
        sec = o * 3600 + m * 60 + s;
    else sec = 0;
}

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