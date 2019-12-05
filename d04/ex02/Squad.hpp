#if !defined(SQUAD_HPP)
#define SQUAD_HPP

#include <cstddef>

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad
{
private:
    typedef struct s_container
    {
        ISpaceMarine *unit;
        struct s_container *next;
    } t_container;

    t_container *_container;
    int _n;

    void _destrayUnits();
    void _copyUnits(const Squad &);

public:
    Squad();
    ~Squad();
    Squad(const Squad &);
    Squad &operator=(const Squad &);

    int getCount() const;
    ISpaceMarine *getUnit(int) const;
    int push(ISpaceMarine *);
};

#endif // SQUAD_HPP
