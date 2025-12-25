#include "Game.h"

Game::Game(Player* PaPlayer) {
    PThePlayer = PaPlayer;
}
Game::~Game() {}
void Game::Update(){

		Encounter Encounters = Encounter(PThePlayer);
		Encounters.Battle();
		Encounters.Battle();
}
