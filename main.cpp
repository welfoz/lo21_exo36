#include <iostream>
#include "evenement.h"
using namespace TIME;
int main() {
    { // dÈbut de bloc
//        Evt1j e1(Date(4,10,1957),"Spoutnik");
//        Evt1j e2(Date(11,6,2013),"Shenzhou");
//        Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(0,10));
//        Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
//        e1.afficher(); e2.afficher(); e3.afficher(); e4.afficher(); //affiche tout
//        Evt1j* pt1= &e1; Evt1j* pt2=&e2; Evt1j* pt3=&e3; Evt1j* pt4=&e4;
//        pt1->afficher(); pt2->afficher(); pt3->afficher(); pt4->afficher(); //affiche que la date et le sujet si pas virtual
//
//        std::cout << "\n\n" << e1 << "\n" << e2 << "\n" << e3 << "\n" << e4 << "\n";
//
//        Agenda A;
//        A << e1;
//        A << e2;
//        A << e3;
//        A << e4;
//        A.afficher();
//        for (auto& e : A) cout << e;
//        for (auto it=A.begin(); it!=A.end(); it++) cout << *it;
        
        Evt1j e1(Date(4,10,1957),"Spoutnik");
        Evt1j e2(Date(11,6,2013),"Shenzhou");
        Evt1jDur e3(Date(11,6,2013),"Lancement de Longue Marche",Horaire(17,38),Duree(0,10));
        Rdv e4(Date(11,4,2013),"reunion UV",Horaire(17,30),Duree(60),"Intervenants UV","bureau");
        Evt1j* pt1= &e1; Evt1j* pt2=&e2; Evt1j* pt3=&e3; Evt1j* pt4=&e4;
        Evt1j& ref1=e1; Evt1j& ref2=e2; Evt1j& ref3=e3; Evt1j& ref4=e4;
        Rdv* pt=pt1; pt->afficher();
        pt=pt2; pt->afficher();
        pt=pt3; pt->afficher();
        pt=pt4; pt->afficher();
        Rdv& r1=ref1; r1.afficher();
        Rdv& r2=ref2; r2.afficher();
        Rdv& r3=ref3; r3.afficher();
        Rdv& r4=ref4; r4.afficher();
        
    } // fin de bloc
    return 0;
}
