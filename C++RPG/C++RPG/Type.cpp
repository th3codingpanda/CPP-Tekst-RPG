#include "Type.h"

 std::string Type::MagicTypeToString(magicType aMagicType) {
	switch (aMagicType)
	{
	case Type::Fire:
		return "Fire";
	case Type::Water:
		return "Water";
	case Type::Earth:
		return "Earth";;
	case Type::Wind:
		return "Wind";
	default:
		return "No Type Found";
	}
}