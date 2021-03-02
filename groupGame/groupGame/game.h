#ifndef GAME_H
#define GAME_H
#include "player.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstdlib>
#include <iterator>

#include "player.h"
#include "bullet.h"
#include "enemy.h"

class Game
{
private:
	//*******window*******
	sf::RenderWindow* window;
	sf::View view;
	sf::Event ev;
	sf::VideoMode videoMode;

	//*******player*******
	Player* player;

	//*******world*******
	sf::Sprite worldBackground;

	//*******resources*******
	std::map<std::string, sf::Texture*> textures;
	std::vector<Bullet*> playerBullets;
	std::vector<Bullet*> enemyBullets;
	std::vector<Enemy*> enemies;
	sf::Font font;

	//*******text*******
	sf::Text pointText;
	sf::Text comboText;
	sf::Text playerHpText;
	sf::Text gameOverText;

	//*******Mouse position*******
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;
	
	//*******Timer*******
	sf::Clock clock;

	//*******character positions*******
	sf::Vector2f playerPos;
	sf::Vector2f enemyPos;

	//*******game logic*******
	//enemy variables
	bool enemySpawned;
	bool enemyCollision;
	bool enemyDestroyed;
	int numEnemies;
	int numEnemiesDestroyed;
	//int bulletCounter;

	//player variables
	bool moveUp;
	bool moveRight;
	bool playerCollision;
	float playerInvulTimer;
	float playerInvulTimerMax;
	sf::FloatRect playerBulletHitbox;

	//game variables
	int currentWave;
	float mouseAngle;
	float enemyAngle;
	bool gameOver;
	unsigned int points;
	unsigned int combo;
	sf::Vector2f playerAimDir;
	sf::Vector2f enemyAimDir;
	sf::Vector2f baseEnemyAimDir;

	//general private variables
	const float pi = 3.14159f;

	//private functions
	void initVariables();
	void initWindow();
	void initTextures();
	void initGUI();
	//void initText(sf::Text& text, sf::Font font, sf::Vector2f pos, int size, sf::Color color, std::string initialString);
	void initWorld();
	void initPlayer();
	void initEnemy();

public:
	//constructor/destructor
	Game();
	~Game();

	//update
	void update();
	void updateView();
	void updateMousePos();
	void updatePollEvents();
	void updatePlayer();
	void updateEnemies();
	void updateBullets();
	void updateWorldCollision();
	void updateEnemyCollision();
	void updatePlayerCollision();
	void updateGUI();

	//render
	void render();
	void renderWorld();
	void renderGUI();

	//accessors
	const bool running() const;

	//functions
	void nextWave();
	void moveInRect(Enemy* enemy);
	void spawnEnemyOne(sf::Vector2f initialPosition, unsigned posInWave);
	void spawnEnemyTwo(sf::Vector2f initialPosition, unsigned posInWave);
	void spawnEnemyThree(sf::Vector2f initialPosition, unsigned posInWave);
	void spawnEnemyFour(sf::Vector2f initialPosition, unsigned posInWave);
	void spawnBoss(sf::Vector2f initialPosition, unsigned posInWave);

	void enemyOneFirePattern();
	void enemyTwoFirePattern();
	void enemyThreeFirePattern();
	void enemyFourFirePattern(Enemy* enemy);
	void bossFirePattern(Enemy* enemy);
	void bossPatternOne(Enemy* enemy);
	void bossPatternTwo(Enemy* enemy);
	void bossPatternThree(Enemy* enemy);
	void bossPatternFour(Enemy* enemy);
	void bossPatternFive(Enemy* enemy);
	void fireInCircle(sf::Texture* bulletTexture, sf::FloatRect bulletHitbox, float offSet);
	void fireClusterShot(Enemy* enemy);

	void waveOne();
	void waveTwo();
	void waveThree();
	void waveFour();
	void waveFive();
	void waveSix();
	void waveSeven();
	void waveEight();
	void waveNine();
	void bossWave();

	//void spawnEnemies();
	void run();
};

#endif