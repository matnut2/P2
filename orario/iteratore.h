class iteratore{
    private:
    contenitore::nodo* punt;

    public:
        bool operator==(const iteratore& i) const;
        bool operator!=(const iteratore& i) const;
        iteratore& operator++();
}