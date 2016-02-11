#ifndef _MYCOLORCHANGER_H_
#define _MYCOLORCHANGER_H_

#include <Windows.h>

//Colors
const int COLOR_GRAY	= 0x08;
const int COLOR_GREEN	= 0x0A;
const int COLOR_AQUA	= 0x0B;
const int COLOR_RED		= 0x0C;
const int COLOR_YELLOW	= 0x0E;
const int COLOR_WHITE	= 0x0F;

void whiteText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, COLOR_WHITE);
}

void redText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, COLOR_RED);
}

void greenText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, COLOR_GREEN);
}

void aquaText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, COLOR_AQUA);
}

void yellowText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, COLOR_YELLOW);
}

void grayText()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, COLOR_GRAY);
}
#endif