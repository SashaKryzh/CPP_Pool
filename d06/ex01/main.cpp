
#include <iostream>

struct DataRaw
{
    char s1[8];
    int n;
    char s2[8];
};

struct Data
{
    std::string s1;
    int n;
    std::string s2;
};

void *serialize()
{
    DataRaw *ret = new DataRaw;
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    srand(time(NULL));
    for (int i = 0; i < 8; i++)
    {
        ret->s1[i] = alphanum[rand() % sizeof(alphanum)];
        ret->s2[i] = alphanum[rand() % sizeof(alphanum)];
    }
    ret->n = rand();
    return ret;
}

Data *deserialize(void *raw)
{
    DataRaw *tmp = reinterpret_cast<DataRaw *>(raw);
    Data *ret = new Data;
    for (int i = 0; i < 8; i++)
    {
        ret->s1 += tmp->s1[i];
        ret->s2 += tmp->s2[i];
    }
    ret->n = tmp->n;
    return ret;
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