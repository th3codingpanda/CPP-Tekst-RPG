#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Encounter.h"
class Game
{
public:
	Game(Player* PaPlayer);
	~Game();
	void Update();

private:
	Player *PThePlayer;
};

