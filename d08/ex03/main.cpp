#include <vector>

#include <iostream>
#include <fstream>

#include "IInstruction.hpp"

void errorExit(std::string message)
{
    std::cout << message << std::endl;
    exit(1);
}

void parseInstructions(std::ifstream &fs, std::vector<IInstruction*> &queue)
{
    std::string s((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
    for (std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        switch (*it)
        {
        case '<':
            queue.push_back(new ArrowLeft());
            break;

        case '>':
            queue.push_back(new ArrowRight());
            break;

        case '+':
            queue.push_back(new Plus());
            break;

        case '-':
            queue.push_back(new Minus());
            break;

        case '.':
            queue.push_back(new Dot());
            break;

        case ',':
            queue.push_back(new Comma());
            break;

        case '[':
            queue.push_back(new BraceRight());
            break;

        case ']':
            queue.push_back(new BraceLeft());
            break;

        default:
            errorExit("Invalid character");
        }
    }
}

void executeInstruction(char arr[], std::vector<IInstruction*> &instructions)
{
    int idx = 0;
    unsigned long i = 0;

    while (i < instructions.size())
    {
        instructions[i]->execute(arr, idx, instructions, i);
        i++;
    }
}

int main(int ac, char *av[])
{
    if (ac != 2)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 0;
    }

    std::ifstream fs(av[1]);
    if (fs.good())
    {
        char arr[30000];
        memset(arr, 0, sizeof(arr));
        std::vector<IInstruction*> instructions;
        parseInstructions(fs, instructions);
        
        fs.close();

        executeInstruction(arr, instructions);
    }
    else
    {
        std::cout << av[0] << ": "
                  << av[1] << ": "
                  << strerror(errno)
                  << std::endl;
    }
    return 0;
}