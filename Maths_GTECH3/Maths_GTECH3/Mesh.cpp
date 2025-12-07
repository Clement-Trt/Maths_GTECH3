#include "Mesh.h"
#include <iostream>
#include <cmath>

constexpr float PI = 3.14159265f;

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
		for (int j = 0; j < m_resolution - 1; j++)
		{
			Vertex v;/*
			v.x = (float)width * 0.5 * (((2.0 * j / (m_resolution - 1.0)) - 1)) ;
			v.y = (float)height * 0.5 * (((2.0 * i / (m_resolution - 1.0)) - 1)) ;*/
			v.x = ((float)width * 0.5 * (((2.0 * j / (m_resolution - 1.0)) - 1)) * eyePos) / zPos;
			v.y = ((float)height * 0.5 * (((2.0 * i / (m_resolution - 1.0)) - 1)) * eyePos) / zPos;
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
void Mesh::CreateTorus(float majorRadius, float minorRadius)
{
	m_resolution = 128;
	//for (int i = 0; i < m_resolution; i++)
	//{
	//	float phi = (2.f * PI * (float)i) / ((float)m_resolution - 1.f);
	//	for (int j = 0; j < m_resolution; j++)
	//	{
	//		float theta = (2.f * PI * (float)j) / ((float)m_resolution - 1.f);
	//		Vertex v{ 0,0,0 };
	//		v.x = (majorRadius + minorRadius * cos(theta)) * cos(phi);
	//		v.y = minorRadius * sin(phi);
	//		v.z = -(majorRadius + minorRadius * cos(theta)) * sin(phi);

	//		m_vertices.push_back(v);
	//	}
	//}
	for (int i = 0; i < m_resolution; i++)
	{
		float majorR = (2.f * PI * i) / (m_resolution - 1);

		for (int j = 0; j < m_resolution; j++)
		{
			float minorR = (2.f * PI * j) / (m_resolution - 1);

			float x = (majorRadius + minorRadius * cos(minorR)) * cos(majorR);
			float y = minorRadius * sin(minorR);
			float z = -(majorRadius + minorRadius * cos(minorR)) * sin(majorR);

			m_vertices.emplace_back( x, y, z );
			
			//AddVertex(x, y, z);
		}
	}

}


void Mesh::Rotate(float angle, Axis axis)
{
	for (auto& vert : m_vertices)
	{
		vert.Rotate(angle, axis);
	}
}

void Vertex::Rotate(float angle, Axis axis)
{

	float radAngle = PI * angle / 180.f;
	float newX = 0, newY = 0, newZ = 0;
	float co = cos(radAngle);
	float si = sin(radAngle);
	switch (axis)
	{
	case AXIS_X:
		newY = y * co - z * si;
		newZ = y * si + z * co;
		y = newY;
		z = newZ;
		break;
	case AXIS_Y:
		newX = z * si + x * co;
		newZ = z * co - x * si;
		x = newX;
		z = newZ;
		break;
	case AXIS_Z:
		newX = x * co - y * si;
		newY = x * si + y * co;
		x = newX;
		y = newY;
		break;
	default:
		break;
	}

}
