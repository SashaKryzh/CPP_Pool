#include "Squad.hpp"

Squad::Squad() : _container(nullptr), _n(0) {}

Squad::~Squad()
{
    _destrayUnits();
}

Squad::Squad(const Squad &src)
{
    _copyUnits(src);
    _n = src._n;
}

Squad &Squad::operator=(const Squad &src)
{
    if (this != &src)
    {
        _destrayUnits();
        _copyUnits(src);
        _n = src._n;
    }
    return *this;
}

int Squad::getCount() const
{
    return _n;
}

void Squad::_destrayUnits()
{
    t_container *tmp;
    while (_container != nullptr)
    {
        tmp = _container;
        _container = _container->next;
        delete tmp->unit;
        delete tmp;
    }
}

void Squad::_copyUnits(const Squad &src)
{
    for (int i = 0; i < src._n; i++)
        push(src.getUnit(i)->clone());
}

ISpaceMarine *Squad::getUnit(int N) const
{
    t_container *c = _container;

    if (N < 0 || N >= _n)
        return nullptr;

    while (N-- > 0)
        c = c->next;

    return c->unit;
}

int Squad::push(ISpaceMarine *sm)
{
    t_container *tmp = _container;

    if (sm == nullptr)
        return -1;

    if (_container == nullptr)
    {
        _container = new t_container;
        _container->unit = sm;
        _container->next = nullptr;
    }
    else
    {
        while (tmp->next != nullptr)
        {
            if (tmp->unit == sm)
                return _n;
            tmp = tmp->next;
        }
    
        tmp->next = new t_container;
        tmp->next->unit = sm;
        tmp->next->next = nullptr;
    }

    _n++;
    return _n;
}
