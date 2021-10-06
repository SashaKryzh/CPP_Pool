#include "GameEntity.hpp"
#include <ncurses.h>
#include "GameWindow.hpp"

GameEntity::GameEntity(t_form form, std::string type, int color) : form_(form), type_(type), color_(color) {}

GameEntity::~GameEntity() {}

GameEntity::GameEntity(const GameEntity &src)
{
    operator=(src);
}

GameEntity &GameEntity::operator=(const GameEntity &src)
{
    if (this != &src)
    {
        pos_ = src.pos_;
        old_ = src.old_;
        form_ = src.form_;
        type_ = src.type_;
        color_ = src.color_;
    }
    return *this;
}

void GameEntity::setPosition(size_t x, size_t y)
{
    pos_.x = x;
    pos_.y = y;

    old_.x = x;
    old_.y = y;
}

t_position GameEntity::getPosition() const
{
    return pos_;
}

t_position GameEntity::getOldPosition() const
{
    return old_;
}

t_form GameEntity::getForm() const
{
    return form_;
}

std::string GameEntity::getType() const
{
    return type_;
}

int GameEntity::getColor() const
{
    return color_;
}

bool isColidingBorder(t_position pos, t_form form)
{
    if (pos.y + form.rows > LINES || pos.y < 3 || pos.x + form.cols > COLS || pos.x < 0)
        return true;
    return false;
}

bool GameEntity::isColidingEntity(const GameEntity *obj) const
{
    t_position objPos = obj->getPosition();
    t_form objForm = obj->getForm();

    int dx = objPos.x - pos_.x;
    int dy = objPos.y - pos_.y;

    for (int i = 0; i < form_.rows; i++)
    {
        for (int j = 0; j < form_.cols; j++)
        {
            if (j - dx >= 0 && j - dx < objForm.cols && i - dy >= 0 && i - dy < objForm.rows &&
                form_.lines[i][j] != ' ' && objForm.lines[i - dy][j - dx] != ' ')
                return true;
        }
    }
    return false;
}

// Return false if coliding border
bool GameEntity::move(int onX, int onY)
{
    old_.x = pos_.x;
    old_.y = pos_.y;

    pos_.x += onX;
    pos_.y += onY;

    if (isColidingBorder(pos_, form_))
    {
        pos_.x = old_.x;
        pos_.y = old_.y;
        return false;
    }

    return true;
}

bool GameEntity::move()
{
    return true;
}