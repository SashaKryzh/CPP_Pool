#include <iostream>

int main() {
	std::string string = "HI THIS IS BRAIN";
	
	std::string* ptr = &string;
	std::string& ref = string;

	std::cout << "Pointer: " << *ptr << std::endl;
	std::cout << "Reference: " << ref << std::endl;

	return 0;
}