#pragma once
#include <iostream>
#include "Type.h"
class WeaknessTable
{
public:
	static constexpr float N = 1.0f;
	static constexpr float E = 1.5f;
	static constexpr float NE = 0.5f;

	//fire
	//water
	//earth
	//wind
	 static constexpr float WeaknessMeasure[4][4] = {
		{ NE, E ,E, N },
		{ E, NE ,N, N },
		{ E, E ,NE, N },
		{ E, N ,E, NE },
	};
	static float HandleWeaknessMath(Type::magicType AttackingType, Type::magicType DefendingType);
};

