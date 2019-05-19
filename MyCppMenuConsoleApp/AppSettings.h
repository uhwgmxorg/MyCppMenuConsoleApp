#pragma once

#include <string>

#define SZ_VALUE_SIZE 300

// For that we need:
// #define _CRT_SECURE_NO_WARNINGS in pch.h
// and 
// #define _CRT_NON_CONFORMING_SWPRINTFS in pch.h for UNICODE functions

#ifdef _UNICODE
#define CAppSettingsW CAppSettings
#else
#define CAppSettingsA CAppSettings
#endif // UNICODE

class CAppSettingsA
{
public:
	long    m_Left = 10;
	long    m_Top = 10;
	long    m_Right = 690;
	long    m_Bottom = 450;


	double m_Factor = 1.1;     // 1.1
	int    m_Min = 2;          // 2

	std::string m_MyPath = "\\MyPath";

	std::string m_IniFlileName = ".\\MyCppMenuConsoleApp.ini";

public:
	CAppSettingsA();
	CAppSettingsA(std::string intFile);
	~CAppSettingsA();
	unsigned int LoadConfig();
	unsigned int SaveConfig();

	static bool FileExsist(char* lpszFilename);
};

class CAppSettingsW
{
public:
	long    m_Left = 10;
	long    m_Top = 10;
	long    m_Right = 690;
	long    m_Bottom = 450;


	double m_Factor = 1.1;     // 1.1
	int    m_Min = 2;          // 2

	std::wstring m_MyPath = L"\\MyPath";

	std::wstring m_IniFlileName = L".\\MyCppMenuConsoleApp.ini";

public:
	CAppSettingsW();
	CAppSettingsW(std::wstring intFile);
	~CAppSettingsW();
	unsigned int LoadConfig();
	unsigned int SaveConfig();

	static bool FileExsist(wchar_t* lpszFilename);
};

