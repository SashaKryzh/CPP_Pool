
#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize()
{

    for (int i = 0; i < 8; i++)
    int n = rand() % (INT_MIN - INT_MAX) - INT_MIN;
}

Data *deserialize(void *raw)
{
}

int main(int ac, char *av[])
{
    void *serialized = serialize();

    return 0;
}