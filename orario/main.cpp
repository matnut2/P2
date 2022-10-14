#include "orario.h"

int main(){
    orario ora(14, 38);
    orario ora2(ora);
    
    std::cout << (ora == ora2) << std::endl;
    orario somma(ora+ora2);
    std::cout << (somma > ora2) << std::endl;
    std::cout << (somma < ora2) << std::endl; 
    std::cout << orario::OraDiPranzo() << std::endl;
    std::cout << ora << std::endl;
    ora.avantiDiUnOra();
    std::cout << ora << std::endl;

}