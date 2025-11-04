// Maths_GTECH3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <windows.h>

#include <thread>
#include <chrono>

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";


    {   // Pas forcement necessaire, depend du compilateur
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hConsole, &mode);
        SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }


    std::cout << "\x1b[2J";
    std::cout << "bob\n";

    std::cout << "\x1b[?25l";

    std::cout << "Le curseur est cache pendant 3 secondes...\n";
    //std::this_thread::sleep_for(std::chrono::seconds(3));

    // Réafficher le curseur
    std::cout << "\x1b[?25h";
    std::cout << "Curseur reactive.\n";

    std::string a;
    std::cin >> a;

    std::cout << "\x1b[H\x1b[n";
    std::cout << "bob2_ ";

    return 0;
}

