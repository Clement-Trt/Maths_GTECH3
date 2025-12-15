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

	char m_backGroundChar;
	char m_meshProjChar;

	float m_screenPosition; 
	float m_viewerPosition; 


public:
	Settings() : m_height(40), m_width(150), m_resolution(32), m_meshProjChar('X'), m_backGroundChar(' '), m_screenPosition(9), m_viewerPosition(10){}

	Params ParseArguments(int argc, char** argv);

	int getHeight() { return m_height; }
	int getWidth() { return m_width; }
	int getResolution() { return m_resolution; }

	char getBackgroundChar() { return m_backGroundChar; }
	char getMeshProjChar() { return m_meshProjChar; }
	int getScreenPosition() { return m_screenPosition; }
	int getViewerPosition() { return m_viewerPosition; }

};

