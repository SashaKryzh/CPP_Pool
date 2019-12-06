#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        sources_[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
    copySources(src);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
    if (this != &src)
    {
        deleteSources();
        copySources(src);
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    deleteSources();
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++)
    {
        if (sources_[i] == nullptr)
        {
            sources_[i] = m->clone();
            return;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++)
    {
        if (sources_[i] != nullptr && sources_[i]->getType() == type)
            return sources_[i]->clone();
    }
    return 0;
}

void MateriaSource::deleteSources()
{
    for (int i = 0; i < 4; i++)
    {
        if (sources_[i] != nullptr)
            delete sources_[i];
    }
}

void MateriaSource::copySources(const MateriaSource &src)
{
    for (int i = 0; i < 4; i++)
    {
        if (src.sources_[i] != nullptr)
            sources_[i] = src.sources_[i]->clone();
    }
}