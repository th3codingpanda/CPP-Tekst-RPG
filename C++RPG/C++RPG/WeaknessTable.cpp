#include "WeaknessTable.h"
 float WeaknessTable::HandleWeaknessMath(Type::magicType AttackingType, Type::magicType DefendingType) {
	float effectiveness = WeaknessMeasure[AttackingType - 1][DefendingType - 1];
	if (effectiveness > 1)
	{
		std::cout << "VERY effective!" << std::endl;
	}
	else if(effectiveness < 1)
	{
		std::cout << "Not very effective :(" << std::endl;
	}
	else
	{
		std::cout << "effective" << std::endl;
	}
	return effectiveness;
}

