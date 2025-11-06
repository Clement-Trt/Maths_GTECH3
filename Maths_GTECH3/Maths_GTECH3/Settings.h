#pragma once

#include <string>

class Settings
{
private:
	int m_width;
	int m_height;


public:
	Settings() : m_height(20), m_width(100) {}

	void initWindowSize(int argc, char** argv);

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }

};

