/**************************************************************************/
/*  MyCppMenuConsoleApp                                                   */
/*                                                                        */
/*                                                 uhwgmxorg 27.04.2019   */
/**************************************************************************/
#include "pch.h"
#include <iostream>

#include <atlstr.h>
#include <conio.h>

#include "conmanip.h"
using namespace conmanip;
using namespace std;

#include "AppSettings.h"

HWND consoleWin;

// 3 vars load and saved in the .ini
double      Factor;
int         Min;
#ifdef _UNICODE
std::wstring MyPath;
#else
std::string MyPath;
#endif // UNICODE

//-------------------------------------------
//     ScreenOutput  overloaded function
//-------------------------------------------
void ScreenOutput(int x, int y, const char *text)
{
#ifdef _UNICODE
	wcout << setposx(x); wcout << setposy(y); wcout << text;
#else
	cout << setposx(x); cout << setposy(y); cout << text;
#endif // UNICODE
}
void ScreenOutput(int x, int y, const char *text, console_text_colors foregroundColor, console_bg_colors backgroundColor)
{
#ifdef _UNICODE
	wcout << settextcolor(foregroundColor) << setbgcolor(backgroundColor);
	wcout << setposx(x); wcout << setposy(y); wcout << text;
	wcout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#else
	cout << settextcolor(foregroundColor) << setbgcolor(backgroundColor);
	cout << setposx(x); cout << setposy(y); cout << text;
	cout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#endif // UNICODE
}
void ScreenOutput(int x, int y, const char *text, console_text_colors foregroundColor)
{
#ifdef _UNICODE
	wcout << settextcolor(foregroundColor);
	wcout << setposx(x); wcout << setposy(y); wcout << text;
	wcout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#else
	cout << settextcolor(foregroundColor);
	cout << setposx(x); cout << setposy(y); cout << text;
	cout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#endif // UNICODE
}
void ScreenOutput(int x, int y, CString text)
{
#ifdef _UNICODE
	wcout << setposx(x); wcout << setposy(y); wcout << (LPCTSTR)text;
#else
	cout << setposx(x); cout << setposy(y); cout << (LPCTSTR)text;
#endif // UNICODE
}
void ScreenOutput(int x, int y, CString text, console_text_colors foregroundColor, console_bg_colors backgroundColor)
{
#ifdef _UNICODE
	wcout << settextcolor(foregroundColor) << setbgcolor(backgroundColor);
	wcout << setposx(x); wcout << setposy(y); wcout << (LPCTSTR)text;
	wcout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#else
	cout << settextcolor(foregroundColor) << setbgcolor(backgroundColor);
	cout << setposx(x); cout << setposy(y); cout << (LPCTSTR)text;
	cout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#endif // UNICODE
}
void ScreenOutput(int x, int y, CString text, console_text_colors foregroundColor)
{
#ifdef _UNICODE
	wcout << settextcolor(foregroundColor);
	wcout << setposx(x); wcout << setposy(y); wcout << (LPCTSTR)text;
	wcout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#else
	cout << settextcolor(foregroundColor);
	cout << setposx(x); cout << setposy(y); cout << (LPCTSTR)text;
	cout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#endif // UNICODE
}
void ScreenOutput(int x, int y, CString *text)
{
#ifdef _UNICODE
	wcout << setposx(x); wcout << setposy(y); wcout << (LPCTSTR)* text;
#else
	cout << setposx(x); cout << setposy(y); cout << (LPCTSTR)* text;
#endif // UNICODE
}
void ScreenOutput(int x, int y, CString *text, console_text_colors foregroundColor, console_bg_colors backgroundColor)
{
#ifdef _UNICODE
	wcout << settextcolor(foregroundColor) << setbgcolor(backgroundColor);
	wcout << setposx(x); wcout << setposy(y); wcout << (LPCTSTR)* text;
	wcout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#else
	cout << settextcolor(foregroundColor) << setbgcolor(backgroundColor);
	cout << setposx(x); cout << setposy(y); cout << (LPCTSTR)* text;
	cout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#endif // UNICODE
}
void ScreenOutput(int x, int y, CString *text, console_text_colors foregroundColor)
{
#ifdef _UNICODE
	wcout << settextcolor(foregroundColor);
	wcout << setposx(x); wcout << setposy(y); wcout << (LPCTSTR)* text;
	wcout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#else
	cout << settextcolor(foregroundColor);
	cout << setposx(x); cout << setposy(y); cout << (LPCTSTR)* text;
	cout << settextcolor(console_text_colors::white) << setbgcolor(console_bg_colors::black);
#endif // UNICODE
}
void ResetColore()
{
	const int GRAY = 7;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GRAY);
}

