#include "Brain.hpp"
#include "Human.hpp"

Human::Human() {
	_brain = Brain();
}

std::string Human::identify() const {
	return _brain.identify();
}

Brain &Human::getBrain() {
	return _brain;
}