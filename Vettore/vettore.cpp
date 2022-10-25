#include <iostream>

class vettore{
    private:
        int* const a;
        unsigned int size;

    public:
        explicit vettore(unsigned int dim = 0, int v =0) : a(dim==0 ? nullptr : new int[dim]), size(dim) {
            for(unsigned int k = 0; k<size; ++k){
                a[k]=v;
            }
        }
};