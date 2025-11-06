// Maths_GTECH3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <windows.h>
#include <vector>

//int main(int argc, char** argv)
//{
//    std::cout << "Hello World!\n";
//
//
//    {   // Pas forcement necessaire, depend du compilateur
//        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//        DWORD mode;
//        GetConsoleMode(hConsole, &mode);
//        SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
//    }
//
//    // "clear" cmd (scroll vers le bas)
//    std::cout << "\x1b[2J";
//    std::cout << "bob\n";
//
//    // cacher curseur
//    std::cout << "\x1b[?25l";
//
//    std::cout << "Le curseur est cache ...\n";
//
//    // Réafficher le curseur
//    std::cout << "\x1b[?25h";
//    std::cout << "Curseur reactive.\n";
//
//    // clear (scroll)
//    std::cout << "\x1b[2J";
//
//   
//    std::cout << "lalalalalal\n nanana ";
//    std::cout << "\x1b[H\x1b[n"; // remonte le cuseur + overwrite
//    std::cout << "bob2_ ";
//
//    return 0;
//}
#include "Settings.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World!\n";


    {   // Pas forcement necessaire, depend du compilateur
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        DWORD mode;
        GetConsoleMode(hConsole, &mode);
        SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    }

    // "clear" cmd (scroll vers le bas)
    std::cout << "\x1b[2J";

    // Default size settings

    Settings param;

    param.initWindowSize(argc, argv);

    int width = param.getWidth();
    int height = param.getHeight();


    std::vector<char> vec;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            vec.push_back('.');
        }
            vec.push_back('\n');
    }

    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
    }

    return 0;
}