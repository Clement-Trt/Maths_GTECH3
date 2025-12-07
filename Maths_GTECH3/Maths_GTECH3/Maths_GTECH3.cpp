// Maths_GTECH3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <windows.h>

#include "Screen.h"
#include "Mesh.h"


void InitConsole() // Pas forcement necessaire, depend du compilateur
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console (scroll down)
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void Space()
{
    std::cout << "\n-\n"; 
}

void SetCursorVisible(bool visible)
{
    if (visible)
    {
        std::cout << "\x1b[?25h"; // Make cursor visible
    }
    else
    {
        std::cout << "\x1b[?25l"; // Make cursor invisible
    }
}

int main(int argc, char** argv)
{
    InitConsole();

    ClearConsole();
    SetCursorVisible(false);

    Screen screen;
    screen.Initialize(argc, argv);
    screen.Display();

    Space();
    Mesh rect(32);
    rect.CreateRect(20, 20);
    screen.DisplayMesh(rect);

    Space();
    ClearConsole();
    Mesh cric(32);
    cric.CreateCircle(12);
    screen.DisplayMesh(cric);

    Space();
    ClearConsole();
    Mesh halfCirc(32);
    halfCirc.CreateSemiCircle(9);
    //halfCirc.debug();
    screen.DisplayMesh(halfCirc);

    Space();
    ClearConsole();
    Mesh torus(32);
    torus.CreateTorus(15.f,5.f);
    screen.DisplayMesh(torus);


    while (true)
    {
    Space();
    ClearConsole();
        torus.Rotate(1, AXIS_X);
        torus.Rotate(1, AXIS_Z);
    screen.DisplayMesh(torus);
    }

    return 0;
}