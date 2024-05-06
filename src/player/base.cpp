#include "meta/headers.hpp"


/***********************************************************************
     * Player
     * constructor

***********************************************************************/
ach::Player::Player()
{
	character = new ach::Character(sf::Vector2f(16.0f, 16.0f));

	legs = new ach::Model(db->getModel("PlayerLegs"));
	body = new ach::Model(db->getModel("PlayerBody"));

	character->models.push_back(legs);
	character->models.push_back(body);
}



/***********************************************************************
     * Player
     * destructor

***********************************************************************/
ach::Player::~Player()
{
}



/***********************************************************************
     * Player
     * update

***********************************************************************/
void ach::Player::update()
{
	character->update();
}



/***********************************************************************
     * Player
     * render

***********************************************************************/
void ach::Player::render()
{
	character->render();
}



/***********************************************************************
     * Player
     * reset

***********************************************************************/
void ach::Player::reset()
{
	legs->setAnimation("Idle");
	body->setAnimation("Front");

	dir = sf::Vector2i(1, 0);

	character->reset();
}



/***********************************************************************
     * Player
     * respawn

***********************************************************************/
void ach::Player::respawn(sf::Vector2f spawn)
{
	character->phys.pos = spawn;

	reset();
}
