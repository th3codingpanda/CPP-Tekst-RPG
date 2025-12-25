#include "Encounter.h"
Encounter::Encounter(Player* PaPlayer) {
	pThePlayer = PaPlayer;


}
Encounter::~Encounter() {

}
void Encounter::Battle() {

	CreateEncounter();
	while (true)
	{
		PlayerChooseTurn();
		EnemyChooseTurn();
		if (ResolvePlayerTurn()) {
			return;
		}
		else if (ResolveEnemyTurn())
		{
			CreateEncounter();
		}
	}
}
int Encounter::askForPlayerAction() {
	std::string input;
	while (true)
	{
		std::cout << "Choose an action: \n1:Attack\n2:Strong attack(1 turn cooldown)\n3:Defend(1 turn cooldown)" << std::endl;
		std::getline(std::cin, input);
		if (std::all_of(input.begin(), input.end(), ::isdigit) && input != "") {
			int number = std::stoi(input);
			{
				switch (number)
				{
				default:
					std::cout << "Give me a correct number\nPress enter to continue!" << std::endl;
					std::getline(std::cin, input);
					system("cls");
					break;
				case 1:
					system("cls");
					std::cout << "You Chose action: " << ActionEnum::ActionToString((ActionEnum::Action)number) << std::endl;
					pThePlayer->CanDefendBoolChange(true);
					pThePlayer->isDefendBoolChange(false);
					pThePlayer->StrongAttackBoolChange(true);
					return number;
				case 2:
					if (pThePlayer->GetStrongAttackBool())
					{
						system("cls");
						std::cout << "You Chose action: " << ActionEnum::ActionToString((ActionEnum::Action)number) << std::endl;
						pThePlayer->CanDefendBoolChange(true);
						pThePlayer->isDefendBoolChange(false);
						pThePlayer->StrongAttackBoolChange(false);
						return number;
					}
					else
					{
						system("cls");
						std::cout << "Action: " << ActionEnum::ActionToString((ActionEnum::Action)number) << " currently on cooldown\nPress enter to continue!" << std::endl;
						std::getline(std::cin, input);
						system("cls");
					}
					break;
				case 3:
					if (pThePlayer->GetCanDefendBool())
					{
						system("cls");
						std::cout << "You Chose action: " << ActionEnum::ActionToString((ActionEnum::Action)number) << std::endl;
						pThePlayer->CanDefendBoolChange(false);
						pThePlayer->isDefendBoolChange(true);
						pThePlayer->StrongAttackBoolChange(true);
						return number;

					}
					else
					{
						system("cls");
						std::cout << "Action: " << ActionEnum::ActionToString((ActionEnum::Action)number) << " currently on cooldown\nPress enter to continue!" << std::endl;
						std::getline(std::cin, input);
						system("cls");
					}
					break;
				}
			}
		}
		else
		{
			std::cout << "Give me a correct number\nPress enter to continue!" << std::endl;
			std::getline(std::cin, input);
			system("cls");
		}
	}
}
void Encounter::PlayerChooseTurn() {
	std::cout << pThePlayer->GetName() << "'s turn:" << std::endl;
	pThePlayer->SetAction(askForPlayerAction());
}
void Encounter::EnemyChooseTurn() {
	srand(time(0));
	if (!pThePlayer->GetCanDefendBool() && theEnemy.GetStrongAttackBool())
	{
		theEnemy.SetAction(ActionEnum::Action::StrongAttack);
	}
	else if (!pThePlayer->GetStrongAttackBool())
	{
		if (theEnemy.GetStrongAttackBool()) {
			theEnemy.SetAction(rand() % 2 + 1);
		}
		else
		{
			theEnemy.SetAction(1);
		}
	}
	else
	{
		if (theEnemy.GetStrongAttackBool() && theEnemy.GetCanDefendBool())
		{
			theEnemy.SetAction(rand() % 3 + 1);
		}
		else if (theEnemy.GetStrongAttackBool())
		{
			theEnemy.SetAction(rand() % 2 + 1);
		}
		else
		{
			int number = rand() % 2 + 1;
			if (number == 1) {
				theEnemy.SetAction(ActionEnum::Action::Attack);
			}
			else
			{
				theEnemy.SetAction(ActionEnum::Action::Defend);
			}
		}
	}
	//Change the cooldown based on the move used
	if (theEnemy.GetAction() == ActionEnum::Action::Defend) {
		theEnemy.CanDefendBoolChange(false);
		theEnemy.isDefendBoolChange(true);
		theEnemy.StrongAttackBoolChange(true);
	}
	else if (theEnemy.GetAction() == ActionEnum::Action::StrongAttack)
	{
		theEnemy.CanDefendBoolChange(true);
		theEnemy.isDefendBoolChange(false);
		theEnemy.StrongAttackBoolChange(false);
	}
	else
	{
		theEnemy.CanDefendBoolChange(true);
		theEnemy.isDefendBoolChange(false);
		theEnemy.StrongAttackBoolChange(true);
	}
}

