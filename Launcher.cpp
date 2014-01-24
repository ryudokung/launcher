#include "stdafx.h"
#include "Launcher.h"

#pragma comment( lib, "Shlwapi.lib" ) 

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	TCHAR szPath[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPath(NULL,CSIDL_PERSONAL|CSIDL_FLAG_CREATE,NULL,0,szPath)))
	{
		PathAppend(szPath, TEXT("BnS"));
		PathAppend(szPath, TEXT("NCSOFT"));
		PathAppend(szPath, TEXT("ClientConfiguration.xml"));

		HANDLE hFile = CreateFile(szPath, GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);

		// TODO: if file is not exist - crate new configuration file
		if (hFile == INVALID_HANDLE_VALUE)	
		{
			return 1;
		}
	}

	ShellExecute(NULL, NULL, L"client.exe", L"/LaunchByLauncher /Sesskey 0123456789 /LoginMode", L"bin", SW_HIDE);
	return 0;
}
