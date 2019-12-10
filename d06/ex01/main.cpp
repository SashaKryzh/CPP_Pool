
#include <iostream>

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize()
{
    Data *ret = new Data;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand(time(NULL));
    for (int i = 0; i < 8; i++)
        ret->s1 += alphanum[rand() % sizeof(alphanum)];
    ret->n = rand();
    for (int i = 0; i < 8; i++)
        ret->s2 += alphanum[rand() % sizeof(alphanum)];
    return ret;
}

Data *deserialize(void *raw)
{
    return reinterpret_cast<Data *>(raw);
}

int main()
{
    void *raw = serialize();
    Data *data = deserialize(raw);

    std::cout << data->s1 << "\n"
              << data->n << "\n"
              << data->s2 << "\n";
    
    return 0;
}