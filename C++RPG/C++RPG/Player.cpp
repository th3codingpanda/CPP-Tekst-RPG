#include "Player.h"
Player::Player(std::string aName, int aMaxHP, int aDamageAmount, enum Type::magicType aMagicType){
	
	name = aName;	
	maxHP = aMaxHP;
	HP = maxHP;
	attackDamage = aDamageAmount;
	level = 0;
	xp = 0;
	xpNeededForLevel = 1000;
	typeOfMagic = aMagicType;
}
Player::~Player(){}
void Player::GiveXp(int aXp) {
	xp += aXp;
	std::cout << "Xp Gained: " << aXp << std::endl;
	CheckForLevelUp();
}
void Player::CheckForLevelUp(){
	if (xp >= xpNeededForLevel)
	{
		LevelUp();
	}
	std::cout << "Xp needed for level up: " << xpNeededForLevel - xp << std::endl;

}
void Player::LevelUp(){
	level += 1;
	attackDamage += (int)round(level * 1.4f);
	maxHP += (int)round(level * 2.1f);
	HP = maxHP;
	xp -= xpNeededForLevel;
	xpNeededForLevel = (int)round(xpNeededForLevel * 1.2);
	std::cout << "Leveled up to level: " << level << std::endl;
	std::cout << "Damage went up by: " << round(level * 1.4f) << " current attack damage: " << attackDamage << std::endl;
	std::cout << "Max HP went up by: " << round(level * 2.1f) << " current Max HP:" << maxHP << std::endl;
	std::cout << "Hp Restored" << std::endl;

}

std::string Player::AskPlayerName() {
	std::string input;
	std::string input2;
	while (true)
	{
		std::cout << "Give your player a name!" << std::endl;
		std::getline(std::cin, input);
		if (std::all_of(input.begin(), input.end(), ::isalpha) && input != "") {
			system("cls");
			std::cout << "You are named: " << input << "\nPress enter to continue!" << std::endl;
			std::getline(std::cin, input2);
			system("cls");
			return input;
		}
		else
		{
			std::cout << "Give me a correct name \nPress enter to continue!" << std::endl;
			std::getline(std::cin, input);
			system("cls");
		}
	}
}
enum Type::magicType Player::AskPlayerType() {
	std::string input;
	while (true)
	{
		std::cout << "Select a magic type!\n1.Fire\n2.Water\n3.Earth\n4.Wind"<< std::endl;
		std::getline(std::cin, input);
		if (std::all_of(input.begin(), input.end(), ::isdigit) && input != "") {
			int typeNumber = std::stoi(input);
			system("cls");
			switch (typeNumber)
			{
			default:
				std::cout << "Give me a correct type\nPress enter to continue!" << std::endl;
				std::getline(std::cin, input);
				system("cls");
			break;
			case 1:
			case 2:
			case 3:
			case 4:
				Type::magicType typeChosen = (Type::magicType)(typeNumber);		
				std::cout << "You have chosen: " << Type::MagicTypeToString(typeChosen) << "\nPress enter to continue!" << std::endl;
				std::getline(std::cin, input);
				system("cls");
				return typeChosen;

			}
		}
		else
		{
			std::cout << "Give me a correct type\nPress enter to continue!" << std::endl;
			std::getline(std::cin, input);
			system("cls");
		}
	}	
}

