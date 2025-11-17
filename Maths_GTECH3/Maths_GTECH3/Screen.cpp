#include "Screen.h"
#include <iostream>
#include "Mesh.h"

void Screen::Initialize(int argc, char** argv)
{
	Params p = m_settings.ParseArguments(argc, argv);

	//m_mesh.setResolution(p.resolution);
}

void Screen::ComputeScreen()
{
	for (int i = 0; i < m_settings.getHeight(); i++)
	{
		for (int j = 0; j < m_settings.getWidth(); j++)
		{
			m_display.push_back('.');
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
    float height = m_settings.getHeight();
    float width = m_settings.getWidth();
    m_display.assign(height * width, '.');

    int cx = width / 2;
    int cy = height / 2;

    for (const auto& v : mesh.GetVertices())
    {
        int col = cx + static_cast<int>(v.x);
        int row = cy - static_cast<int>(v.y); // -v.y car ligne 0 = haut

        if (col >= 0 && col < width && row >= 0 && row < height)
        {
            m_display[row * width + col] = 'X';
        }
    }

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
            std::cout << m_display[row * width + col];
        std::cout << '\n';
    }
}




