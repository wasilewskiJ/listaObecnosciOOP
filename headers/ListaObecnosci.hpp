#ifndef LISTA_OBECNOSCI_H_
#define LISTA_OBECNOSCI_H_

#include <iostream>

#include "Osoba.hpp"

#define MAKS_LICZBA_OSOB 30

class ListaObecnosci
{
protected:
    Osoba *lista[MAKS_LICZBA_OSOB]; // tablica z obiektami typu osoba
    int obecnosc[MAKS_LICZBA_OSOB]; // tablica z wartosciami bool, indeks osoby w tablicy lista odpowiada jej indeksowi w tablicy obecnosc
    int indeks;
    std::string data;

public:
    ListaObecnosci(std::string data);

    int dodajOsobe(Osoba *nowaOsoba);

    int ustawObecnosc(int indeksOsoby, bool czyObecny);
    void wyswietlObecnosc(int indeksOsoby);
    void wyswietlListeObecnosci();
    void wyswietlOsoby();
    std::string getData();
};

#endif