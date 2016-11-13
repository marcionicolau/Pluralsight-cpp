// Assertions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Precompiled.h"

#define ASSERT _ASSERTE

auto main() -> int
{
	ASSERT(4 == 5);
	printf("success!\n");
}

