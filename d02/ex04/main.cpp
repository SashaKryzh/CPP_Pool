#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.class.hpp"

std::stringstream g_ags;
std::stringstream g_ops;

// void extractNumbers(std::string s)
// {
// 	std::stringstream ss(s);
// 	std::string temp;
// 	float check;

// 	while (!ss.eof())
// 	{
// 		ss >> temp;
// 		std::cout << temp << "\n";

// 		if (std::stringstream(temp) >> check)
// 			g_ags << temp << " ";

// 		// without it last number will be twice
// 		temp = "";
// 	}
// }

void pop(std::stringstream &ss, float &nbr)
{
	std::cout << "was:" << ss.str() << "!" << std::endl;

	std::string tmp;
	ss >> tmp;

	nbr = std::stof(tmp);
	std::cout << "get:" << nbr << "!" << std::endl;

	//clear
	std::string tmp2(&ss.str()[tmp.length() + 1]);
	ss.str(std::string());
	ss << tmp2;

	std::cout << "became:" << ss.str() << "!" << std::endl;
}

void pop(std::stringstream &ss, char &c)
{
	std::cout << "was:" << ss.str() << "!" << std::endl;

	ss >> c;

	std::cout << "get:" << c << "!" << std::endl;

	//clear
	std::string tmp(&ss.str()[2]);
	ss.str(std::string());
	ss << tmp;

	std::cout << "became:" << ss.str() << "!" << std::endl;
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
	std::string tmp(" ");
	tmp += ss.str();
	ss.str(std::string());
	ss << op << tmp;
}

bool isEmpty(std::stringstream &ss)
{
	return ss.str().empty();
}

void errorExit(std::string message)
{
	std::cout << "Error: " << message << std::endl;
	exit(0);
}

bool isOperator(char c)
{
	return c == '1' ? false : false;
}

int precedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

float applyOp(Fixed a, Fixed b, char op)
{
	switch (op)
	{
	case '+':
		return (a + b).toFloat();
	case '-':
		return (a - b).toFloat();
	case '*':
		return (a * b).toFloat();
	case '/':
		return (a / b).toFloat();
	}
	return -666;
}

void skipNbr(std::string s, size_t &i, bool rec)
{
	// if (rec == false)
	// 	std::cout << &s[i] << std::endl;

	while (isdigit(s[i]))
		i += 1;

	if (s[i] == '.' && rec == false)
	{
		i++;
		if (isdigit(s[i]))
			skipNbr(s, i, true);
		else
			errorExit("Not a digit after '.' in number");
	}
	else if (s[i] == '.' && rec == true)
		errorExit("Second '.' in a number");
}

Fixed evaluate(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
			continue;

		else if (s[i] == '(')
			push(g_ops, s[i]);

		else if (isdigit(s[i]))
		{
			std::stringstream tmp(&s[i]);
			float nbr;

			tmp >> nbr;
			push(g_ags, nbr);
			skipNbr(s, i, false);
		}

		else if (s[i] == ')')
		{
		}

		// Operator
		else if (isOperator(s[i]))
		{
			while (!isEmpty(g_ops) &&
				   precedence(g_ops.peek() >= precedence(s[i])))
			{
				float f1;
				float f2;
				pop(g_ags, f2);
				pop(g_ags, f1);

				char op;
				pop(g_ops, op);

				push(g_ags, applyOp(f1, f2, op));
			}

			push(g_ops, s[i]);
		}

		else
			errorExit("Invalid character");
	}

	// std::cout << "tyt" << std::endl;
	// std::cout << g_ags.str() << std::endl;
	// float c;
	// pop(g_ags, c);
	// std::cout << c << std::endl;
	// std::cout << g_ags.str() << std::endl;

	// pop(g_ags, c);
	// std::cout << c << std::endl;
	// std::cout << g_ags.str() << std::endl;

	// char op;
	// 	pop(g_ops, op);
	std::cout << "--------------" << std::endl;

	while (!isEmpty(g_ops))
	{
		float f1;
		float f2;
		pop(g_ags, f2);
		pop(g_ags, f1);

		char op;
		pop(g_ops, op);

		// std::cout << f1 << std::endl;
		// std::cout << f2 << std::endl;
		// std::cout << op << std::endl;

		push(g_ags, applyOp(f1, f2, op));
	}

	float f;
	g_ags >> f;
	return Fixed(f);
}

int main(int ac, char *av[])
{
	if (ac != 2 || std::string(av[1]).empty())
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return 0;
	}

	Fixed answ = evaluate(av[1]);

	// std::cout << g_ags.str() << std::endl;

	std::cout << "Result: " << answ << std::endl;

	return 0;
}