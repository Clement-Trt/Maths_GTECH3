// Maths_GTECH3.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <windows.h>

#include "Screen.h"
#include "Mesh.h"


void InitConsole(int width, int height) // Pas forcement necessaire, depend du compilateur
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hConsole == INVALID_HANDLE_VALUE)
		return;

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
}

void ClearConsole()
{
	std::cout << "\x1b[2J"; // Remove all characters in console (scroll down)
}

void SetHomePosition()
{
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
	InitConsole(150, 50);

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
	Mesh torus(256);
	torus.CreateTorus(4.f, 0.9f);
	//torus.CreateTorus(8.f,2.f);
	screen.DisplayMesh(torus);


	//while (true)
	//{
	//Space();
	//Space();
	//Space();
	//SetHomePosition();
	//    //torus.Rotate(5, AXIS_X);
	//    torus.Rotate(20, AXIS_Y);
	//    torus.Rotate(15, AXIS_Z);
	//screen.DisplayMesh(torus);
	//}

	Space();
	ClearConsole();
	Mesh sphere(256);
	sphere.CreateEmptySphere(4.f);
	screen.DisplayMesh(sphere);

	Vertex dynamicLight{ 1,1,1 };

	bool up = false;

	while (true)
	{
		SetHomePosition();

		// Dynamic Light
		screen.SetLight(dynamicLight);
		dynamicLight.Rotate(5, AXIS_Y);

		// Movement Sphere
		if (sphere.GetPosition().x > 20 || sphere.GetPosition().x < -20)
			up = !up;
		if (up)
			sphere.SetPosition(sphere.GetPosition().x + 1, sphere.GetPosition().y + 1, sphere.GetPosition().z + 0.2);
		else
			sphere.SetPosition(sphere.GetPosition().x - 1, sphere.GetPosition().y - 1, sphere.GetPosition().z - 0.2);

		//torus.Rotate(5, AXIS_X);
		//sphere.Rotate(20, AXIS_Y);
		//sphere.Rotate(15, AXIS_Z);
		screen.DisplayMesh(sphere);
	}

	return 0;
}