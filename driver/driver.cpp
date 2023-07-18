#include "driver.h"

extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT driverObject, _In_ PUNICODE_STRING registryPath) {
  UNREFERENCED_PARAMETER(registryPath);
  driverObject->DriverUnload          = DriverUnload;
  NTSTATUS status                     = STATUS_SUCCESS;
  
  DbgInfolog("driver %s","loaded...");
  return status;
}



void DriverUnload(_In_ PDRIVER_OBJECT driverObject) {
  UNREFERENCED_PARAMETER(driverObject);
  DbgInfolog("driver unloaded...");
}