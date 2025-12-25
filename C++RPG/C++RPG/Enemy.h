#pragma once
#include <String>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <math.h>
#include "Type.h"
#include "Character.h"

class Enemy : public  Character
{
public:
	Enemy();
	~Enemy();
	int GetXpDrop();
private:
	int xpDrop;
	std::string presetNames[5]{
	"Goblin","Golem","Cultist","Dragon","Knight"
	};
};
;

