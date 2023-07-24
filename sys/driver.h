#pragma once

#include <ntddk.h>


/* debugging info output
Debugview necessary settings:
  1. capture
    1.1 Capture kernel
    1.2 Enable Verbose kernel output 
    1.3 Capture Events
  2. filter 
    2.1 include string of "[*]"

Display debugging info in windbg:
Write the following text to the "r.reg" file in the virtual machine, then double click to run it
Then restart and reconnect windbg, load the driver again, and then you can see the debugging info in windbg.
The following text:
Windows Registry Editor Version 5.00
[HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Debug Print Filter]
"DEFAULT"=dword:0000000f
*/
namespace km {
#define INFO "[INFO] "
#define FAIL "[FAIL] "
#define WARN "[WARN] "
#define log(...) DbgPrint(__VA_ARGS__);DbgPrint("\n")

    template<typename... T>
    void info(T... args) {
#ifdef DEBUG
        DbgPrint(INFO);
        log(args...);
#endif
    }

    template<typename... T>
    void fail(T... args) {
#ifdef DEBUG
        DbgPrint(FAIL);
        log(args...);
#endif
    }

    template<typename... T>
    void warn(T... args) {
#ifdef DEBUG
        DbgPrint(WARN);
        log(args...);
#endif
    }
}

// Function Definition
void DriverUnload(_In_ PDRIVER_OBJECT driverObject);

extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT driverObject, _In_ PUNICODE_STRING registryPath);