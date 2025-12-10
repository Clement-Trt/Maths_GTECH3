//#include <iostream>
//#include <windows.h> // For console settings
//#include "Settings.h"
//#include "Screen.h"
//#include "Mesh.h"
//
//constexpr float PI = 3.14159265f;
//void InitConsole()
//{
//	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	DWORD mode;
//	GetConsoleMode(hConsole, &mode);
//	SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
//}
//
//void ClearConsole()
//{
//	std::cout << "\x1b[2J"; // Remove all characters in console
//	std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
//}
//
//void SetCursorVisible(bool visible)
//{
//	if (visible)
//	{
//		std::cout << "\x1b[?25h"; // Make cursor visible
//	}
//	else
//	{
//		std::cout << "\x1b[?25l"; // Make cursor invisible
//	}
//}
//
//int main(int argc, char** argv)
//{
//	InitConsole();
//	ClearConsole();
//	SetCursorVisible(false);
//	Settings settings(argc, argv);
//	Screen screen(settings);
//	screen.Display();
//	Mesh mesh(settings);
//	mesh.GenerateRectangle(10.f, 20.f);
//	std::cout << "Rectangle 10x20:" << std::endl;
//	screen.Display(mesh);
//	mesh.GenerateSquare(20.f);
//	mesh.Rotate(45, AXIS_Z);
//	std::cout << "Square 20x20:" << std::endl;
//	screen.Display(mesh);
//	mesh.GenerateCircle(15.f);
//	std::cout << "Circle radius 15:" << std::endl;
//	screen.Display(mesh);
//	mesh.GenerateHalfCircle(15.f);
//	mesh.Rotate(90, AXIS_Z);
//	std::cout << "Half Circle radius 15:" << std::endl;
//	screen.Display(mesh);
//	mesh.GenerateTorus(20.f, 1.f);
//	std::cout << "torus radius 15:" << std::endl;
//	mesh.Rotate(PI / 6, AXIS_X);
//	screen.Display(mesh);
//
//	//while (true)
//	//{
//	//	ClearConsole();
//
//	//	screen.Display(mesh);
//	//	Sleep(100);
//	//}
//
//
//
//
//	return 0;
//}


#define _USE_MATH_DEFINES

#include <iostream>
#include <windows.h> // For console settings
#include <cmath>
#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

void InitConsole()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hConsole, &mode);
    SetConsoleMode(hConsole, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ClearConsole()
{
    std::cout << "\x1b[2J"; // Remove all characters in console
    std::cout << "\x1b[H"; // Set cursor pos to "home" position (0,0)
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
    Settings settings(argc, argv);
    Screen screen(settings);
    Mesh mesh(settings);
    mesh.GenerateTorus(4.f, 0.9f);
    screen.Display(mesh);
    SetCursorVisible(true);

    while (true)
    {
        
        std::cout << "\x1b[H";
        mesh.GenerateTorus(4.f, 0.9f);
        mesh.Rotate(0.1, Axis::X);
        mesh.Rotate(0.1, Axis::Y);
        mesh.Rotate(0.1, Axis::Z);
        screen.Display(mesh);
    }

    return 0;
}