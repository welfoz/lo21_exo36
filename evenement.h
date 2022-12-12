//#if !defined(_EVENEMENT_H)
//#define _EVENEMENT_H
#include <iostream>
#include <string>
#include "timing.h"
#include <vector>
using namespace std;

namespace TIME {
    class Evt {
    private:
        string sujet;
    public:
        Evt(const string& s):sujet(s){};
        const string& getDescription() const {return sujet;};
        virtual void afficher(ostream&f = cout) const = 0;
    };

    class Evt1j : public Evt {
    private:
        Date date;
    public:
        Evt1j(const Date& d, const std::string& s) : Evt(s), date(d){
            cout << "construction Evt1j " << this << "\n";
        }
        const Date& getDate() const { return date; }
        virtual void afficher(std::ostream& f = std::cout) const {
            f << "***** Evt ********" << "\n" << "Date=" << date << " sujet=" << getDescription() << "\n";
        }
        virtual ~Evt1j() { cout << "destruction Evt1j " << this << "\n"; }
    };

    class EvtPj : public Evt {
    private:
        Date dateDebut;
        Date dateFin;
    public:
        EvtPj(const Date& d1, const Date& d2, const std::string& s) : Evt(s), dateDebut(d1), dateFin(d2){
            cout << "construction EvtPj " << this << "\n";
        }
        const Date& getDateDebut() const { return dateDebut; }
        const Date& getDateFin() const { return dateFin; }
        virtual void afficher(std::ostream& f = std::cout) const {
            f << "***** Evt ********" << "\n" << "Date debut =" << dateDebut << "Date fin =" << dateFin << " sujet=" << getDescription() << "\n";
        }
        virtual ~EvtPj() { cout << "destruction EvtPj " << this << "\n"; }
    };

    class Evt1jDur : public Evt1j {
        Horaire horaire;
        Duree duree;
    public:
        Evt1jDur(const Date& d, const std::string& s,
            const Horaire& h, const Duree& dur) :
            Evt1j(d, s), horaire(h), duree(dur) {
            cout << "construction Evt1jDur " << this << "\n";
        }
        ~Evt1jDur() { cout << "destruction Evt1jDur " << this << "\n"; }
        const Horaire& getHoraire() const { return horaire; }
        const Duree& getDuree() const { return duree; }
        void afficher(std::ostream& f = std::cout) const {
            Evt1j::afficher(f);
            f    << "Horaire=" << horaire
                << "Duree=" << duree << "\n";
        }
    };

    class Rdv : public Evt1jDur {
        string personnes;
        string lieu;
    public:
        Rdv(const Date& d, const std::string& s,
            const Horaire& h, const Duree& dur,
            const string& p, const string& l) :
            Evt1jDur(d, s, h, dur), personnes(p), lieu(l) {
            cout << "construction Rdv " << this << "\n";
        }
        ~Rdv() { cout << "destruction Rdv " << this << "\n"; }
        const string& getPersonnes() const { return personnes; }
        const string& getLieu() const { return lieu; }
        void afficher(std::ostream& f = std::cout) const {
            Evt1jDur::afficher(f);
            f << "Personnes=" << personnes
                << "Lieu=" << lieu << "\n";
        }
    };

    class Agenda {
    private:
        vector<Evt*> tab;
    public:
        Agenda() = default;
        virtual ~Agenda() = default; //au cas ou Agenda serait spécialisé par la suite !!
        Agenda& operator<<(Evt& e);
        void afficher(ostream& f = cout) const{
            cout << "Agenda : \n";
            for (auto pt : tab) pt->afficher(f);
        };
        Agenda(Agenda& a) = delete;
        Agenda& operator=(Agenda& a) = delete;
        
        class Iterator : public vector<Evt*>::iterator {
        public:
            //on utilise l'iterator de vector
            Iterator(vector<Evt*>::iterator it) : vector<Evt*>::iterator(it) {};
            //on a besoin d'une indirection supplémentaire car sinon va renvoyer un pointeur de Evt
            Evt& operator*() const {return *vector<Evt*>::iterator::operator*();}
        };
        Iterator begin(){return tab.begin();}
        Iterator end(){return tab.end();}
        //on peut aussi faire un const iterator identique
    };

    
}

std::ostream& operator<<(std::ostream& f, const TIME::Evt& e);


//#endif
