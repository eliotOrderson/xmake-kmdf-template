#pragma once

#include <ntddk.h>
#include <ntstrsafe.h>

namespace km {
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
#define INFO "[INFO] "
#define FAIL "[FAIL] "
#define WARN "[WARN] "

    template<typename... T>
    void log(const char *prefix, T... args) {
#ifdef DEBUG
        DbgPrint(prefix);
        DbgPrint(args...);
        DbgPrint("\n");
#endif
    }

    template<typename... T>
    void info(T... args) {
        log(INFO, args...);
    }

    template<typename... T>
    void fail(T... args) {
        log(FAIL, args...);
    }

    template<typename... T>
    void warn(T... args) {
        log(WARN, args...);
    }


    template<typename... E>
    auto format(const CHAR *fmt, E... args) {
        static CHAR buf[512];
        if (RtlStringCchPrintfA(buf, 512,fmt,args...)) {
            auto ret = "RtlStringCchPrintfA Write to buff failed";
            fail(ret);
            return ret;
        }
        return buf;
    }
}



