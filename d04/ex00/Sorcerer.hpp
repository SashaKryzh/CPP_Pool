#if !defined(SORCERER_HPP)
#define SORCERER_HPP

#include <string>
#include <ostream>

#include "Victim.hpp"

class Sorcerer
{
public:
    Sorcerer(std::string name, std::string title);
    ~Sorcerer();
    Sorcerer(const Sorcerer &rhs);
    Sorcerer &operator=(const Sorcerer &rhs);

    std::string getName() const;
    std::string getTitle() const;

    void polymorph(Victim const &) const;

private:
    std::string _name;
    std::string _title;
};

std::ostream &operator<<(std::ostream &os, const Sorcerer &sr);

#endif // SORCERER_HPP
