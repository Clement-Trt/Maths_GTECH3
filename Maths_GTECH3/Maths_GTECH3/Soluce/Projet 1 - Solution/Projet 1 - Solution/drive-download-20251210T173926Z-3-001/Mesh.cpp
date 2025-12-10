#define _USE_MATH_DEFINES

#include <cmath>
#include "Mesh.h"
#include "Settings.h"

void Vertex::Rotate(float angle, Axis axis)
{
    Vertex previous = *this;
    switch(axis)
    {
        case Axis::X:
        {
            y = previous.y * std::cos(angle) - previous.z * std::sin(angle);
            z = previous.y * std::sin(angle) + previous.z * std::cos(angle);
        }
        break;
        case Axis::Y:
        {
            x = previous.z * std::sin(angle) + previous.x * std::cos(angle);
            z = previous.z * std::cos(angle) - previous.x * std::sin(angle);
        }
        break;
        case Axis::Z:
        {
            x = previous.x * std::cos(angle) - previous.y * std::sin(angle);
            y = previous.x * std::sin(angle) + previous.y * std::cos(angle);
        }
        break;
    }
}

Mesh::Mesh(Settings const& settings)
: m_resolution(settings.GetMeshResolution())
{
}

void Mesh::GenerateCircle(float radius)
{
    _GenerateSector(radius, 2 * M_PI);
}

void Mesh::GenerateHalfCircle(float radius)
{
    _GenerateSector(radius, M_PI);
}

void Mesh::GenerateRectangle(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        for(int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f*i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f*j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}

void Mesh::GenerateSquare(float side)
{
    GenerateRectangle(side, side);
}

void Mesh::GenerateTorus(float majorRadius, float minorRadius)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float angleY = (2 * M_PI * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float angleZ = (2 * M_PI * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = majorRadius + minorRadius * std::cos(angleZ);
            m_vertices[m_resolution * i + j].y = minorRadius * std::sin(angleZ);
            m_vertices[m_resolution * i + j].Rotate(angleY, Axis::Y);
        }
    }
}

void Mesh::Rotate(float angle, Axis axis)
{
    for(Vertex& vertex : m_vertices)
    {
        vertex.Rotate(angle, axis);
    }
}

void Mesh::Debug() const
{
    for(Vertex const& vertex : m_vertices)
    {
        vertex.Debug();
    }
}

void Mesh::_GenerateSector(float radius, float angle)
{
    m_vertices.resize(m_resolution * m_resolution);
    for(int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for(int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = r * std::cos(theta);
            m_vertices[m_resolution * i + j].y = r * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
}