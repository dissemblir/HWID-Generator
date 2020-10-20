#include <Windows.h>
#include <tchar.h>
#include <intrin.h>

char16_t getCPU() {

    int cpuInfo[4] = { 0, 0, 0, 0 }; //EAX, EBX, ECX, EDX
    __cpuid(cpuInfo, 0);
    char16_t hash = 0;
    char16_t* pointer = (char16_t*)(&cpuInfo[0]);
    for (char32_t i = 0; i < 8; i++)
        hash += pointer[i];

	return hash;
}

DWORD getHDD() {

	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)));

	return serialNumber;
}