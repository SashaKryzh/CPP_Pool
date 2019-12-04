#if !defined(VICTIM_HPP)
#define VICTIM_HPP

#include <string>
#include <ostream>

class Victim
{
public:
    Victim(std::string name);
    ~Victim();
    Victim(const Victim &rhs);
    Victim &operator=(const Victim &rhs);

    std::string getName() const;

    virtual void getPolymorphed() const;

private:
    std::string _name;
};

std::ostream &operator<<(std::ostream &os, const Victim &sr);

#endif // VICTIM_HPP
