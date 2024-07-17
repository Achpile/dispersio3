#include "meta/headers.hpp"


/***********************************************************************
     * Impact
     * constructor

***********************************************************************/
ach::Impact::Impact(sf::Vector2f _pos, sf::Vector2f _dir, sf::Color _color)
{
	pos   = _pos;
	dir   = _dir;
	color = _color;
}



/***********************************************************************
     * Impact
     * destructor

***********************************************************************/
ach::Impact::~Impact()
{
}



/***********************************************************************
     * Impact
     * update

***********************************************************************/
bool ach::Impact::update()
{
	return false;
}