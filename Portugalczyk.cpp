#include "headers/Portugalczyk.hpp"

Portugalczyk::Portugalczyk(std::string imie, std::string nazwisko)
{
    this->setImie(imie);
    this->setNazwisko(nazwisko);
}

void Portugalczyk::ustawDateUrodzenia(std::string identyfikator) {
    std::string data;
    std::cout << "Prosze podac date urodzenia w formacie dd.mm.rr: ";
    std::cin >> data;
    this->dataUrodzenia = data;
}

std::string Portugalczyk::getKraj()
{
    return "Portugalia";
}

void Portugalczyk::wyswietlDane()
{
    std::cout << this->imie << " " << this->nazwisko << std::endl;
    std::cout << "Identyfikator: " << this->identyfikator << std::endl;
    std::cout << "Data urodzenia: " << this->dataUrodzenia << std::endl;
    std::cout << "KRAJ: PT" << std::endl;
}

bool Portugalczyk::sprawdzIdentyfikator(std::string identyfikator)
{
    if (identyfikator.length() < 8 || identyfikator.length() > 11)
    {
        return false;
    }

    return true;
}

bool Portugalczyk::setIdentyfikator(std::string identyfikator)
{
    if (this->sprawdzIdentyfikator(identyfikator)) {
        this->identyfikator = identyfikator;
        return true;
    }
    return false;
}
