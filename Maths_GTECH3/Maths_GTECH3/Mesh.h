#pragma once
#include <vector>

struct Vertex
{
	float x, y, z;

	void debug();
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


};

