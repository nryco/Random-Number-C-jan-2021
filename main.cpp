// Code made with the help of @42prisme 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <sstream>

int start()
{
    std::cout << "[Ordinateur]: Je pense à un chiffre entre 0 et 9 essaye de deviner !" << std::endl ;
    int hour = time(NULL);
    srand(hour);
    return 0;
}

int numero()
{
    const int MIN = 0, MAX = 9;
    return (rand() % (MAX - MIN + 1)) + MIN;
}

bool reflexion(int *inputvalue,int unknown) 
{

    if (*inputvalue == unknown)
    {
        std::cout << "Bien joué tu as trouvé le numéro! "  << "Le numéro était le numéro " << unknown << "!" << std::endl;
        return true; 
    }
    else 
    {
        std::cout << "Non, ce n'est pas ça le numéro " << *inputvalue <<"! " "Essaye un autre chiffre!" << std::endl;
        return false; 
    }
}

int yournumber(int *inputvalue, int unknown)
{
    std::string line;
    double d;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        if (ss >> *inputvalue)
        {
            if (ss.eof())
            {   // Success
                break;
            }
        }
        std::cout << "Caractère Invalide!" << std::endl;
    }

    if (*inputvalue >= 0 && *inputvalue <= 9)
    {

        return 1;
    }
    else
    { 
        std::cout << "Numéro Invalide !" << std::endl << "Le numéro " << *inputvalue << " est invalide!" << std::endl;
        yournumber(inputvalue, unknown); 
        return -1;
    }
}      

int main() 
{
    start();
    bool programm = false;
    int inputvalue = 0;
    int unknown = numero();
    while (programm == false)
    {
        yournumber(&inputvalue, unknown);
        programm = reflexion(&inputvalue, unknown);
    }

    return 0;
}
