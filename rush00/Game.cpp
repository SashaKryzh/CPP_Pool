#include "Game.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "SuperEnemy.hpp"

Game::Game(GameWindow &w) : window(w), kills_(0)
{
	player[0] = nullptr;
	player[1] = nullptr;

	for (int i = 0; i < NUM_PLAYER; i++)
	{
		player[i] = new Player();
		playerWantToShoot[i] = false;
	}

	for (int i = 0; i < MAX_BULLETS; i++)
		bullets_[i] = nullptr;
	for (int i = 0; i < MAX_ENEMIES; i++)
		enemies_[i] = nullptr;
}

Game::~Game() {}

void Game::enemyShoot()
{
	srand(time(NULL));
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		Enemy *e = enemies_[i];
		if (e != nullptr)
		{
			// chance of shoot is 20%
			if (rand() % 5 != 1)
				continue;
			addBullet(e);
		}
	}
}

void Game::applyPlayerShoot()
{
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		if (player[i] == nullptr)
			continue;

		if (playerWantToShoot[i])
		{
			addBullet(player[i]);
			playerWantToShoot[i] = false;
		}
	}
}

#define PRED 20

void Game::spawnEnemy()
{
	static int pred = 0;
	int nbOfEnemies;

	if (pred == PRED)
		nbOfEnemies = 3;
	else
	{
		srand(time(NULL));
		nbOfEnemies = rand() % 3;
	}

	for (int i = 0; i < nbOfEnemies; i++)
	{
		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			if (enemies_[j] == nullptr)
			{
				// To not spawn them one on another
				int check = 0;
				while (true)
				{
					bool coliding = false;

					// Predetermined
					if (pred == PRED)
						enemies_[j] = new SuperEnemy();
					else
					{
						if (rand() % 10 == 0)
							enemies_[j] = new SuperEnemy();
						else
							enemies_[j] = new Enemy();
					}

					// check if it alloud to place here
					for (int z = 0; z < MAX_ENEMIES; z++)
					{
						if (j != z && enemies_[z] != nullptr)
							if ((coliding = enemies_[z]->isColidingEntity(enemies_[j])))
								break;
					}

					if (coliding == false)
						break;

					delete enemies_[j];
					enemies_[j] = nullptr;

					// break if we can't put 10 times in a row
					check++;
					if (check == 10)
						break;
				}
				break;
			}
		}
	}

	pred++;
	pred %= PRED + 1;
}

void Game::addBullet(SpaceShip *ship)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (bullets_[i] == nullptr)
		{
			// Deicide how much damage bullet has
			if (ship->getType() == PLAYER_T)
				bullets_[i] = new Bullet(ship, 100);
			else
				bullets_[i] = new Bullet(ship, 20);
			return;
		}
	}
}

size_t Game::getKillsNb(void) const
{
	return kills_;
}

Player *Game::getPlayer(int idx)
{
	if (idx >= 0 && idx < 2)
		return player[idx];
	return nullptr;
}

const Enemy **Game::getEnemies() const
{
	return (const Enemy **)enemies_;
}

const Bullet **Game::getBullets() const
{
	return (const Bullet **)bullets_;
}

void Game::movePlayer()
{
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		if (player[i] != nullptr)
			player[i]->applyMove();
	}
}

void Game::moveEnemies()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		if (enemies_[i] != nullptr)
			if (enemies_[i]->move() == false) // crossed the border
				window.endOfGame("Enemy Crossed The Border");
	}
}

void Game::moveBullets()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		Bullet *b = bullets_[i];
		if (b != nullptr)
		{
			if (b->updateMove() == false) // crossed the border
				deleteBullet(i);
		}
	}
}

void Game::deleteBullet(int idx)
{
	window.undrawObject(bullets_[idx]);
	delete bullets_[idx];
	bullets_[idx] = nullptr;
}

void Game::deleteEnemy(int idx)
{
	window.undrawObject(enemies_[idx]);
	delete enemies_[idx];
	enemies_[idx] = nullptr;
}

void Game::deletePlayer(int idx)
{
	window.undrawObject(player[idx]);
	delete player[idx];
	player[idx] = nullptr;
}

int count(Player *arr[])
{
	int count = 0;
	for (int i = 0; i < NUM_PLAYER; i++)
	{
		if (arr[i] != nullptr)
			count++;
	}
	return count;
}

void Game::playerDeath(int idx, std::string message)
{
	deletePlayer(idx);
	if (count(player) == 0)
		window.endOfGame(message);
}

void Game::checkColision()
{
	for (int i = 0; i < MAX_ENEMIES; i++)
	{
		Enemy *e = enemies_[i];
		if (e != nullptr)
		{
			for (int z = 0; z < NUM_PLAYER; z++)
			{
				if (player[z] != nullptr && e->isColidingEntity(player[z]))
					playerDeath(z, "Colision With Enemy");
			}
		}
	}
}

void Game::checkBulletColisions()
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		Bullet *b = bullets_[i];
		if (b == nullptr)
			continue;

		for (int j = 0; j < NUM_PLAYER; j++)
		{
			if (player[j] != nullptr && player[j]->isColidingEntity(b))
			{
				if (player[j]->takeDamage(b->getDamage()) == false)
					playerDeath(j, "You are killed");

				deleteBullet(i);
				continue;
			}
		}

		for (int j = 0; j < MAX_ENEMIES; j++)
		{
			Enemy *e = enemies_[j];
			if (e == nullptr)
				continue;

			if (e->isColidingEntity(b))
			{
				if (e->takeDamage(b->getDamage()) == false)
				{
					kills_++;
					deleteEnemy(j);
				}
				deleteBullet(i);
				break;
			}
		}
	}
}

void Game::checkCollisions()
{
	checkColision();
	checkBulletColisions();
}

void Game::ketPressed(int key)
{
	switch (key)
	{
	case KEY_UP:
		if (player[0] != nullptr)
			player[0]->setNextMove(0, -1);
		break;

	case KEY_DOWN:
		if (player[0] != nullptr)
			player[0]->setNextMove(0, 1);
		break;

	case KEY_LEFT:
		if (player[0] != nullptr)
			player[0]->setNextMove(-1, 0);
		break;

	case KEY_RIGHT:
		if (player[0] != nullptr)
			player[0]->setNextMove(1, 0);
		break;

	case 'w':
		if (player[1] != nullptr)
			player[1]->setNextMove(0, -1);
		break;

	case 's':
		if (player[1] != nullptr)
			player[1]->setNextMove(0, 1);
		break;

	case 'a':
		if (player[1] != nullptr)
			player[1]->setNextMove(-1, 0);
		break;

	case 'd':
		if (player[1] != nullptr)
			player[1]->setNextMove(1, 0);
		break;

	case KEY_ENTER:
		if (player[0] != nullptr)
			playerWantToShoot[0] = true;
		break;

	case ' ':
		if (player[1] != nullptr)
			playerWantToShoot[1] = true;
		break;

	default:
		break;
	}
}