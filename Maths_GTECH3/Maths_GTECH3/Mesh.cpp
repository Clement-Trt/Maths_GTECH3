#include "Mesh.h"
#include <iostream>

void Vertex::debug()
{
	std::cout << " x = " << x << " y = " << y << " z = " << z << std::end;
}

void Mesh::debug()
{
		std::cout << " Mesh contains : " << std::endl;
	//for (auto vertex : m_vertices)
	for (int i = 0; i < m_vertices.size(); i++)
	{
		std::cout << " Vertex " << i << " :" << std::endl;
	}
}

