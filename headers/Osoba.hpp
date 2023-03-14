#ifndef OSOBA_H_
#define OSOBA_H_

#include <iostream>

class Osoba
{
protected:
    std::string imie;
    std::string nazwisko;
    std::string identyfikator;
    std::string dataUrodzenia;

public:
    Osoba(){};
    Osoba(std::string imie, std::string nazwisko);

    std::string getImie();
    std::string getNazwisko();
    std::string getIdentyfikator();
    std::string getDataUrodzenia();
    std::string getImieNazwisko();

    void setImie(std::string imie);
    void setNazwisko(std::string nazwisko);

    virtual bool sprawdzIdentyfikator(std::string identyfikator) = 0;
    virtual bool setIdentyfikator(std::string identyfikator) = 0;
    virtual std::string getKraj() = 0;
    virtual void ustawDateUrodzenia(std::string identyfikator) = 0;
    virtual void wyswietlDane() = 0;
};

#endif