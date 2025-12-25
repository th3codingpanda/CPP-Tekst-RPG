#include "Game.h"

Game::Game(Player* PaPlayer) {
    PThePlayer = PaPlayer;
}
Game::~Game() {}
void Game::Update(){

		Encounter Encounters = Encounter(PThePlayer);
		while (true) {
			Encounters.Battle();
			if (!AskToContinue())
			{
				return;
			}
		}

}
bool Game::AskToContinue() {
	std::string input;
	while (true)
	{
	std::cout << "Continue? y or enter/n" << std::endl;
	std::getline(std::cin, input);
	if (input == "y" || "")
	{
		system("cls");
		return true;
	}
	else if (input == "n")
	{
		return false;
	}
	system("cls");
	std::cout << "Please enter a correct answer" << std::endl;
	}
}