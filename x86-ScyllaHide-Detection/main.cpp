#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>

bool CheckForPatchedHeavensGate()
{
	uintptr_t gateAddress = static_cast<uintptr_t>(__readfsdword(0xC0u));
	BYTE gateJumpOffset = *reinterpret_cast<BYTE*>(gateAddress + 0x5);

	if (gateJumpOffset != static_cast<BYTE>(0x33))
	{
		return true;
	}

	return false;
}

int main()
{
	if (CheckForPatchedHeavensGate())
	{
		printf("ScyllaHide tampering detected!\n");
	}
	else
	{
		printf("Nothing found...\n");
	}

	printf("\nPress any key to continue . . .\n");
	static_cast<void>(getchar());

	return 0;
}