void Encounter::CreateEncounter() {
	pThePlayer->ResetAllMoves();
	theEnemy = Enemy();
	std::string input;
	std::cout << "you are facing: " << theEnemy.GetName() << std::endl;
	theEnemy.ShowHP();
	std::cout << "Press enter to continue!" << std::endl;
	std::getline(std::cin, input);
	system("cls");
}
bool Encounter::ResolveEnemyTurn() {
	std::string input;
	if (!pThePlayer->GetIsDefendingBool())
	{
		switch (theEnemy.GetAction())
		{
		default:
			break;
		case ActionEnum::Action::Attack:
			std::cout << theEnemy.GetName() << " used Normal " << Type::MagicTypeToString(theEnemy.GetType()) << " Attack!" << std::endl;
			pThePlayer->TakeDamage((int)round(theEnemy.GetAttackDamage() * WeaknessTable::HandleWeaknessMath(theEnemy.GetType(), pThePlayer->GetType())));
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			break;
		case ActionEnum::Action::StrongAttack:
			std::cout  << theEnemy.GetName() << " used Strong " << Type::MagicTypeToString(theEnemy.GetType()) << " Attack!" << std::endl;
			pThePlayer->TakeDamage((int)round(theEnemy.GetAttackDamage() * 1.5f * WeaknessTable::HandleWeaknessMath(theEnemy.GetType(), pThePlayer->GetType())));
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			break;
		case ActionEnum::Action::Defend:
			std::cout << theEnemy.GetName() << " Defended your attack!" << std::endl;
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			break;
		}
		if (pThePlayer->CheckIfDied())
		{
			std::cout << pThePlayer->GetName() << " has been slain" << std::endl;
			std::cout << " You had one job :(" << std::endl;
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			return true;
		}
	}
	else
	{
		std::cout << theEnemy.GetName() <<" tried to use:" << ActionEnum::ActionToString(theEnemy.GetAction()) << std::endl;
		std::cout << "but " << pThePlayer->GetName() << " Deflected the attack! (good job!)" << std::endl;
		std::cout << "Press enter to continue" << std::endl;
		std::getline(std::cin, input);
		system("cls");
	}
	return false;
}
bool Encounter::ResolvePlayerTurn() {
	std::string input;
	if (!theEnemy.GetIsDefendingBool())
	{
		switch (pThePlayer->GetAction())
		{
		default:
			break;
		case ActionEnum::Action::Attack:
			std::cout << pThePlayer->GetName() << " used Normal " << Type::MagicTypeToString(pThePlayer->GetType()) << " Attack!" << std::endl;
			theEnemy.TakeDamage((int)round(pThePlayer->GetAttackDamage() * WeaknessTable::HandleWeaknessMath(pThePlayer->GetType(), theEnemy.GetType())));
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			break;
		case ActionEnum::Action::StrongAttack:
			std::cout << pThePlayer->GetName() << " used Strong " << Type::MagicTypeToString(pThePlayer->GetType()) << " Attack!" << std::endl;
			theEnemy.TakeDamage((int)round(pThePlayer->GetAttackDamage() * 1.5f * WeaknessTable::HandleWeaknessMath(pThePlayer->GetType(), theEnemy.GetType())));
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			break;
		case ActionEnum::Action::Defend:
			std::cout << pThePlayer->GetName() << " Defends!" << std::endl;
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			break;
		}
		if (theEnemy.CheckIfDied())
		{
			std::cout << theEnemy.GetName() << " has been slain" << std::endl;
			pThePlayer->GiveXp(theEnemy.GetXpDrop());
			std::cout << "Press enter to continue" << std::endl;
			std::getline(std::cin, input);
			system("cls");
			return true;
		}
	}
	else
	{
		std::cout << "you tried to use:" << ActionEnum::ActionToString(pThePlayer->GetAction()) << std::endl;
		std::cout << "but " << theEnemy.GetName() << " Deflected the attack!" << std::endl;
		std::cout << "Press enter to continue" << std::endl;
		std::getline(std::cin, input);
		system("cls");
		
	}
	return false;
}