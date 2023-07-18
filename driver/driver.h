#pragma once

#include <ntddk.h>



// debug info ouput
// debugview necessary settings:
// 1. capture
//    1.1 Capture kernel
//    1.2 Enable Verbose kernel output 
//    1.3 Capture Events
// 2. filter 
//    2.1 include string of "[*]"
#ifdef DEBUG // The DEBUG macro is defined in the xmake file
  #define DbgInfolog(...) DbgPrint("[INFO] " ## __VA_ARGS__)
#else
  #define DbgInfolog(...) 
#endif


// Function Definition
void DriverUnload(_In_ PDRIVER_OBJECT driverObject);
extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT driverObject, _In_ PUNICODE_STRING registryPath);
