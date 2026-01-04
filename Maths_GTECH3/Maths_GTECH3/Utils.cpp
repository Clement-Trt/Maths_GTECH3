#include "Utils.h"

#include <iostream>
#include <windows.h>

void Utils::InitConsole(int width, int height)
{
    // 0) Initialisation console
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    // 1) Taille du buffer
    COORD bufferSize;
    bufferSize.X = width;
    bufferSize.Y = height;

    if (!SetConsoleScreenBufferSize(hConsole, bufferSize))
    {
        std::cerr << "Erreur SetConsoleScreenBufferSize\n";
        return;
    }

    // 2) Taille de la fenêtre
    SMALL_RECT windowRect;
    windowRect.Left = 0;
    windowRect.Top = 0;
    windowRect.Right = width - 1;
    windowRect.Bottom = height - 1;

    if (!SetConsoleWindowInfo(hConsole, TRUE, &windowRect))
    {
        std::cerr << "Erreur SetConsoleWindowInfo\n";
        return;
    }

    ClearConsole();
    SetCursorVisible(false);
}

void Utils::SetCursorToHomePosition()
{
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
}

void Utils::ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    SetCursorToHomePosition();
}

void Utils::SetCursorVisible(bool visible)
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

void Utils::OnKill(int signum)
{
    ClearConsole();
    SetCursorVisible(true);
    exit(signum);
}

void Utils::SetColor(Color color)
{
    switch (color)
    {
    case Utils::Red:
        std::cout << "\x1b[91m";
        break;
    case Utils::Blue:
        std::cout << "\x1b[92m";
        break;
    case Utils::Yellow:
        std::cout << "\x1b[93m";
        break;
    case Utils::Green:
        std::cout << "\x1b[32m";
        break;
    case Utils::White:
        std::cout << "\x1b[37m";
        break;
    default:
        std::cout << "\x1b[37m";
        break;
    }
}
