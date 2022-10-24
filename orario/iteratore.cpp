        bool operator==(const iteratore& i) const{
            return punt==i.punt;
        }

        bool operator!=(const iteratore& i) const{
            return punt!=i.punt;
        }

        iteratore& operator++(){
            if(punt) punt = punt->next; 
                return *this;
        }