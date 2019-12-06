#if !defined(CHARACTER_HPP)
#define CHARACTER_HPP

#include <string>

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    AMateria *inventory_[4];
    std::string name_;

    void deleteInventory();
    void copyInventory(const Character &);

public:
    Character(std::string name);
    Character(const Character &);
    Character &operator=(const Character &);
    ~Character();

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
};

#endif // CHARACTER_HPP
