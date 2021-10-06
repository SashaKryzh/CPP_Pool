#include "GameWindow.hpp"
#include "Game.hpp"
#include <sys/ioctl.h> //ioctl() and TIOCGWINSZ
#include <unistd.h>    // for STDOUT_FILENO
#include <iostream>

int colornum(int fg, int bg)
{
    int B, bbb, ffff;

    B = 1 << 7;
    bbb = (7 & bg) << 4;
    ffff = 7 & fg;

    return (B | bbb | ffff);
}

void setcolor(int color)
{
    attron(COLOR_PAIR(color));
}

void unsetcolor(int color)
{
    attroff(COLOR_PAIR(color));
}

void check_win_size(void)
{
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    if (size.ws_col < 100 || size.ws_row < 13)
    {
        std::cout << "Error: Terminal size too small." << std::endl;
        exit(0);
    }
}

void menu(void)
{
    NUM_PLAYER = -1;

    std::cout << "  _____  __                    __                 " << std::endl;
    std::cout << "_/ ____\\/  |_  _______   _____/  |________  ____  " << std::endl;
    std::cout << "\\   __\\\\   __\\ \\_  __ \\_/ __ \\   __\\_  __ \\/  _ \\ " << std::endl;
    std::cout << " |  |   |  |    |  | \\/\\  ___/|  |  |  | \\(  <_> )" << std::endl;
    std::cout << " |__|   |__|____|__|    \\___  >__|  |__|   \\____/ " << std::endl;
    std::cout << "          /_____/           \\/                    \n"
              << std::endl;

    std::cout << "Press 1 for simple player or 2 for multiplayer : ";
    while (NUM_PLAYER != 1 && NUM_PLAYER != 2)
    {
        short read;
        
        if (!(std::cin >> read)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			read = -1;
		}

        if ((read != 1 && read != 2))
            std::cout << "Error: invalid entry.\nPress 1 for simple player or 2 for multiplayer : ";
        else
            NUM_PLAYER = read;
    }
}

GameWindow::GameWindow()
{
    // Pre checks
    check_win_size();
    menu();

    // init screen
    initscr();

    // Config
    curs_set(0);
    noecho();
    nodelay(stdscr, TRUE);
    keypad(stdscr, TRUE);

    // Colors
    start_color();
    init_pair(COLOR_RED, COLOR_RED, 0);
    init_pair(COLOR_GREEN, COLOR_GREEN, 0);
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, 0);

    // Stats
    statsWin = newwin(STATS_HEIGHT, COLS - 1, 0, 0);

    // Background ( * 2 cause I'm lazy )
    background_ = new char *[LINES * 2 + 10];
    for (int i = 0; i < LINES * 2 + 10; i++)
    {
        background_[i] = new char[COLS];
        for (int j = 0; j < COLS; j++)
        {
            int r = rand() % 100;
            if (r >= 0 && r < 2)
                background_[i][j] = '*';
            else if (r >= 2 && r < 4)
                background_[i][j] = '+';
            else
                background_[i][j] = ' ';
        }
    }
}

GameWindow::~GameWindow()
{
    delwin(statsWin);
    endwin();
}

void GameWindow::refreshWin(Game &game)
{
    drawStats(game);
    drawEnemies(game.getEnemies());
    for (int i = 0; i < NUM_PLAYER; i++)
    {
        if (game.getPlayer(i) != nullptr)
            drawObject(game.getPlayer(i));
    }
    drawBullets(game.getBullets());

    refresh();
}

void GameWindow::refreshBackground()
{
    static int count = 0;

    for (int i = 3; i < LINES; i++)
    {
        mvprintw(i, 0, background_[LINES * 2 - LINES + i - count]);
    }

    count++;
    count %= LINES;
}

void GameWindow::drawStats(Game &game)
{
    box(statsWin, '|', '-');
    mvwprintw(statsWin, 1, COLS / 2 - 4, "FT_RETRO");
    
    Player *p1 = game.getPlayer(0);
    Player *p2 = game.getPlayer(1);

    int p1HP = p1 != nullptr ? p1->getHP() : 0;
    int p2HP = p2 != nullptr ? p2->getHP() : 0;

    if (NUM_PLAYER == 1)
        mvwprintw(statsWin, 1, 2, "ESC - exit   |||   HP: %3d | KILLS: %3d", p1->getHP(), game.getKillsNb());
    else
        mvwprintw(statsWin, 1, 2, "ESC - exit   |||   HP: %3d / %3d | KILLS: %3d", p1HP, p2HP, game.getKillsNb());

    wrefresh(statsWin);
}

void GameWindow::drawObject(const GameEntity *obj)
{
    setcolor(obj->getColor());

    t_form form = obj->getForm();
    t_position pos = obj->getPosition();

    // Undraw from old position
    undrawObject(obj);

    // Draw on new position
    for (int i = 0; i < form.rows; i++)
    {
        mvprintw(pos.y + i, pos.x, form.lines[i].c_str());
    }

    unsetcolor(obj->getColor());
}

void GameWindow::drawEnemies(const Enemy *enemies[])
{
    for (int i = 0; i < MAX_ENEMIES; i++)
    {
        if (enemies[i] != nullptr)
        {
            drawObject(enemies[i]);
        }
    }
}

// merge functions! up down

void GameWindow::drawBullets(const Bullet *bullets[])
{
    for (int i = 0; i < MAX_BULLETS; i++)
    {
        if (bullets[i] != nullptr)
        {
            drawObject(bullets[i]);
        }
    }
}

void GameWindow::endOfGame(std::string message)
{
    clear();
    mvprintw(LINES / 2, COLS / 2, message.c_str());
    while (true)
    {
        int ch = getch();
        if (ch == 27)
            break;
    }
    deinit();
    exit(0);
}

void GameWindow::undrawObject(const GameEntity *obj)
{
    t_form form = obj->getForm();
    t_position old = obj->getOldPosition();
    t_position pos = obj->getPosition();

    for (int i = 0; i < form.rows; i++)
    {
        for (int j = 0; j < form.cols; j++)
        {
            mvprintw(old.y + i, old.x + j, " ");
            mvprintw(pos.y + i, pos.x + j, " ");
        }
    }
}

void GameWindow::deinit()
{
    delwin(statsWin);
    endwin();
}