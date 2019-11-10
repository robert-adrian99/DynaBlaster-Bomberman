#pragma once
#include <iostream>
#include <iomanip>
#include <stdlib.h> 
#include <conio.h>
#include <Windows.h>

class Pause
{
public:
	Pause();
	void displayClock();
	void timer();
	void pauseTimer();
private:
	int m_minutes = 3, m_seconds = 0;
	bool m_ok = false;
};

