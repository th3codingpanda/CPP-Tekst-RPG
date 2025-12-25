#pragma once
#include <string>
#include <math.h> 
#include <iostream> 
#include <algorithm>
#include "Type.h"
#include "Character.h"
class Player :public Character {
public:

	Player(std::string aName, int aMaxHp, int aDamageAmount, enum Type::magicType aMagicType);
	~Player();
	void GiveXp(int aXp);
	void CheckForLevelUp();
	void LevelUp();
	std::string AskPlayerName();
	enum Type::magicType AskPlayerType();

private:
	int level = 0;
	int xp = 0;
	int xpNeededForLevel = 1000;
};