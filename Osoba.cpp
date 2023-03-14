#include "headers/Osoba.hpp"

Osoba::Osoba(std::string imie, std::string nazwisko)
{
    this->setImie(imie);
    this->setNazwisko(nazwisko);
}

std::string Osoba::getImie()
{
    return this->imie;
}

std::string Osoba::getNazwisko()
{
    return this->nazwisko;
}

std::string Osoba::getIdentyfikator()
{
    return this->identyfikator;
}

std::string Osoba::getDataUrodzenia()
{
    return this->dataUrodzenia;
}

std::string Osoba::getImieNazwisko()
{
    return this->getImie() + " " + this->getNazwisko();
}

void Osoba::setImie(std::string imie)
{
    this->imie = imie;
}

void Osoba::setNazwisko(std::string nazwisko)
{
    this->nazwisko = nazwisko;
}