#include <iostream>
#include "Pony.hpp"

int main() {
	std::cout << "--- On The Heap ---" << std::endl;
	ponyOnTheHeap();

	std::cout << std::endl;

	std::cout << "--- On The Stack ---" << std::endl;
	ponyOnTheStack();

	return 0;
}