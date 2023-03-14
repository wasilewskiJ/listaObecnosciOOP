#ifndef GUI_H_
#define GUI_H_

#include <iostream>
#include <string>

#define MAKS_LICZBA_LIST 100

#include "FabrykaOsob.hpp"
#include "ListaObecnosci.hpp"

class GUI
{
protected:
    ListaObecnosci *listyObecnosci[MAKS_LICZBA_LIST];
    FabrykaOsob fabrykaOsob;
    int liczbaList;
    bool wyjdz;

    ListaObecnosci *getLista();
    Osoba *stworzUzupelnionaOsobe();
    void dodajListe();
    void dodajOsobe();
    void ustawObecnosc();
    void wyswietlObecnosc();
    void wyswietlListe();
    void zakonczProgram();
    void podejmijAkcje(int akcja);
    void pokazMenu();
public:
    GUI();
    void start();
};

#endif