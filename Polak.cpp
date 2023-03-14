#include "headers/Polak.hpp"

std::string Polak::uzyskajDateZPeselu(std::string identyfikator)
{
    std::string rok, miesiac, dzien;
    rok.push_back(identyfikator[0]);
    rok.push_back(identyfikator[1]);

    miesiac.push_back(identyfikator[2]);
    miesiac.push_back(identyfikator[3]);

    dzien.push_back(identyfikator[4]);
    dzien.push_back(identyfikator[5]);
    if (miesiac[0] == '8' || miesiac[0] == '9')
    {
        miesiac = std::to_string(atoi(miesiac.c_str()) - 80);
        rok.insert(0, "18");
    }
    else if (miesiac[0] == '0' || miesiac[0] == '1')
    {
        miesiac = std::to_string(atoi(miesiac.c_str()));
        rok.insert(0, "19");
    }
    else if (miesiac[0] == '2' || miesiac[0] == '3')
    {
        miesiac = std::to_string(atoi(miesiac.c_str()) - 20);
        rok.insert(0, "20");
    }
    else if (miesiac[0] == '4' || miesiac[0] == '5')
    {
        miesiac = std::to_string(atoi(miesiac.c_str()) - 40);
        rok.insert(0, "21");
    }
    else if (miesiac[0] == '6' || miesiac[0] == '7')
    {
        miesiac = std::to_string(atoi(miesiac.c_str()) - 60);
        rok.insert(0, "22");
    }
    if (miesiac.size() == 1)
        miesiac.insert(0, "0");

    return dzien + "." + miesiac + "." + rok;
}

Polak::Polak(std::string imie, std::string nazwisko)
{
    this->imie = imie;
    this->nazwisko = nazwisko;
}

void Polak::ustawDateUrodzenia(std::string identyfikator)
{
    this->dataUrodzenia = Polak::uzyskajDateZPeselu(identyfikator);
}

std::string Polak::getKraj()
{
    return "Polska";
}

bool Polak::setIdentyfikator(std::string identyfikator)
{
    if (this->sprawdzIdentyfikator(identyfikator))
    {
        this->identyfikator = identyfikator;
        return true;
    }
    return false;
}

bool Polak::sprawdzIdentyfikator(std::string identyfikator)
{
    // walidacja numeru identyfikator - algorytm z wikipedii
    if (identyfikator.length() != 11)
    {
        return false;
    }

    int wagi[11] = { 1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1 };
    int suma = 0;

    for (int i = 0; i < 10; i++)
    {
        suma += ((int)identyfikator[i] - 48) * wagi[i];
    }
    int m = suma % 10;
    int kontrolna = ((int)identyfikator[10] - 48);

    if (m != 0 && 10 - m != kontrolna)
    {
        return false;
    }
    
    return true;
}

void Polak::wyswietlDane()
{
    std::cout << imie << " " << nazwisko << std::endl;
    std::cout << "Pesel: " << identyfikator << std::endl;
    std::cout << "Data urodzenia: " << dataUrodzenia << std::endl;
    std::cout << "KRAJ: PL" << std::endl;
}
