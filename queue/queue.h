#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>


template <class T> class queue;
template <class T>
class QueueItem{
    friend class queue<T>;
    private:
        QueueItem(const T& val) : info(val), next(0){}
        T info;
        QueueItem* next;
};

template <class T>
class queue{
    public:
        queue() : primo(nullptr), ultimo(nullptr){};
        ~queue();
        bool empty() const;
        void add(const T&);
        T remove();
        queue(const queue&);
        queue& operator=(const queue&);

        private:
            QueueItem<T>* primo;
            QueueItem<T>* ultimo;     
            static int contatore; 
};

template <class T> bool queue<T>::empty() const{
    return (primo==0);
}

template <class T> void queue<T>::add(const T& val){
    if(empty())
        primo = ultimo = new QueueItem<T>(val);
    else{
            ultimo->next = new QueueItem<T>(val);
            ultimo = ultimo->next;
    }
}

template <class T> T queue<T>::remove(){
    if(empty()){
        std::cerr << "remove() su coda vuota" << std::endl;
        exit(1);
    }

    QueueItem<T>* p = primo;
    primo = primo->next;
    if(primo==nullptr) ultimo = primo;
    T aux = p->info;
    delete p;
    return aux;

}

template <class T> queue<T>::~queue(){
    while(!empty()) remove();
}

template <class T> int queue<T>::contatore = 0;

#endif