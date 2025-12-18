#pragma once

struct Vec3
{
	float x, y, z;
};

class Light
{
private:
	float m_dirX, m_dirY, m_dirZ;

public:
	Light(float dirX = 1, float dirY = 1, float dirZ = 1);

	void SetLightDir(float dirX, float dirY, float dirZ) { m_dirX = dirX; m_dirY = dirY; m_dirZ = dirZ; }
	void SetLightDir(Vec3 dir) { m_dirX = dir.x; m_dirY = dir.y; m_dirZ = dir.z; }

	Vec3 GetLightDir() { return { m_dirX, m_dirY, m_dirZ }; }

private:

};

