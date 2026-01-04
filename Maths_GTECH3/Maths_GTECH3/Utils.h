#pragma once
namespace Utils
{
	enum Color
	{
		Red,
		Blue,
		Yellow,
		Green,
		White
	};

	void InitConsole(int width, int height);
	void SetCursorToHomePosition();
	void ClearConsole();
	void SetCursorVisible(bool visible);
	void OnKill(int signum);
	void SetColor(Color color);
};

