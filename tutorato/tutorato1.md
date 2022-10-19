# Esercizi sulle Funzioni
## Esercizio 1
Il programma C++ sotto ha una funzione definita _sumup()_ che è definita dopo la chiamata all'interno del _main()_. Inserisci una linea che definisca correttamente il prototipo della funzione _sumup()_.
```
#include <iostream.h>

void sumup (float&, float, int);

void main(void){
    sumup(1, 2, 3);
}

void sumup (float& sum, float x, int n)
```

## Esercizio 2
Qual'è il problema della seguente funzione?
```
float resolve(int a, float b, char c, float d){
    char e;
    float c;

    return;
}
```

Il problema è che stiamo creando una seconda variabile locale di nome _c_.

## Esercizio 3
Quale delle seguenti è un prototipo di funzione corretto?

`float resolve(int, float, char, float);`

## Esercizio 4
Qual'è il tipo di ritorno di una funzione che non ritorna nessun valore?
`void`

## Esercizio 5
Gli argomenti e i parametri delle funzione devon essere...?
> stesso numero e stesso tipo

## Esercizio 6
Quale delle seguenti affermazione descrive meglio ciò che la seguente funzione fa?
```
void increase(int number){
    ++number;
    return;
}
```
> cambia il valore della variabile locale denominata _numero_ ma non cambia il valore del parametro attuale definito nell'invocazione della funzione

# Esercizi su Valori di Default, Ricorsione e Overloading di Funzioni
## Esercizio 1
Creare un prototipo della funzione _sumup()_ che specifichi di default il valore 1.0 per _x_ e di 1 per _n_.

`void sumup(float&, float =1.0, int =1)`

## Esercizio 2
Effettua l'overloading della funzione _manip()_ del programma sottostante. La nuova funzione ha due parametri di tipo _float_ denominati _num1_ e _num2_ che sono entrambi passati per valore. Essa deve ritornare il quoziente dei due numeri. Introdurre anche il prototipo di funzione

```
float manip(float, float);

[...]

float manip(float num1, float num2){
    return num1/num2;
}
```

## Esercizio 3
Quale delle seguenti funzioni descrive al meglio la riga di codice:
```
float sum(float = 1.0, float =0.0);

[...]

z = sum(5.2);
```

> è equivalente a `z = sum(5.2, 0.0);`

## Esercizio 4
