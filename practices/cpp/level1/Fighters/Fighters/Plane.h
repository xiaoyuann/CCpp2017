#ifndef PLANE_H
#define PLANE_H
#include <SFML/Graphics.hpp>
#include "RTexture.h"
#include "MMusic.h"
#include "Action.h"
class World;
class Plane :public Action
{
public:
	Plane(World *world);
	virtual ~Plane();

protected:
	World *world;
	sf::Texture BOOMP = RTexture::BOOM1;
	sf::Music &BOOM = Music::ENEMY_BOOM;
	sf::Music &FIRE = Music::Fire;
private:
};

#endif // PLANE_H
