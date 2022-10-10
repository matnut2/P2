class C { int a[1000];};

bool byValue(C x){ return true;}
bool byReference(C x){ return true;}

int main(){
    C obj;
    for(int i = 0; i < 10000000; i++) byValue(obj);
    for(int i = 0; i < 10000000; i++) byReference(obj);
}