#pragma once
#include "Settings.h"
//#include "Mesh.h"
#include <vector>

class Mesh;

class Screen
{
private:

	Settings m_settings;
	std::vector<char> m_display;

public:

	//Screen();

	Settings& GetSettings() { return m_settings; }

	void Initialize(int argc, char** argv);
	void ComputeScreen();
	void Display();

	void DisplayMesh(Mesh& mesh);



};

