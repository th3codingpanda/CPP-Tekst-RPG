#include "ActionEnum.h"

std::string ActionEnum::ActionToString(Action aAction){
	switch (aAction)
	{
	default:
		return "No Type Found";
	case Action::Attack:
		return "Attack";
	case Action::StrongAttack:
		return "Strong attack";
	case Action::Defend:
		return "Defend";
	}
}
