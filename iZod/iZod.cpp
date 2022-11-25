#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>
using std::string;
using std::vector;

class FileAudio{
    protected:
        string titolo;
        unsigned int dimensione;
    
    public:
        virtual FileAudio* clone() const = 0;
        virtual bool qualita() const = 0;
        virtual ~FileAudio() {}
        double getSize() const {return dimensione;}
        virtual bool operator==(const FileAudio& f) const {
            return typeid(*this) == typeid(f) && 
            titolo == f.titolo && dimensione == f.dimensione;
        }
};

class Mp3 : public FileAudio{
    private:
        unsigned int bitrate;
        
    public:
        Mp3* clone() const override{
            return new Mp3(*this);
        }

        bool qualita() const override{
            return bitrate >= 192 ? true: false;
        }

        unsigned int getBitrate() const {return bitrate;}  
        bool operator==(const FileAudio& f) const override {    
            return FileAudio::operator==(f)
                   && bitrate == static_cast<const Mp3&>(f).bitrate;
        }
};

class WAV : public FileAudio{
    private:
        unsigned int frequenza;
        bool loseless;

    public:
        WAV* clone() const override{
            return new WAV(*this);
        }

        bool qualita() const override{
            return frequenza >= 96 ? true : false;
        }

        bool getLossLess() const {return loseless;}
        bool operator==(const FileAudio& f) const override {
            return FileAudio::operator==(f)
                   && frequenza == static_cast<const WAV&>(f).frequenza
                   && loseless == static_cast<const WAV&>(f).loseless;  }
};

class iZod{
    private:
        class brano{
            public:
                FileAudio * ptr;
                brano(FileAudio* p) : ptr(p->clone()){};
                brano(const brano& b) : ptr(b.ptr->clone()){};
                brano& operator=(const brano& b){
                    if(this != &b){
                        delete ptr;
                        ptr = b.ptr->clone();
                    }

                    return *this;
                }

                ~brano() {delete ptr;}
        };

        vector<brano> brani;

    public:
        vector<Mp3> mp3(const double dim, const int br) const{
           vector<Mp3> selected;
            for(vector<brano>::const_iterator cit = brani.begin(); cit != brani.end(); ++cit){
                Mp3* p = dynamic_cast<Mp3*>(cit->ptr);
                if(p != nullptr && p->getSize() >= dim && p->getBitrate() >= br)
                    selected.push_back(*p);
            }

            return selected;
        }

        vector<FileAudio*> braniQual() const{
            vector<FileAudio*> selected;

            for(auto cit = brani.begin(); cit != brani.end(); ++cit)
                if((cit->ptr)->qualita() && (dynamic_cast<WAV*>(cit->ptr) == nullptr || static_cast<WAV*>(cit->ptr)->getLossLess()))
                    selected.push_back(cit->ptr);
                return selected;
            
        }
        
        void insert(Mp3* p){
            bool found = false;
            for(auto it = brani.begin(); !found && it != brani.end(); ++it)
                if(*(it->ptr) == *p) found = true;

            if(!found) brani.push_back(p);
        }
};

int main(void){}