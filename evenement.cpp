#include "evenement.h"
using namespace TIME;

std::ostream& operator<<(std::ostream& f, const TIME::Evt& e){
    e.afficher(f);
    return f;
}

Agenda& Agenda::operator<<(Evt& e){
    tab.push_back(&e);
    return *this;
}
