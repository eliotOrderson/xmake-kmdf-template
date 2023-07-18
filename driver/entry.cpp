#include <ntddk.h>

// debugview necessary settings:
// 1. capture
//    1.1 Capture kernel
//    1.2 Enable Verbose kernel output 
//    1.3 Capture Events
// 2. filter 
//    2.1 include string of "[*]"
#define DbgInfolog(...) DbgPrint("[INFO] " ## __VA_ARGS__)


void DriverUnload(_In_ PDRIVER_OBJECT driverObject) {
  UNREFERENCED_PARAMETER(driverObject);
  DbgInfolog("driver unloaded...");
}

extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT driverObject, _In_ PUNICODE_STRING registryPath) {
  driverObject->DriverUnload          = DriverUnload;
  NTSTATUS status                     = STATUS_SUCCESS;
  UNREFERENCED_PARAMETER(registryPath);

  DbgInfolog("driver %s","loaded...");
  return status;
}
