#pragma once
#include <vector>

struct Vertex
{
	int x, y, z;

	void debug();
};

class Mesh
{
private:
	std::vector<Vertex> m_vertices;
	int m_resolution;
public:

	void debug();

	void setResolution(int resolution) { m_resolution = resolution; }
};

