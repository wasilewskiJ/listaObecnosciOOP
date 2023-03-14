#include "headers/GUI.hpp"

GUI::GUI() {
    this->wyjdz = false;
    this->liczbaList = 0;
}

ListaObecnosci *GUI::getLista()
{
    std::string data;
    std::cout << "Prosze podac date listy, na ktorej ma byc wykonana akcja w formacie dd.mm.rr: ";
    std::cin >> data;
    for (int i = 0; i < this->liczbaList; i++)
    {
        if (this->listyObecnosci[i]->getData() == data)
        {
            return this->listyObecnosci[i];
        }
    }
    return nullptr;
}

void GUI::dodajListe()
{
    if (this->liczbaList >= MAKS_LICZBA_LIST)
    {
        std::cout << "Brak miejsca na dodanie nowej listy" << std::endl;
        return;
    }

    std::string data;
    std::cout << "Prosze podac date listy, na ktorej ma byc wykonana akcja w formacie dd.mm.rr: ";
    std::cin >> data;
    ListaObecnosci *nowaLista = new ListaObecnosci(data);
    listyObecnosci[this->liczbaList++] = nowaLista;
}

Osoba *GUI::stworzUzupelnionaOsobe()
{
    std::string kraj;
    std::cout << "Proszę podać kod kraju osoby PL/PT (Polska/Portugalia): ";
    std::cin >> kraj;
    Osoba *nowaOsoba = this->fabrykaOsob.utworzOsobe(kraj);

    if (nowaOsoba != nullptr)
    {
        std::string zmiennaPomocnicza;
        std::cout << "Prosze podac imie osoby, na ktorej ma byc wykonana akcja: ";
        std::cin >> zmiennaPomocnicza;
        nowaOsoba->setImie(zmiennaPomocnicza);

        std::cout << "Prosze podac nazwisko osoby, na ktorej ma byc wykonana akcja: ";
        std::cin >> zmiennaPomocnicza;
        nowaOsoba->setNazwisko(zmiennaPomocnicza);

        bool idCheck = false;
        while (!idCheck)
        {
            std::cout << "Prosze podac identyfikator osoby, na ktorej ma byc wykonana akcja: ";
            std::cin >> zmiennaPomocnicza;
            idCheck = nowaOsoba->sprawdzIdentyfikator(zmiennaPomocnicza);
            if (!idCheck)
            {
                std::cout << "Identyfikator " << zmiennaPomocnicza << " jest niepoprawny" << std::endl;
            }
        }
        nowaOsoba->setIdentyfikator(zmiennaPomocnicza);
        nowaOsoba->ustawDateUrodzenia(zmiennaPomocnicza);
    }

    return nowaOsoba;
}

void GUI::dodajOsobe()
{
    ListaObecnosci *listaObecnosci = this->getLista();
    if (listaObecnosci == nullptr)
    {
        std::cout << "Niepoprawna data. Kod bledu: 3" << std::endl;
        return;
    }

    Osoba *nowaOsoba = this->stworzUzupelnionaOsobe();
    if (nowaOsoba == nullptr)
    {
        std::cout << "Wystapil blad, osoba nie mogla zostac stworzona." << std::endl;
        return;
    }
    listaObecnosci->dodajOsobe(nowaOsoba);
}

void GUI::ustawObecnosc()
{
    ListaObecnosci *listaObecnosci = this->getLista();
    if (listaObecnosci == nullptr)
    {
        std::cout << "Niepoprawna data. Kod bledu: 3" << std::endl;
        return;
    }

    int numerWybranejOsoby;
    char odpowiedz;

    listaObecnosci->wyswietlOsoby();
    std::cout << "Wybierz osobe (podaj numer): ";
    std::cin >> numerWybranejOsoby;

    std::cout << "Czy jest obecny/a (t/n)?: ";
    std::cin >> odpowiedz;

    listaObecnosci->ustawObecnosc(numerWybranejOsoby - 1, odpowiedz == 't');
}

void GUI::wyswietlObecnosc()
{
    ListaObecnosci *listaObecnosci = this->getLista();
    if (listaObecnosci == nullptr)
    {
        std::cout << "Niepoprawna data. Kod bledu: 3" << std::endl;
        return;
    }

    listaObecnosci->wyswietlListeObecnosci();
}

void GUI::wyswietlListe()
{
    ListaObecnosci *listaObecnosci = this->getLista();
    if (listaObecnosci == nullptr)
    {
        std::cout << "Niepoprawna data. Kod bledu: 3" << std::endl;
        return;
    }

    listaObecnosci->wyswietlOsoby();
}

void GUI::zakonczProgram()
{
    this->wyjdz = true;
    std::cout << "Dobranoc." << std::endl;
}

void GUI::podejmijAkcje(int akcja)
{
    switch(akcja) {
        case 0:
            this->dodajListe();
            break;
        case 1:
            this->dodajOsobe();
            break;
        case 2:
            this->ustawObecnosc();
            break;
        case 3:
            this->wyswietlObecnosc();
            break;
        case 4:
            this->wyswietlListe();
            break;
        case 5:
            this->zakonczProgram();
            break;
        default:
            std::cout << "Podales niepoprawny numer akcji" << std::endl;
            break;
    }
}

void GUI::pokazMenu()
{
    std::cout << std::endl << "==Menu==" << std::endl;
    std::cout << "0 - Dodaj nowa liste" << std::endl;
    std::cout << "1 - Dodaj osobe do listy" << std::endl;
    std::cout << "2 - Ustaw obecnosc" << std::endl;
    std::cout << "3 - Wyswietl obecnosc" << std::endl;
    std::cout << "4 - Wyswietl liste" << std::endl;
    std::cout << "5 - Zakoncz program" << std::endl;
    std::cout << "Wybierz akcje: ";
}

void GUI::start()
{
    int akcja;
    std::cout << "Witaj w programie Lista Obecnosci." << std::endl;

    while (!this->wyjdz)
    {
        this->pokazMenu();
        std::cin >> akcja;

        this->podejmijAkcje(akcja);
    }
}
