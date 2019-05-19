#include "pch.h"
#include "AppSettings.h"

#include <atlstr.h>
#include <stdio.h>
#include  <io.h>

using namespace std;

/*****************************************************************************************/
/*                               CAppSettingsA NON UNICODE                               */
/*****************************************************************************************/

//-------------------------------------------
//	Constructor
//-------------------------------------------
CAppSettingsA::CAppSettingsA()
{
	LoadConfig();
}

//-------------------------------------------
//	Constructor
//-------------------------------------------
CAppSettingsA::CAppSettingsA(string intFile)
{
	m_IniFlileName = intFile;
	LoadConfig();
}

//-------------------------------------------
//	Destructor
//-------------------------------------------
CAppSettingsA::~CAppSettingsA()
{
	SaveConfig();
}

//-------------------------------------------
//	LoadConfig
//-------------------------------------------
unsigned int CAppSettingsA::LoadConfig()
{
	char szValue[SZ_VALUE_SIZE];

	char szIniFile[MAX_PATH];
	strcpy(szIniFile, m_IniFlileName.c_str());

	m_Left = GetPrivateProfileIntA("Window", "Left", 10, szIniFile);
	m_Top = GetPrivateProfileIntA("Window", "Top", 10, szIniFile);
	m_Right = GetPrivateProfileIntA("Window", "Right", 690 + 10, szIniFile);
	m_Bottom = GetPrivateProfileIntA("Window", "Bottom", 450 + 10, szIniFile);

	GetPrivateProfileStringA("App", "Factor", "1.1", szValue, SZ_VALUE_SIZE, szIniFile);
	m_Factor = atof(szValue);
	m_Min = GetPrivateProfileIntA("App", "Min", 2, szIniFile);

	GetPrivateProfileStringA("App", "MyPath", m_MyPath.c_str(), szValue, SZ_VALUE_SIZE, szIniFile);
	m_MyPath = szValue;

	unsigned int e = GetLastError();

	return e;
}

//-------------------------------------------
//	SaveConfig
//-------------------------------------------
unsigned int CAppSettingsA::SaveConfig()
{
	bool flag;
	char szValue[SZ_VALUE_SIZE];

	char szIniFile[MAX_PATH];
	strcpy(szIniFile, m_IniFlileName.c_str());

	sprintf(szValue, "%d", m_Left);
	flag = WritePrivateProfileStringA("Window", "Left", szValue, szIniFile);
	sprintf(szValue, "%d", m_Top);
	flag = WritePrivateProfileStringA("Window", "Top", szValue, szIniFile);
	sprintf(szValue, "%d", m_Right);
	flag = WritePrivateProfileStringA("Window", "Right", szValue, szIniFile);
	sprintf(szValue, "%d", m_Bottom);
	flag = WritePrivateProfileStringA("Window", "Bottom", szValue, szIniFile);

	sprintf(szValue, "%f", m_Factor);
	flag = WritePrivateProfileStringA("App", "ScaleFactor", szValue, szIniFile);
	sprintf(szValue, "%d", m_Min);
	flag = WritePrivateProfileStringA("App", "MinNeighbors", szValue, szIniFile);

	sprintf(szValue, "%s", m_MyPath.c_str());
	flag = WritePrivateProfileStringA("App", "MyPath", szValue, szIniFile);

	unsigned int e = GetLastError();

	return e;
}

//-------------------------------------------
//	FileExsist 
//-------------------------------------------
bool CAppSettingsA::FileExsist(char* lpszFilename)
{
	return _access(lpszFilename, 0) == 0;
}

/*****************************************************************************************/
/*                                CAppSettingsW UNICODE                                  */
/*****************************************************************************************/

//-------------------------------------------
//	Constructor
//-------------------------------------------
CAppSettingsW::CAppSettingsW()
{
	LoadConfig();
}

//-------------------------------------------
//	Constructor
//-------------------------------------------
CAppSettingsW::CAppSettingsW(wstring intFile)
{
	m_IniFlileName = intFile;
	LoadConfig();
}

//-------------------------------------------
//	Destructor
//-------------------------------------------
CAppSettingsW::~CAppSettingsW()
{
	SaveConfig();
}

//-------------------------------------------
//	LoadConfig
//-------------------------------------------
unsigned int CAppSettingsW::LoadConfig()
{
	wchar_t szValue[SZ_VALUE_SIZE];

	wchar_t szIniFile[MAX_PATH];
	wcscpy(szIniFile, m_IniFlileName.c_str());

	m_Left = GetPrivateProfileIntW(L"Window", L"Left", 10, szIniFile);
	m_Top = GetPrivateProfileIntW(L"Window", L"Top", 10, szIniFile);
	m_Right = GetPrivateProfileIntW(L"Window", L"Right", 690 + 10, szIniFile);
	m_Bottom = GetPrivateProfileIntW(L"Window", L"Bottom", 450 + 10, szIniFile);

	GetPrivateProfileStringW(L"App", L"Factor", L"1.1", szValue, SZ_VALUE_SIZE, szIniFile);
	m_Factor = _wtof(szValue);
	m_Min = GetPrivateProfileIntW(L"App", L"Min", 2, szIniFile);

	GetPrivateProfileStringW(L"App", L"MyPath", m_MyPath.c_str(), szValue, SZ_VALUE_SIZE, szIniFile);
	m_MyPath = szValue;

	unsigned int e = GetLastError();

	return e;
}

//-------------------------------------------
//	SaveConfig
//-------------------------------------------
unsigned int CAppSettingsW::SaveConfig()
{
	bool flag;
	wchar_t szValue[SZ_VALUE_SIZE];

	wchar_t szIniFile[MAX_PATH];
	wcscpy(szIniFile, m_IniFlileName.c_str());

	swprintf(szValue, L"%d", m_Left);
	flag = WritePrivateProfileStringW(L"Window", L"Left", szValue, szIniFile);
	swprintf(szValue, L"%d", m_Top);
	flag = WritePrivateProfileStringW(L"Window", L"Top", szValue, szIniFile);
	swprintf(szValue, L"%d", m_Right);
	flag = WritePrivateProfileStringW(L"Window", L"Right", szValue, szIniFile);
	swprintf(szValue, L"%d", m_Bottom);
	flag = WritePrivateProfileStringW(L"Window", L"Bottom", szValue, szIniFile);

	swprintf(szValue, L"%f", m_Factor);
	flag = WritePrivateProfileStringW(L"App", L"ScaleFactor", szValue, szIniFile);
	swprintf(szValue, L"%d", m_Min);
	flag = WritePrivateProfileStringW(L"App", L"MinNeighbors", szValue, szIniFile);

	swprintf(szValue, L"%s", m_MyPath.c_str());
	flag = WritePrivateProfileStringW(L"App", L"MyPath", szValue, szIniFile);

	unsigned int e = GetLastError();

	return e;
}

//-------------------------------------------
//	FileExsist 
//-------------------------------------------
bool CAppSettingsW::FileExsist(wchar_t* lpszFilename)
{
	return _waccess(lpszFilename, 0) == 0;
}
