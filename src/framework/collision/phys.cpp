#include "meta/headers.hpp"


/***********************************************************************
     * Phys
     * update

***********************************************************************/
void ach::Phys::update()
{
	vel += acc * tm->frame;
	pos += vel * tm->frame;

	calc();
}



/***********************************************************************
     * Phys
     * calc

***********************************************************************/
void ach::Phys::calc()
{
	rect.left = pos.x - rect.width  / 2.0f;
	rect.top  = pos.y - rect.height / 2.0f;
}



/***********************************************************************
     * Phys
     * init

***********************************************************************/
void ach::Phys::init(sf::Vector2f _size)
{
	size = _size;
	rect = sf::FloatRect(sf::Vector2f(0.0f, 0.0f), size);

	reset();
}



/***********************************************************************
     * Phys
     * reset

***********************************************************************/
void ach::Phys::reset()
{
	acc = sf::Vector2f(0.0f, 0.0f);
	vel = sf::Vector2f(0.0f, 0.0f);

	grounded = true;
	moving   = false;
	jumpdown = false;

	calc();
}
