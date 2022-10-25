class nodo{
    friend class tree;
    private:
        nodo(char c = '*', nodo* s = 0, nodo* d = 0) : info(c), sx(s), dx(d){}
        char info;
        nodo* sx;
        nodo* dx;
};

class tree{
    public:
        tree() : root(nullptr){}
        tree(const tree&);
        tree& operator=(const tree&);
        tree(const tree&);
        ~tree();
        static nodo* copia(nodo*);
        static void distruggi(nodo*);

    private:
        nodo* root;
};