#if !defined(IINSTRUCTION_HPP)
#define IINSTRUCTION_HPP

#include <vector>

class IInstruction
{
private:
    char _c;

public:
    IInstruction(char c);
    virtual ~IInstruction(){};
    virtual void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const = 0;
    char getChar() const;
};

class ArrowLeft : public IInstruction
{
public:
    ArrowLeft();
    ~ArrowLeft();

    ArrowLeft(const ArrowLeft &);
    ArrowLeft &operator=(const ArrowLeft &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class ArrowRight : public IInstruction
{
public:
    ArrowRight();
    ~ArrowRight();

    ArrowRight(const ArrowRight &);
    ArrowRight &operator=(const ArrowRight &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class Plus : public IInstruction
{
public:
    Plus();
    ~Plus();

    Plus(const Plus &);
    Plus &operator=(const Plus &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class Minus : public IInstruction
{
public:
    Minus();
    ~Minus();

    Minus(const Minus &);
    Minus &operator=(const Minus &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class Dot : public IInstruction
{
public:
    Dot();
    ~Dot();

    Dot(const Dot &);
    Dot &operator=(const Dot &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class Comma : public IInstruction
{
public:
    Comma();
    ~Comma();

    Comma(const Comma &);
    Comma &operator=(const Comma &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class BraceRight : public IInstruction
{
public:
    BraceRight();
    ~BraceRight();

    BraceRight(const BraceRight &);
    BraceRight &operator=(const BraceRight &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

class BraceLeft : public IInstruction
{
public:
    BraceLeft();
    ~BraceLeft();

    BraceLeft(const BraceLeft &);
    BraceLeft &operator=(const BraceLeft &);

    void execute(char arr[], int &idx, std::vector<IInstruction *> v, unsigned long &i) const;
};

#endif // IINSTRUCTION_HPP
