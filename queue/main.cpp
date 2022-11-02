#include <iostream>
using std::cout; using std::endl;
#include "queue.h"

int main(void){
    queue<int>* pi = new queue<int>;
    int i;
    for(i=0; i < 10; i++)
        pi->add(i);

    for(i = 0; i < 11; i++)
        cout << pi->remove() <<endl;
}