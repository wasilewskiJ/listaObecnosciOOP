#ifndef FABRYKA_OSOB_H_
#define FABRYKA_OSOB_H_

#include <iostream>

#include "Polak.hpp"
#include "Portugalczyk.hpp"

class FabrykaOsob
{
public:
    Osoba *utworzOsobe(std::string kraj);
};

#endif