//-------------------------------------------
//	PrintMenu
//-------------------------------------------
void PrintMenu()
{
	CString strFileVersion = "1.0.0.0";
	CString strCharSet;
	CString strArchitecture;

	system("cls");

	if (sizeof(void*) == 4)
		strArchitecture = "x32";
	else
		strArchitecture = "x64";

	strCharSet = "Not Set";
#ifdef _UNICODE
	strCharSet = "UNICODE";
#endif // UNICODE

#ifdef 	_MBCS
	strCharSet = "MBCS";
#endif // _MBCS

#ifdef DEBUG
	ScreenOutput(1, 0, "Program MyCppMenuConsoleApp Debug Ver. Software Version " + strFileVersion, console_text_colors::light_cyan);
	ScreenOutput(1, 1, "Character Set: " + strCharSet + " Architecture: " + strArchitecture, console_text_colors::cyan);
#else
	ScreenOutput(1, 0, "Program MyCppMenuConsoleApp Release Ver. Software Version " + strFileVersion, console_text_colors::light_cyan);
	ScreenOutput(1, 1, "Character Set: " + strCharSet + " Architecture: " + strArchitecture, console_text_colors::cyan);
#endif // DEBUG


	int X = 35, Y = 5;

	ScreenOutput(X, Y + 2, "b Beep");
	ScreenOutput(X, Y + 3, "r PrintRuler");
	ScreenOutput(X, Y + 4, "s Reset Window Pos");
	ScreenOutput(X, Y + 6, "x For Exit");

	ScreenOutput(X - 5, Y + 9, "press a key for choice", console_text_colors::light_green);


	ScreenOutput(79, 0, "");
}

//-------------------------------------------
//	PrintRuler 
//  80 X 25
//-------------------------------------------
void PrintRuler()
{
	system("cls");
	ScreenOutput(0, 0, "12345678901234567890123456789012345678901234567890123456789012345678901234567890", console_text_colors::light_white);
	ScreenOutput(0, 1, "         1         2         3         4         5         6         7         8", console_text_colors::light_white);
	ScreenOutput(0, 1, "2", console_text_colors::light_white);
	ScreenOutput(0, 2, "3", console_text_colors::light_white);
	ScreenOutput(0, 3, "4", console_text_colors::light_white);
	ScreenOutput(0, 4, "5", console_text_colors::light_white);
	ScreenOutput(0, 5, "6", console_text_colors::light_white);
	ScreenOutput(0, 6, "7", console_text_colors::light_white);
	ScreenOutput(0, 7, "8", console_text_colors::light_white);
	ScreenOutput(0, 8, "9", console_text_colors::light_white);
	ScreenOutput(0, 9, "10", console_text_colors::light_white);
	ScreenOutput(0, 10, "11", console_text_colors::light_white);
	ScreenOutput(0, 11, "12", console_text_colors::light_white);
	ScreenOutput(0, 12, "13", console_text_colors::light_white);
	ScreenOutput(0, 13, "14", console_text_colors::light_white);
	ScreenOutput(0, 14, "15", console_text_colors::light_white);
	ScreenOutput(0, 15, "16", console_text_colors::light_white);
	ScreenOutput(0, 16, "17", console_text_colors::light_white);
	ScreenOutput(0, 17, "18", console_text_colors::light_white);
	ScreenOutput(0, 18, "19", console_text_colors::light_white);
	ScreenOutput(0, 19, "20", console_text_colors::light_white);
	ScreenOutput(0, 20, "21", console_text_colors::light_white);
	ScreenOutput(0, 21, "22", console_text_colors::light_white);
	ScreenOutput(0, 22, "23", console_text_colors::light_white);
	ScreenOutput(0, 23, "24", console_text_colors::light_white);
	ScreenOutput(0, 24, "25", console_text_colors::light_white);

	ScreenOutput(30, 5, "press a key to continue", console_text_colors::red, console_bg_colors::white);
	_getch();
}

//-------------------------------------------
//	ResetWindowPos 
//-------------------------------------------
void ResetWindowPos()
{
	RECT r;
	r.left = 10;
	r.top = 10;
	r.right = 690 + 10;
	r.bottom = 450 + 10;
	MoveWindow(consoleWin, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}

//-------------------------------------------
//	MenuDispatcher 
//-------------------------------------------
void MenuDispatcher(char key)
{
	system("cls");
	switch (key)
	{
	case 'b':
		cout << '\a';
		break;
	case 'r':
		PrintRuler();
		break;
	case 's':
		ResetWindowPos();
		break;
	case 'x':
		break;
	default:
		if (key != 0)
		{
			cout << '\a';
			cout << '\a';
			ScreenOutput(30, 5, "You pressed a wrong key !!", console_text_colors::red, console_bg_colors::white);
			_getch();
			system("cls");
		}
		break;
	}
}

//-------------------------------------------
//	main
//-------------------------------------------
int main()
{
	CAppSettings appSettings;

	consoleWin = GetConsoleWindow();
	RECT r;
	GetWindowRect(consoleWin, &r);
	r.left = appSettings.m_Left;
	r.top = appSettings.m_Top;
	r.right = appSettings.m_Right;
	r.bottom = appSettings.m_Bottom;
	MoveWindow(consoleWin, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);

	// load vars from the .ini
	Factor = appSettings.m_Factor;
	Min = appSettings.m_Min;
	MyPath = appSettings.m_MyPath;

	int X = 10, Y = 2;
	CHAR c = 0;
	do
	{
		MenuDispatcher(c);
		PrintMenu();
		c = _getch();
	} while (c != 'x');

	// get and save the Window position
	GetWindowRect(consoleWin, &r);
	appSettings.m_Left = r.left;
	appSettings.m_Top = r.top;
	appSettings.m_Right = r.right;
	appSettings.m_Bottom = r.bottom;

	// save vars to the .ini
	appSettings.m_Factor = Factor;
	appSettings.m_Min = Min;
	appSettings.m_MyPath = MyPath;

	return 0;
}
