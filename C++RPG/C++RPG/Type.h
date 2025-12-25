#pragma once
#include <String>
class Type
{
	public:
		enum magicType {

			Fire = 1,
			Water,
			Earth,
			Wind
		};
	static std::string MagicTypeToString(magicType aMagicType);
};

