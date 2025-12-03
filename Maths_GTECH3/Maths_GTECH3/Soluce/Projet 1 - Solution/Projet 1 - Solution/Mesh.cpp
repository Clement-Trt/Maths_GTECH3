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
	for (auto vert : m_vertices)
	{
		vert.Rotate(angle, axis);
	}
}

void Vertex::Rotate(float angle, Axis axis)
{

	float radAngle = PI * angle / 180.f;
	//float dist = std::sqrt(x * x + y * y);
	float newX, newY, newZ;
	float co = cos(radAngle);
	float si = sin(radAngle);
	switch (axis)
	{
	case AXIS_X:
		newY = y * co - z * si;
		newZ = y * si + z * co;
		break;
	caseY:
		newX = z * si + x * co;
		newZ = z * co - x * si;
		break;
	case AXIS_Z:
		newX = x * co - y * si;
		newY = x * si + y * co;
		break;
	default:
		break;
	}
	x = newX;
	y = newY;
	z = newZ;

}
