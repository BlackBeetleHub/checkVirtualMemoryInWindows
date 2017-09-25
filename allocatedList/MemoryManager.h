#pragma once

#include<Windows.h>
#include<assert.h>

// allocate in virtual memory. 
// Params:
// lpAddress - where allocate new memory (default NULL - autoregist)
// dwSize - size for structure or class for allocate memory ( rounds ~ in grad system ) 
// flAllocateType - allocate memory for work. Not reserve.
// flProtect - what we do with memory? read, write, execute... smth.
// Return value: pointer type T in new memory
template<typename T>
T* allocate() {
	LPVOID address = VirtualAlloc(NULL, sizeof(T), MEM_COMMIT, PAGE_READWRITE);
	assert(address); //throw if VirtuallAlloc return NULL - bad allocate
	return (T*)address; // return need type pointer
}

// delete allocate memory by address
void freeMemory(LPVOID address) {
	bool resFree = VirtualFree(address, 0, MEM_RELEASE);
	assert(resFree); //throw if VirtualFree return false - bad free
}