#pragma once
#include <String>
class ActionEnum
{
public:
	enum Action {
		Attack = 1,
		StrongAttack = 2,
		Defend = 3
	};
	static std::string ActionToString(Action aAction);
};

