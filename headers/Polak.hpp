#ifndef POLAK_H_
#define POLAK_H_

#include <iostream>

#include "Osoba.hpp"

class Polak : public Osoba
{
public:
    static std::string uzyskajDateZPeselu(std::string identyfikator);

    Polak(){};
    Polak(std::string imie, std::string nazwisko);

    bool sprawdzIdentyfikator(std::string identyfikator);
    bool setIdentyfikator(std::string identyfikator);
    std::string getKraj();
    void ustawDateUrodzenia(std::string identyfikator);
    void wyswietlDane();
};

#endif