#pragma once

#include <string>

struct Params
{
	float width;
	float height;
	float resolution;
};

class Settings
{
private:
	float m_width;
	float m_height;

	float m_resolution;

public:
	Settings() : m_height(20), m_width(100), m_resolution(32) {}

	Params ParseArguments(int argc, char** argv);

	int getHeight()& { return m_height; }
	int getWidth()& { return m_width; }
	int getResolution()& { return m_resolution; }

};

