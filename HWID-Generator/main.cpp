#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>
#include <string>

#include "info_grabber.h";

int main()
{
    long cpuL = 0;
    long long hddL = 0;
    long long hwid = 0;

    std::string cpuSerial = std::to_string(getCPU());
    std::string hddSerial = std::to_string(getHDD());

    cpuL = atol(cpuSerial.c_str());
    hddL = std::stoll(hddSerial.c_str());

    // Example of simple math to create your own unique pair of hardware id's
    hwid = cpuL * hddL + 2345678;

    // Print to console
    std::cout << hwid << std::endl;
    std::cin.get();
}