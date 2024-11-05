#pragma once

#include "Stocznia.hpp"
#include <iostream>

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int lŻaglowców = 0;
    unsigned int remainingTowar = towar;
    unsigned int towarNaKurs = 0;
    Stocznia stocznia{};

    if(towar == 0)
    {
        std::cout<<"Brak towarow do przewiezienia";
        return 0;
    }
    else
    {
        while(remainingTowar>0)
        {
            Statek* currentStatek = stocznia();
            towarNaKurs = currentStatek->transportuj();
            remainingTowar = remainingTowar - towarNaKurs;

            if(dynamic_cast< Zaglowiec* >(currentStatek) != nullptr)
                lŻaglowców++;
            
            delete currentStatek;
        }

        std::cout<<"Caly towar przewieziony";
        return lŻaglowców;
    }

}