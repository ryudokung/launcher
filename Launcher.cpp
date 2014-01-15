#include "stdafx.h"
#include "Launcher.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	ShellExecute(NULL, NULL, L"client.exe", L"/LaunchByLauncher /Sesskey 0123456789 /LoginMode", L"bin", SW_HIDE);
	return 0;
}