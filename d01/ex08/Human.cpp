#include "Human.hpp"

#include <iostream>
#include <functional>

void Human::meleeAttack(std::string const &target)
{
	std::cout << "meleeAttack: " << target << std::endl;
}

void Human::rangedAttack(std::string const &target)
{
	std::cout << "rangedAttack: " << target << std::endl;
}

void Human::intimidatingShout(std::string const &target)
{
	std::cout << "intimidatingShout: " << target << std::endl;
}

typedef void (Human::* actionPtr) (std::string const &);

void Human::action(std::string const &action_name, std::string const &target)
{
	std::string actionNames[3] = {
		"melee",
		"ranged",
		"intimidating",
	};

	actionPtr actions[3] = {
		&Human::meleeAttack,
		&Human::rangedAttack,
		&Human::intimidatingShout,
	};

	for (int i = 0; i < 3; i++)
	{
		if (actionNames[i] == action_name)
		{
			(this->*actions[i])(target);
			return ;
		}
	}
}