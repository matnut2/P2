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
Quali sono le caratteristiche principali delle funzioni ricorsive?
> una funzione che normalmente chiama sè stessa, ma ci sono dei modi per finirla senza richiamarsi

## Esercizio 5
Cosa richiede l'overloading di una funzione?
> la funzione deve avere un numero diverso di parametri o almeno un parametro deve essere di tipo diverso

## Esercizio 6
Dati i seguenti prototipi di funzione:
```
int suspend(int, int);
float suspend(int, int =30, int =25, int =53);
```
quale delle seguenti chiamate porta ad avere ambiguità?
> la seconda, in quanto essendoci due parametri attuali definiti, il compilatore non sa quale definizione scegliere. Quindi `suspend(3,5)` produce ambiguità

# Esercizi su Subscripted Variables e Puntatori
## Esercizio 1
Data la definizione `int box[10]`, cosa c'è di sbagliato nel seguente _statement_: `box[10] = 10`?
> il problema sta nel fatto che gli indici di _box_ vanno da 0 a 9 e non da 1 a 10, quindi richiamando `box[10]` si tenta di accedere ad una locazione di memoria che non appartiene all'array

## Esercizio 2
In un array ci possono essere valori di tipi diversi
> falso, un array è un insieme di valori dello stesso tipo e che in memoria sono posizionati in celle contigue

## Esercizio 3
Passare grandi array all funzioni è una brutta idea perchè impiega molto tempo per copiarlo all'interno della funzione
> falso, se l'array viene passao per riferimento non sorge il problema della copia, andando così a minimizzare il tempo per l'accesso all'array

## Esercizio 4
Dato l'array `int link[5] = { 2, 3, 4, 0, 1)` quale output daranno i seguenti _statement_?
* `cout << link[0]` -> 2
* `cout << link[link[2]]` -> 1
* `cout << [link[link[link[link[link[k]]]]]` -> k