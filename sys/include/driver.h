#pragma once

#include <ntddk.h>
#include "utils.h"


// Function Definition
void DriverUnload(_In_ PDRIVER_OBJECT driverObject);

extern "C" NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT driverObject, _In_ PUNICODE_STRING registryPath);