#include "headers/ListaObecnosci.hpp"

ListaObecnosci::ListaObecnosci(std::string data)
{
    this->data = data;
    this->indeks = 0;
}

int ListaObecnosci::dodajOsobe(Osoba *nowaOsoba)
{
    if (indeks >= MAKS_LICZBA_OSOB)
    {
        std::cout << "Brak miejsca na dodanie osoby" << std::endl;
        return 2;
    }
    
    for (int i = 0; i < indeks; i++)
    {
        if (lista[indeks]->getIdentyfikator() == nowaOsoba->getIdentyfikator())
        {
            std::cout << "Ta osoba jest juz na liscie." << std::endl;
            return 1;
        }
    }
    std::cout << nowaOsoba->getImieNazwisko() << " zostal/a dodany/a do listy." << std::endl;
    this->lista[this->indeks] = nowaOsoba;
    this->indeks++;
    return 0;
}

int ListaObecnosci::ustawObecnosc(int indeksOsoby, bool czyObecny)
{
    if (indeksOsoby >= this->indeks) {
        std::cout << "Brak osoby na podanym indeksie " << indeksOsoby << std::endl;
        return 1;
    }

    this->obecnosc[indeksOsoby] = czyObecny;
    return 0;
}

void ListaObecnosci::wyswietlObecnosc(int indeksOsoby)
{
    if (indeksOsoby >= this->indeks) {
        std::cout << "Brak osoby na podanym indeksie " << indeksOsoby << std::endl;
        return;
    }
    
    std::cout << this->lista[indeksOsoby]->getImieNazwisko();

    bool czyObecny = this->obecnosc[indeksOsoby];
    if (czyObecny)
    {
        std::cout << " OBECNY";
    }
    else
    {
        std::cout << " NIEOBECNY";
    }
    std::cout << std::endl;
}

void ListaObecnosci::wyswietlListeObecnosci()
{
    std::cout << "Lista obecnosci " << this->data << ":" << std::endl;
    for (int i = 0; i < indeks; i++)
    {
        this->wyswietlObecnosc(i);
    }
}

void ListaObecnosci::wyswietlOsoby()
{
    std::cout << "Osoby na liscie obecnosci " << this->data << ":" << std::endl;
    for (int i = 0; i < this->indeks; i++)
    {
        Osoba *obecnaOsoba = this->lista[i];
        std::cout << i+1 << ") " << obecnaOsoba->getImieNazwisko() << " Kraj=" << obecnaOsoba->getKraj() << " ID=" << obecnaOsoba->getIdentyfikator() << std::endl;
    }
}

std::string ListaObecnosci::getData()
{
    return data;
}
