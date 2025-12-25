#include "Character.h"
#include "Enemy.h"
bool Character::CheckIfDied() {
	if (HP <= 0) {
		return true;
	}
	return false;
}

void Character::TakeDamage(int aDamage) {
	HP -= aDamage;
	std::string input;
	std::cout << name <<" Took: " << aDamage << " Damage" << std::endl;
	std::cout << name << " Hp:" << HP << " / " << maxHP << std::endl;
}
int Character::GetAttackDamage() {
	return attackDamage;
}
std::string Character::GetName() {
	return name;
}
enum Type::magicType Character::GetType() {
	return typeOfMagic;
}
void Character::StrongAttackBoolChange(bool aBool) {
	canStrongAttack = aBool;
}
bool Character::GetStrongAttackBool() {
	return canStrongAttack;
}
void Character::CanDefendBoolChange(bool aBool) {
	canDefend = aBool;
}
bool Character::GetCanDefendBool() {
	return canDefend;
}
bool Character::GetIsDefendingBool() {
	return isDefending;
}
void Character::SetAction(int aInt) {
	CharacterAction = (ActionEnum::Action)aInt;
}
enum ActionEnum::Action Character::GetAction() {
	return CharacterAction;
}
void Character::ShowHP() {
	std::cout << HP << " / " << maxHP << " HP" << std::endl;
}
void Character::isDefendBoolChange(bool aBool) {
	isDefending = aBool;
}
void Character::ResetAllMoves() {
	isDefending = false;
	canDefend = true;
	canStrongAttack = true;
}