#pragma once
#include "Settings.h"
#include "Light.h"
//#include "Mesh.h"
#include <vector>

class Mesh;

class Screen
{
private:

	Settings m_settings;
	Light m_light;
	std::vector<char> m_display;
	std::vector<float> m_oozBuffer;

public:

	//Screen();

	Settings& GetSettings() { return m_settings; }

	void Initialize(int argc, char** argv);
	void ComputeScreen();
	void Display();

	void DisplayMesh(Mesh& mesh);



};

