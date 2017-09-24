#include <windows.h>
#include <stdio.h>

int main() {
	// Системна інформація
	SYSTEM_INFO SystemInfo;
	GetSystemInfo(&SystemInfo);
	printf("dwPageSize = %d\n", SystemInfo.dwPageSize);
	printf("dwAllocationGranularity = %d\n", SystemInfo.dwAllocationGranularity);
	printf("lpMinimumApplicationAddress = %#x\n",
		SystemInfo.lpMinimumApplicationAddress);
	printf("lpMaximumApplicationAddress = %#x\n",
		SystemInfo.lpMaximumApplicationAddress);
	// Стан пам’яті
	MEMORYSTATUSEX MemoryStatus;
	MemoryStatus.dwLength = sizeof(MEMORYSTATUSEX);
	GlobalMemoryStatusEx(&MemoryStatus);
	printf("ullAvailPhys = %I64x\n", MemoryStatus.ullAvailPhys);
	printf("ullAvailVirtual = %I64x\n", MemoryStatus.ullAvailVirtual);
	printf("ullAvailPageFile = %I64x\n", MemoryStatus.ullAvailPageFile);
	printf("ullullTotalPhys = %I64x\n", MemoryStatus.ullTotalPhys);
	printf("ullTotalVirtual = %I64x\n", MemoryStatus.ullTotalVirtual);
	printf("ullTotalPageFile = %I64x\n", MemoryStatus.ullTotalPageFile);
	// Базова інформація про пам'ять процесору
	MEMORY_BASIC_INFORMATION Buffer;
	HANDLE hProcess = GetCurrentProcess();
	DWORD dwAddress = (DWORD)SystemInfo.lpMinimumApplicationAddress;
	while (dwAddress < (DWORD)SystemInfo.lpMaximumApplicationAddress)
	{
		DWORD dwSize = VirtualQueryEx(hProcess, (const void *)dwAddress,
			&Buffer, sizeof(MEMORY_BASIC_INFORMATION));
		printf("BaseAddress = %#x\n", dwAddress);
		printf("RegionSize = %u\n", Buffer.RegionSize);
		switch (Buffer.State) {
		case MEM_COMMIT:printf("MEM_COMMIT\n"); break;
		case MEM_FREE: printf("MEM_FREE\n"); break;
		case MEM_RESERVE:printf("MEM_RESERVE\n"); break;
		default:printf("UNKNOWN\n");
		}
		if (Buffer.State != MEM_FREE) {
			switch (Buffer.AllocationProtect) {
			case PAGE_READONLY: printf("PAGE_READONLY\n"); break;
			case PAGE_READWRITE: printf("PAGE_READWRITE\n"); break;
			case PAGE_EXECUTE: printf("PAGE_READWRITE\n"); break;
			case PAGE_EXECUTE_READ:
				printf("PAGE_EXECUTE_READ\n"); break;
			case PAGE_EXECUTE_READWRITE:
				printf("PAGE_EXECUTE_READWRITE\n"); break;
			case PAGE_EXECUTE_WRITECOPY:
				printf("PAGE_EXECUTE_WRITECOPY\n"); break;
			case PAGE_NOACCESS: printf("PAGE_NOACCESS\n"); break;
			case PAGE_WRITECOPY: printf("PAGE_WRITECOPY\n"); break;
			default: printf("UNKNOWN\n");
			}
		}
		printf("\N\N");
		dwAddress += Buffer.RegionSize;
	}
	system("pause");
	return 0;
}