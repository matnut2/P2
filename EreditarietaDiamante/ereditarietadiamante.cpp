#include <cmath>

class solidoConCerchio{
    protected:
        double raggio;
        double circonferenza() const {return (2*M_PI*raggio);}
        double area_cerchio() const { return (M_PI*raggio*raggio);}

    public:
        solidoConCerchio(double r) : raggio(r) {};
        virtual double area() const = 0;
        virtual double volume() const = 0;
};

class cilindro : virtual public solidoConCerchio{
    protected:
        double altezza;
        double area_laterale() const{ return circonferenza() * altezza;}

    public:
        cilindro(double r, double h): solidoConCerchio(r), altezza(h) {};
        double area() const override { return (2*area_cerchio() + area_laterale());}
        double volume() const override { return (area_cerchio() * altezza);}
};

class cono : virtual public solidoConCerchio{
    protected:
        double altezza;
        double area_laterale() const{
            double apotema = sqrt(raggio*raggio + altezza*altezza);
            return (0.5*circonferenza()*apotema);
        }

        public:
            cono(double r, double h) : solidoConCerchio(r), altezza(h) {};
            double area() const override{ return (area_cerchio() + area_laterale());}
            double volume() const override{ return (area_cerchio()*altezza/3);}
};

class cilicono : public cilindro, public cono{
    public:
        cilicono(double r, double h1, double h2) : solidoConCerchio(r), cilindro(r, h1), cono(r, h2) {};
        double area() const override{
            return (cilindro::area_laterale() + cono::area_laterale() + area_cerchio());
        }
        double volume() const override{
            return (cilindro::volume() + cono::volume());
        }
};