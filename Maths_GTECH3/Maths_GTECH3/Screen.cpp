#include "Screen.h"
#include <iostream>
#include "Mesh.h"



void Screen::Initialize(int argc, char** argv)
{
	Params p = m_settings.ParseArguments(argc, argv);
	ComputeScreen();
	//m_mesh.setResolution(p.resolution);
}

void Screen::ComputeScreen()
{
	for (int i = 0; i < m_settings.getHeight(); i++)
	{
		for (int j = 0; j < m_settings.getWidth(); j++)
		{
			m_display.push_back(m_settings.getBackgroundChar());
		}
		m_display.push_back('\n');
	}
}

void Screen::Display()
{
	//if(m_mesh.GetVertices().empty())
	//{
	//	for (int i = 0; i < m_display.size(); i++)
	//	{
	//		std::cout << m_display[i];
	//	}
	//}
	//else
	//{


	//}
}

// QUESTIONS : pourquoi z += m_meshPosition; pareil que z -= m_meshPosition; et surtout pourquoi le centre de roation semble avoir bougé en utilisant la perspective ??
void Screen::DisplayMesh(Mesh& mesh)
{
	int height = m_settings.getHeight();
	int width = m_settings.getWidth();
	m_display.assign(height * width, m_settings.getBackgroundChar());
	m_oozBuffer.assign(height * width, -1);

	float m_screenPosition(3.33f);
	//float m_screenPosition(30.f);
	float m_meshPosition(5.f);
	float m_meshPositionY(5.f);
	float m_meshPositionX(25.f);
	//float m_meshPosition(35.f);

	int centreX = width / 2;
	int centreY = height / 2;


	for (Vertex v : mesh.GetVertices())
	{
		v.z -= m_meshPosition;
		v.x = m_screenPosition * v.x / m_meshPosition + m_meshPositionX;
		v.y = m_screenPosition * v.y / m_meshPosition + m_meshPositionY;

		int col = centreX + std::round(v.x);
		int row = centreY - std::round(v.y) / 2; // -v.y car ligne 0 = haut, /2 car affichage déformé en Y par la console	

		if (col >= 0 && col < width && row >= 0 && row < height)
		{
			float ooz = 1 / v.z;
			int index = row * width + col;
			if (ooz < m_oozBuffer[index]) continue;
			m_oozBuffer[index] = ooz;
			m_display[index] = 'X';
		}
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
			std::cout << m_display[row * width + col];
		std::cout << '\n';
	}
}




