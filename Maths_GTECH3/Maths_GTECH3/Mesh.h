#pragma once
#include <vector>

enum Axis
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

struct Vertex
{
	float x, y, z;
	Vertex() = default;
	Vertex(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void debug();
	void Rotate(float angle, Axis axis);
};

class Mesh
{
private:
	std::vector<Vertex> m_vertices;
	float m_resolution;
public:

	Mesh(float resolution) : m_resolution(resolution) {}

	void debug();

	void setResolution(float resolution) { m_resolution = resolution; }

	std::vector<Vertex>& GetVertices() { return m_vertices; }

	void CreateRect(float width, float height);
	void CreateSquare(float size);
	void CreateCircle(float radius);
	void CreateSemiCircle(float radius);

	void CreateTorus(float majorRadius, float minorRadius);

	void Rotate(float angle, Axis axis);

};

