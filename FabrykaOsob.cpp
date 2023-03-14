#include "headers/FabrykaOsob.hpp"

Osoba *FabrykaOsob::utworzOsobe(std::string kraj)
{
    Osoba *nowaOsoba = nullptr;
    if(kraj == "PL")
    {
        nowaOsoba = new Polak();
    }
    if(kraj == "PT")
    {
        nowaOsoba = new Portugalczyk();
    }
    return nowaOsoba;
}
