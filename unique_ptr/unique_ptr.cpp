// unique_ptr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Precompiled.h"
#include <memory>

using namespace std;

struct Hen
{
	unsigned id;
	float eggs;

	Hen(unsigned id_, float eggs_) :
		id{ id_ },
		eggs{ eggs_ }
	{
		TRACE(L"Started Hen with id = %d and eggs = %3.2f\n", id, eggs);
	}

	~Hen() 
	{
		TRACE(L"Chicken soup! (%d)\n", id);
	}
};

auto GetHen() -> unique_ptr<Hen>
{
	return make_unique<Hen>(2, 3.9f);
}

auto UpdateHen(unique_ptr<Hen> hen) -> unique_ptr<Hen>
{
	hen->eggs += 1.8f;
	return hen;
}

auto main() -> int
{
	auto hen = make_unique<Hen>(1, 5.6f);

	if (hen) TRACE(L"'hen' owns the Hen!\n");

	auto hen2 = move(hen);

	if (hen) TRACE(L"'hen' owns the Hen!\n");
	if (hen2) TRACE(L"'hen2' owns the Hen!\n");

	auto xy = GetHen();

	TRACE(L"eggs %3.2f\n", xy->eggs);

	xy = UpdateHen(move(xy));

	TRACE(L"eggs %3.2f\n", xy->eggs);
}

