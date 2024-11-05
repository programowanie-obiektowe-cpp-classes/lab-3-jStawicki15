#pragma once

#include "Stocznia.hpp"
#include <iostream>

unsigned int transportujFlota(unsigned int towar)
{
    unsigned int lŻaglowców = 0;
    unsigned int lTankowcow = 0;
    int remainingTowar = static_cast<int>(towar);
    int towarNaKurs = 0;
    Stocznia stocznia{};

    if(towar == 0)
    {
        std::cout<<"Brak towarow do przewiezienia\n";
        return 0;
    }
    else
    {
        std::cout<<"Towar do przewiezienia = "<<remainingTowar<<"\n";

        while(remainingTowar>0)
        {
            Statek* currentStatek = stocznia();
            towarNaKurs = currentStatek->transportuj();
            remainingTowar = remainingTowar - towarNaKurs;

            std::cout<<"Towar przewieziony kursem = "<<towarNaKurs<<"\tTowar pozostaly do przewiezienia = "<<remainingTowar<<"\n";

            if(dynamic_cast< Zaglowiec* >(currentStatek) != nullptr)
            {
                lŻaglowców++;
            }
            else
            {
                lTankowcow++;
            }
            
            delete currentStatek;
        }

        std::cout<<"Caly towar przewieziony!!!\n";
        std::cout<<"Liczba Zaglowcow = "<<lŻaglowców<<"\n"<<"Liczba Tankowcow = "<<lTankowcow<<"\n\n";
        return lŻaglowców;
    }

}