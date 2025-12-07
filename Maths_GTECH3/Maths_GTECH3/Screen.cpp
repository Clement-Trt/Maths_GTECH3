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


void Screen::DisplayMesh(Mesh& mesh)
{
	int height = m_settings.getHeight();
	int width = m_settings.getWidth();
	m_display.assign(height * width, m_settings.getBackgroundChar());
	m_oozBuffer.assign(height * width, -1);


	int centreX = width / 2;
	int centreY = height / 2;

	for (const Vertex& v : mesh.GetVertices())
	{
		int col = centreX + std::round(v.x);
		int row = centreY - std::round(v.y) / 2; // -v.y car ligne 0 = haut

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


	//float meshPositonZ = 5;
	//float viewPositionZ = 3.33f;

	//int size = width * height;

	//for (Vertex vertex : mesh.GetVertices())
	//{

	//	float y_prime = (vertex.y * viewPositionZ) / meshPositonZ;
	//	float x_prime = (vertex.x * viewPositionZ) / meshPositonZ;

	//	y_prime /= 2.0f;

	//	x_prime += centreX;
	//	y_prime += centreY;

	//	int u = round(x_prime);
	//	int v = round(y_prime);

	//	int index = width * v + u;

	//	float ooz = 1.f / vertex.z;

	//	if (ooz < m_oozBuffer[index]) continue;
	//	if (index < 0 || index >= size) continue;

	//	m_display[index] = m_settings.getMeshProjChar();
	//	m_oozBuffer[index] = ooz;
	//}

	//for (int i = 0; i < size; ++i)
	//{
	//	std::cout << m_display[i];

	//	if ((i + 1) % width == 0)
	//		std::cout << std::endl;
	//}
}




