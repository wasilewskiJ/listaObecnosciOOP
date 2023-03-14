#ifndef PORTUGALCZYK_H_
#define PORTUGALCZYK_H_

#include <iostream>

#include "Osoba.hpp"

class Portugalczyk : public Osoba {
public:
    Portugalczyk(){};
    Portugalczyk(std::string imie, std::string nazwisko);

    bool sprawdzIdentyfikator(std::string identyfikator);
    bool setIdentyfikator(std::string identyfikator);
    std::string getKraj();
    void ustawDateUrodzenia(std::string identyfikator);
    void wyswietlDane();
};

#endif