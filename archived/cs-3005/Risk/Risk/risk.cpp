#include "risk.h"
#include <cstdlib>
#include <iostream>


int roll_die(const int sides)
{
    if (sides < 0)
    {
        return -1;
    }
    //std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = std::rand() % sides + 1;
    //std::cout << random_variable << '\n';
    return random_variable;
}

void sort_int_dsc(int a[], const int size)
{
    bool swapped = true;
    int j = 0;
    int tmp;
    int i;
    while (swapped) {
        swapped = false;
        j++;
        for (i = 0; i < size - j; i++) {
            if (a[i] < a[i + 1]) {
                tmp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}

void roll_player(int rolls[], const int ndice)
{
    int i;
    for (i = 0; i < ndice; i++)
    {
        rolls[i] = roll_die(6);
    }
//    std::cout << "Original: " << rolls[0] << '\n';
    sort_int_dsc(rolls, ndice);
//    std::cout << "Sorted: " << rolls[0] << '\n';
}

int handle_battle(const int nattack, const int ndefend)
{
    int attack[nattack];
    int defend[ndefend];
    int def_losses = 0;
    int i;
    if (nattack > 3 || ndefend > 2)
    {
        return -1;
    }
    roll_player(attack, nattack);
    roll_player(defend, ndefend);
    
    for (i = 0; i < ndefend; i++ )
    {
//        std::cout << "Roll[" << i << "]: \n";
//        std::cout << "Attack[" << i << "]: " << attack[i] << '\n';
//        std::cout << "Defend[" << i << "]: " << defend[i] << '\n';

        if (attack[i] > defend[i])
        {
            def_losses += 1;
        }
    }
//    std::cout << "Losses: " << def_losses << '\n';
    return def_losses;
}

double win_chances(const int nattack, const int ndefend, const int nbattles)
{
    int i;
    int def_losses = 0;
    int total_def_losses = 0;
    int total_losses = 0;
    double chances;
    for (i = 0; i < nbattles; i++)
    {
        def_losses = handle_battle(nattack, ndefend);
        if (def_losses < 0)
        {
            return -1;
        }
        total_def_losses += def_losses;
        if (nattack >= ndefend)
        {
            total_losses += ndefend;
        }
        else
        {
            total_losses += nattack;
        }
    }
    chances = (double)total_def_losses / total_losses;
    return chances;
}
