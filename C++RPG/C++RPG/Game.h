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
	bool AskToContinue();

private:
	Player *PThePlayer;
};

