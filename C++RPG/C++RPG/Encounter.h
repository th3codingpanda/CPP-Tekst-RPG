#pragma once
#include <String>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h> 
#include "Player.h"
#include "Enemy.h"
#include "ActionEnum.h"
#include "Type.h"
#include "WeaknessTable.h"
class Encounter
{
public:
	Encounter(Player *PaPlayer);
	~Encounter();
	void Battle();
	

private:
	Player* pThePlayer;
	Enemy theEnemy;
	void CreateEncounter();
	int askForPlayerAction();
	void PlayerChooseTurn();
	void EnemyChooseTurn();
	bool ResolvePlayerTurn();
	bool ResolveEnemyTurn();
};

