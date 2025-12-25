#include "Enemy.h"
Enemy::Enemy() {
	srand(time(0));
	maxHP = rand() % 11 + 4;
	HP = maxHP;
	attackDamage = (rand() % 4 + 1);
	typeOfMagic = (Type::magicType)((rand() % 4) + 1);
	name = Type::MagicTypeToString(typeOfMagic) +" "+presetNames[(rand() % 5)];
	xpDrop = round(1000 * ((rand() % 50) / 100.0f + 1));
}
Enemy::~Enemy() {
}
int Enemy::GetXpDrop() {
	return xpDrop;
}