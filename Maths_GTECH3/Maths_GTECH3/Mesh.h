#pragma once
#include <vector>
#include "Light.h"

enum Axis
{
	AXIS_X,
	AXIS_Y,
	AXIS_Z
};

//struct Vec3
//{
//	float x, y, z;
//};

struct Vertex
{
	float x, y, z;

	Vec3 normal;

	Vertex() = default;
	Vertex(float _x, float _y, float _z, Vec3 n = { 0,0,0 })
	{
		x = _x;
		y = _y;
		z = _z;
		normal = n;
	}

	void debug();
	void Rotate(float angle, Axis axis);
	void RotateRad(float radAngle, Axis axis);
	float ComputeIllumination(Light& light);
};

class Mesh
{
private:

	union
	{
		float m_width, m_height;
		float m_r, m_radius;
		float m_majorR, m_minorR;
	};

	std::vector<Vertex> m_vertices;
	float m_resolution;

	Vec3 m_position;
public:

	Mesh(float resolution) : m_resolution(resolution), m_position({ 0,0,0 }) {}

	void debug();

	void setResolution(float resolution) { m_resolution = resolution; }

	std::vector<Vertex>& GetVertices() { return m_vertices; }

	Vec3 GetPosition() { return m_position; }
	void SetPosition(float x, float y, float z) { m_position.x = x; m_position.y = y; m_position.z = z; }
	void SetPosition(Vec3 v) { m_position.x = v.x; m_position.y = v.y; m_position.z = v.z; }

	void CreateRect(float width, float height);
	void CreateSquare(float size);
	void CreateCircle(float radius);
	void CreateSemiCircle(float radius);

	void CreateTorus(float majorRadius, float minorRadius);

	void CreateEmptySphere(float radius);

	void Rotate(float angle, Axis axis);

};

