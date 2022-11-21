#include <iostream>
using std::cout; using std::endl;

class C {

    public:
        void ind(){cout << this << endl;};
};

int main(void){
    C a;
    a.ind();
}