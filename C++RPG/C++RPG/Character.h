#pragma once
#include <String>
#include <iostream>
#include "Type.h"
#include "ActionEnum.h"
class Character
{
public:
	void SetAction(int aInt);
	enum ActionEnum::Action GetAction();
	void TakeDamage(int aDamage);
	int GetAttackDamage();
	std::string GetName();
	bool CheckIfDied();
	enum Type::magicType GetType();
	void StrongAttackBoolChange(bool aBool);
	bool GetStrongAttackBool();
	void CanDefendBoolChange(bool aBool);
	bool GetCanDefendBool();
	void isDefendBoolChange(bool aBool);
	bool GetIsDefendingBool();
	void ShowHP();
	void ResetAllMoves();

protected:
	std::string name;
	int HP = 0;
	int maxHP = 0;
	int attackDamage = 0;
	enum Type::magicType typeOfMagic = (Type::magicType)1;
	bool canStrongAttack = true;
	bool canDefend = true;
	bool isDefending = false;
	enum ActionEnum::Action CharacterAction = (ActionEnum::Action)1;
};

