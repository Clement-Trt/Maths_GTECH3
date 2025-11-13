#include "Mesh.h"
#include <iostream>

void Vertex::debug()
{
	std::cout << " x = " << x << " y = " << y << " z = " << z << std::endl;
}

void Mesh::debug()
{
		std::cout << " Mesh contains : " << std::endl;
	//for (auto vertex : m_vertices)
	for (int i = 0; i < m_vertices.size(); i++)
	{
		std::cout << " Vertex " << i << " :"; 
		m_vertices[i].debug();
	}
}

void Mesh::CreateRect(int width, int height)
{
	for (int i = 0; i < m_resolution - 1; i++)
	{
		for (int j = 0; j < m_resolution - 1; j++)
		{
			Vertex v;
			v.x = width * ((2 * i / m_resolution - 1) * 0.5);
			v.y = height * ((2 * j / m_resolution - 1) * 0.5);
			v.z = 0;
			m_vertices.push_back(v);
		}
	}
}

