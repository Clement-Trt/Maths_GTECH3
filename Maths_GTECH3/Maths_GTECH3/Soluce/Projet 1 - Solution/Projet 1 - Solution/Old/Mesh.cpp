#include <cmath>
#include "Mesh.h"
#include "Settings.h"

constexpr float PI = 3.14159265f;

Mesh::Mesh(Settings const& settings)
	: m_resolution(settings.GetMeshResolution())
{
}

void Mesh::GenerateCircle(float radius)
{
	_GenerateSector(radius, 2 * PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
	_GenerateSector(radius, PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
	m_vertices.resize(m_resolution * m_resolution);
	for (int i = 0; i < m_resolution; i++)
	{
		for (int j = 0; j < m_resolution; j++)
		{
			m_vertices[m_resolution * i + j].x = (1.f * i / (m_resolution - 1) - 0.5f) * width;
			m_vertices[m_resolution * i + j].y = (1.f * j / (m_resolution - 1) - 0.5f) * height;
			m_vertices[m_resolution * i + j].z = 0.f;
		}
	}
}
void Mesh::GenerateSquare(float side)
{
	GenerateRectangle(side, side);
}

//void Mesh::GenerateTorus(float majorRadius, float minorRadius)
//{
//	//m_vertices.resize(m_resolution * m_resolution * m_resolution);
//
//
//	//for (int k = 0; k < m_resolution; k++)
//	//{
//	//	for (int i = 0; i < m_resolution; i++)
//	//	{
//	//		for (int j = 0; j < m_resolution; j++)
//	//		{
//	//			float theta = (2 * PI * j) / (m_resolution - 1);
//	//			m_vertices[m_resolution * i + j].x = majorRadius * std::cos(theta) + minorRadius;
//	//			m_vertices[m_resolution * i + j].y = majorRadius * std::sin(theta) + minorRadius;
//	//			m_vertices[m_resolution * i + j].z = 0.f;
//	//		}
//	//	}
//	//}
//
//	m_resolution *= 10;
//
//	m_vertices.resize(m_resolution * m_resolution);
//
//	for (int i = 0; i < m_resolution; i++)   // angle minor
//	{
//		float phi = (2.0f * PI * i) / (m_resolution - 1);
//
//		for (int j = 0; j < m_resolution; j++)   // angle major
//		{
//			float theta = (2.0f * PI * j) / (m_resolution - 1);
//
//			float x = (majorRadius + minorRadius * std::cos(phi)) * std::cos(theta);
//			float y = (majorRadius + minorRadius * std::cos(phi)) * std::sin(theta);
//			float z = minorRadius * std::sin(phi);
//
//			m_vertices[i * m_resolution + j] = { x, y, z };
//		}
//	}
//
//}
void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
	int res = m_resolution;
	res *= 2;

	m_vertices.clear();
	//m_vertices.resize(res * res);
	m_vertices.resize(res * res * res);

	//for (int i = 0; i < res; ++i) // theta : autour du tube
	//{
	//	float theta = 2.0f * PI * (float)i / (float)res;
	//	float cosTheta = std::cos(theta);
	//	float sinTheta = std::sin(theta);

	//	for (int j = 0; j < res; ++j) // phi : autour du donut
	//	{
	//		float phi = 2.0f * PI * (float)j / (float)res;
	//		float cosPhi = std::cos(phi);
	//		float sinPhi = std::sin(phi);

	//		float cx = majorRadius + minorRadius * cosTheta; // R2 + R1 cos(theta)

	//		float x = cx * cosPhi;       // (R2 + R1 cos(theta)) cos(phi)
	//		float y = minorRadius * sinTheta; // R1 sin(theta)
	//		float z = -cx * sinPhi;       // -(R2 + R1 cos(theta)) sin(phi)

	//		int index = i * res + j;
	//		m_vertices[index].x = x;
	//		m_vertices[index].y = y;
	//		m_vertices[index].z = z;
	//	}
	//}

	// //EN COURS CI DESSOUS
	for (int k = 0; k < res; k++)
	{
		float phi = (2 * PI * k) / (res - 1);

		for (int i = 0; i < res; i++)
		{
			//float theta = PI - (2.0f * PI * i) / ((float)res - 1);
			for (int j = 0; j < res; j++)
			{
				float theta = (2 * PI * j) / (m_resolution - 1);

				/*float x = (minorRadius * std::cos(theta) + majorRadius) * cos(phi);
				float y = (minorRadius * std::sin(theta) + majorRadius) * sin(phi);
				float z = minorRadius * sin(theta);*/
				float x = (minorRadius * std::cos(theta) + majorRadius) * cos(phi);
				//float y = -(minorRadius * std::cos(theta) + majorRadius) * sin(phi);
				//float z = minorRadius * sin(theta);
				float z = -(minorRadius * std::cos(theta) + majorRadius) * sin(phi);
				float y = minorRadius * sin(theta);

				int index = k * res + i * res + j;
				m_vertices[index].x = x;
				m_vertices[index].y = y;
				m_vertices[index].z = z;
				//m_vertices.emplace_back(Vertex{ x, y, z });
			}
		}
	}

	//for (float i = 0; i < m_resolution; i++)
	//{
	//	float majorR = (2.f * PI * i) / ((float)m_resolution - 1);
	//	for (int j = 0; j < m_resolution; j++)
	//	{
	//		float minorR = PI - (2.0f * PI * j) / ((float)m_resolution - 1);
	//		for (int k = 0; k < m_resolution; k++)
	//		{
	//			float x = (majorRadius + minorRadius * cos(minorR)) * cos(majorR);
	//			float y = (majorRadius + minorRadius * sin(minorR)) * sin(majorR);
	//			float z = minorR * sin(minorR);
	//			m_vertices.emplace_back(Vertex{ x, y, z });
	//		}
	//	}
	//}



	//int res = m_resolution;
	//m_vertices.resize(res * res);

	//for (int i = 0; i < res; i++)
	//{
	//	// Petit cercle (tube) dans le plan XY
	//	float theta = (2.0f * PI * i) / (res - 1);
	//	float xCircle = minorRadius * std::cos(theta);
	//	float yCircle = minorRadius * std::sin(theta);
	//	float xShift = majorRadius + xCircle; // distance à l'axe Y

	//	for (int j = 0; j < res; j++)
	//	{
	//		// Rotation de ce cercle autour de l'axe Y
	//		float phi = (2.0f * PI * j) / (res - 1);
	//		float cosPhi = std::cos(phi);
	//		float sinPhi = std::sin(phi);

	//		float X = xShift * cosPhi;
	//		float Z = -xShift * sinPhi; // le signe détermine juste le sens de rotation
	//		float Y = yCircle;

	//		int index = i * res + j;
	//		m_vertices[index].x = X;
	//		m_vertices[index].y = Y;
	//		m_vertices[index].z = Z;
	//	}
	//}
}
void Mesh::Debug() const
{
	for (Vertex const& vertex : m_vertices)
	{
		vertex.Debug();
	}
}

void Mesh::_GenerateSector(float radius, float angle)
{
	m_vertices.resize(m_resolution * m_resolution);
	for (int i = 0; i < m_resolution; i++)
	{
		float r = (radius * i) / (m_resolution - 1);
		for (int j = 0; j < m_resolution; j++)
		{
			float theta = (angle * j) / (m_resolution - 1);
			m_vertices[m_resolution * i + j].x = r * std::cos(theta);
			m_vertices[m_resolution * i + j].y = r * std::sin(theta);
			m_vertices[m_resolution * i + j].z = 0.f;
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
