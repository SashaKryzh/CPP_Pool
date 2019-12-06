#if !defined(IMATERIA_SOURCEHPP)
#define IMATERIA_SOURCEHPP

#include <string>

#include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria *) = 0;
    virtual AMateria *createMateria(std::string const &type) = 0;
};

#endif // IMATERIA_SOURCEHPP
