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

void Mesh::CreateRect(float width, float height)
{
	m_vertices.clear();

	//int zPos = 1;
	int zPos = 10;
	//int eyePos = 0;
	int eyePos = 5;

	for (int i = m_resolution - 1; i >= 0; i--)
	{
		for (int j = 0; j < m_resolution; j++)
		{
			Vertex v;/*
			v.x = (float)width * 0.5 * (((2.0 * j / (m_resolution - 1.0)) - 1)) ;
			v.y = (float)height * 0.5 * (((2.0 * i / (m_resolution - 1.0)) - 1)) ;*/
			v.x = ((float)width * 0.5 * (((2.0 * j / (m_resolution - 1.0)) - 1)) * 1 * eyePos) / zPos;
			v.y = ((float)height * 0.5 * (((2.0 * i / (m_resolution - 1.0)) - 1)) * 1 * eyePos) / zPos;
			v.z = 0;
			m_vertices.push_back(v);
		}
	}
}

void Mesh::CreateSquare(float size)
{
	CreateRect(size, size);
}

void Mesh::CreateCircle(float radius)
{
	m_vertices.clear();



	// On parcourt la zone [-radius, radius] avec un pas défini par la résolution
	for (int i = 0; i < m_resolution; i++)
	{
		float y = -radius + 2.0f * radius * i / (m_resolution - 1); // y de -radius à +radius

		for (int j = 0; j < m_resolution; j++)
		{
			float x = -radius + 2.0f * radius * j / (m_resolution - 1); // x de -radius à +radius

			if (x * x + y * y <= radius * radius)
			{
				Vertex v;
				v.x = x;
				v.y = y;
				v.z = 0;
				m_vertices.push_back(v);
			}
		}
	}
}

void Mesh::CreateSemiCircle(float radius)
{

	m_vertices.clear();

	// On parcourt la zone [-radius, radius] avec un pas défini par la résolution
	for (int i = 0; i < m_resolution; i++)
	{
		float y = -radius + 2.0f * radius * i / (m_resolution - 1); // y de -radius à +radius

		for (int j = 0; j < m_resolution; j++)
		{
			float x = -radius + 2.0f * radius * j / (m_resolution - 1); // x de -radius à +radius

			if (y >= 0 && x * x + y * y <= radius * radius)
			{
				Vertex v;
				v.x = x;
				v.y = y;
				v.z = 0;
				m_vertices.push_back(v);
			}
		}
	}
}
