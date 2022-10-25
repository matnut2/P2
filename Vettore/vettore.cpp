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

        vettore operator+(const vettore& v) const{
            vettore w(size + v.size);
            for(unsigned int k = 0; k < size; ++k){
                w.a[k] = a[k];
            }
            for(unsigned int k = size; k < w.size; ++k){
                w.a[k] = v.a[k-size];
            }
            return w;
        }

        void append(const vettore& v){
            vettore w = this->operator+(v);
            delete[] a;
            *this = this->operator+(v);
            a=w.a;
            size=w.size;
            

        }
};