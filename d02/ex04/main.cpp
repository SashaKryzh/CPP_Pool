#include <iostream>
#include <sstream>
#include <string>

#include "Fixed.class.hpp"
#include "eval_expr.hpp"

std::stringstream g_ags;
std::stringstream g_ops;

void errorExit(std::string message)
{
	std::cout << "Error: " << message << std::endl;
	exit(0);
}

bool isEmpty(std::stringstream &ss)
{
	return ss.str().empty();
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void checkIsNumberPresent()
{
	if (isEmpty(g_ags))
		errorExit("Wrong number of operators");
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
	errorExit("Something wrong in applyOp()");
	return -666;
}

void skipNbr(std::string s, size_t &i, bool rec)
{
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
		std::cout << "Ags: " << g_ags.str() << std::endl;
		std::cout << "Ops: " << g_ops.str() << std::endl;
		std::cout << "now: " << s[i] << std::endl;

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
			i--;
		}

		else if (s[i] == ')')
		{
			while(!isEmpty(g_ops) && g_ops.peek() != '(') 
            { 
				float f1;
				float f2;
				pop(g_ags, f2);
				pop(g_ags, f1);

                char op; 
                pop(g_ops, op); 

                push(g_ags, applyOp(f1, f2, op)); 
            } 

            // pop opening brace. 
			char x;
            if(!isEmpty(g_ops)) 
               pop(g_ops, x);
			else
				errorExit("Wrong number of braces");
		}

		// Operator
		else if (isOperator(s[i]))
		{
			std::cout << "isEmpty(ops):" << isEmpty(g_ops) << std::endl;
			// std::cout << "g_ops.peek(): " << (!isEmpty(g_ops) ? g_ops.peek() : 5) << std::endl;
			
			// if (!isEmpty(g_ops))
			// {
			// 	std::cout << precedence(g_ops.peek()) << std::endl;
			// 	std::cout << precedence(s[i]) << std::endl;
			// }

			while (!isEmpty(g_ops) && precedence(g_ops.peek()) >= precedence(s[i]))
			{
				printf("tyt");
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

		std::cout << std::endl;
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
	pop(g_ags, f);
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

	if (!isEmpty(g_ags))
	{
		errorExit("Wrong number of numbers");
	}
	// std::cout << g_ags.str() << std::endl;

	std::cout << "Result: " << answ << std::endl;

	return 0;
}