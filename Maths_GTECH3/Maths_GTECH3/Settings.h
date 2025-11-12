#pragma once

#include <string>

struct Params
{
	int width;
	int height;
	int resolution;
};

class Settings
{
private:
	int m_width;
	int m_height;

	int m_resolution;

public:
	Settings() : m_height(20), m_width(100), m_resolution(32) {}

	Params initWindowSize(int argc, char** argv);

	int getHeight()& { return m_height; }
	int getWidth()& { return m_width; }
	int getResolution()& { return m_resolution; }

};

