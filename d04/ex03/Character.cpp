#include "Character.hpp"

Character::Character(std::string name) : name_(name)
{
    for (int i = 0; i < 4; i++)
        inventory_[i] = nullptr;
}

Character::Character(const Character &src)
{
    name_ = src.name_;
    copyInventory(src);
}

Character &Character::operator=(const Character &src)
{
    if (this != &src)
    {
        name_ = src.name_;
        deleteInventory();
        copyInventory(src);
    }
    return *this;
}

Character::~Character()
{
    deleteInventory();
}

std::string const &Character::getName() const
{
    return name_;
}

void Character::equip(AMateria *m)
{
    int i = 0;
    while (i < 4 && inventory_[i] != nullptr)
        i++;
    if (i != 4)
        inventory_[i] = m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        inventory_[idx] = nullptr;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx < 4 && inventory_[idx] != nullptr)
        inventory_[idx]->use(target);
}

void Character::deleteInventory()
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory_[i] != nullptr)
            delete inventory_[i];
    }
}

void Character::copyInventory(const Character &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.inventory_[i] != nullptr)
            inventory_[i] = src.inventory_[i]->clone();
    }
}