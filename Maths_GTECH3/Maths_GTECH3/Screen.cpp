#include "Screen.h"
#include <iostream>
#include "Mesh.h"

constexpr float PI = 3.14159265f;


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

	float m_screenPosition(0.f);
	float m_meshPosition(20.f);

	int centreX = width / 2;
	int centreY = height / 2;

	float moy = (width + height) / 2;

	m_screenPosition = moy * m_meshPosition * 3 / (8 * (4 + 0.9));

	// TEMPORAIRE
	Vec3 light = { 1,1,1 };

	for (Vertex v : mesh.GetVertices())
	{
		if (v.z == 0) continue;
		v.z += m_meshPosition;
		v.x = m_screenPosition * v.x / v.z;
		v.y = m_screenPosition * v.y / v.z;

		int col = centreX + std::round(v.x);
		int row = centreY - std::round(v.y) / 2; // -v.y car ligne 0 = haut, /2 car affichage déformé en Y par la console	

		if (col >= 0 && col < width && row >= 0 && row < height)
		{
			float ooz = 1 / v.z;
			int index = row * width + col;
			if (ooz < m_oozBuffer[index]) continue;
			m_oozBuffer[index] = ooz;


			float dist = std::sqrt(light.x * light.x + light.y * light.y + light.z * light.z);
			Vec3 normalLight = { light.x / dist, light.y / dist, light.z / dist };

			float prodScal = normalLight.x * v.normal.x + normalLight.y * v.normal.y + normalLight.z * v.normal.z;


			//., -~:; = !*#$@
			
			if (prodScal > 0.8)
				m_display[index] = '@';
			else if (prodScal > 0.5)
				m_display[index] = '#';
			else if (prodScal > 0.2)
				m_display[index] = '$';
			else if (prodScal > 0.0)
				m_display[index] = '£';
			else if (prodScal > -0.2)
				m_display[index] = '%';
			else if (prodScal > -0.5)
				m_display[index] = '/';
			else if (prodScal > -0.8)
				m_display[index] = ':';
			else
				m_display[index] = '.';
		}
	}

	for (int row = 0; row < height; row++)
	{
		for (int col = 0; col < width; col++)
			std::cout << m_display[row * width + col];
		std::cout << '\n';
	}
}




