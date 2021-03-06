#ifndef BULLET_H
#define BULLET_H

#include "entity.h"

class Bullet : public Entity
{
private:
	sf::Vector2f direction;
	sf::Vector2f basePlayerPos;
	int type;
	int maxBounce;
public:
	Bullet();
	Bullet(sf::Texture& texture, int bulletType, sf::FloatRect newHitbox, sf::Vector2f pos, float angle, sf::Vector2f dir, float movementSpeed);
	virtual ~Bullet();

	//accessor
	const int getType() const;
	const sf::Vector2f getBasePlayerPos() const;
	const int getMaxBounce() const;
	const sf::Vector2f getDir() const;

	//mutator
	void setBasePlayerPos(sf::Vector2f newPlayerPos);
	void setMaxBounce(int newMaxBounce);
	void setDir(sf::Vector2f newDir);

	void update();
};

#endif