#include <sstream>
#include <iostream>

#include "eval_expr.hpp"

void pop(std::stringstream &ss, float &nbr)
{
	// std::cout << "was:" << ss.str() << "!" << std::endl;

	checkIsNumberPresent();
	std::string tmp;
	ss >> tmp;

	nbr = std::stof(tmp);
	// std::cout << "get:" << nbr << "!" << std::endl;

	//clear
	std::string tmp2(&ss.str()[tmp.length() + 1]);
	ss.str(std::string());
	ss << tmp2;

	// std::cout << "became:" << ss.str() << "!" << std::endl;
}

void pop(std::stringstream &ss, char &c)
{
	// std::cout << "was:" << ss.str() << "!" << std::endl;

	ss >> c;

	// std::cout << "get:" << c << "!" << std::endl;

	//clear
	std::string tmp(&ss.str()[2]);
	ss.str(std::string());
	ss << tmp;

	// std::cout << "became:" << ss.str() << "!" << std::endl;
}

void push(std::stringstream &ss, float nbr)
{
	std::string tmp(" ");
	tmp += ss.str();
	ss.str(std::string());
	ss << nbr << tmp;
}

void push(std::stringstream &ss, char op)
{
	// std::cout << op << std::endl;
	std::string tmp(" ");
	tmp += ss.str();
	ss.str(std::string());
	ss << op << tmp;
	// std::cout << ss.str() << std::endl;
}
