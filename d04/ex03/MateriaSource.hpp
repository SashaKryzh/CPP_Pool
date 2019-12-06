#if !defined(MATERIA_SOURCE_HPP)
#define MATERIA_SOURCE_HPP

#include <string>

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *sources_[4];

    void deleteSources();
    void copySources(const MateriaSource &);

public:
    MateriaSource();
    MateriaSource(const MateriaSource &);
    MateriaSource &operator=(const MateriaSource &);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};

#endif // MATERIA_SOURCE_HPP
