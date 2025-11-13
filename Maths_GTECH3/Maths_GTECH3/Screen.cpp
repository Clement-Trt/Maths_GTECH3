#include "Screen.h"
#include <iostream>

void Screen::Initialize(int argc, char** argv)
{
	Params p = m_settings.initWindowSize(argc, argv);

	m_mesh.setResolution(p.resolution);
}

void Screen::ComputeScreen()
{


	//for (int i = 0; i < (m_settings.getHeight() / m_settings.getResolution()); i++)
	for (int i = 0; i < m_settings.getHeight(); i++)
	{
		for (int j = 0; j < m_settings.getWidth(); j++)
		{
			m_display.push_back('.');
		}
		m_display.push_back('\n');
	}
	/*auto res = m_settings.getResolution();

	for (auto vertex : m_mesh.GetVertices())
	{

	}
	m_display.push_back('\n');*/
}

void Screen::Display()
{
	for (int i = 0; i < m_display.size(); i++)
	{
		std::cout << m_display[i];
	}
}
void Screen::CreateRect(int width, int height)
{
	m_mesh.CreateRect(width, height);
}

