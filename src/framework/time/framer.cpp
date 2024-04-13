#include "meta/headers.hpp"


/***********************************************************************
     * Framer
     * constructor

***********************************************************************/
ach::Framer::Framer(float _timer)
{
	_timer = _timer;

	reset();
}



/***********************************************************************
     * Framer
     * destructor

***********************************************************************/
ach::Framer::~Framer()
{
}



/***********************************************************************
     * Framer
     * update

***********************************************************************/
void ach::Framer::update(bool real)
{
	value -= real ? tm->real : tm->frame;

	while (value < 0.0f)
	{
		value += timer;
		frame++;
	}
}



/***********************************************************************
     * Framer
     * reset

***********************************************************************/
void ach::Framer::reset()
{
	frame = 0;
	value = timer;
}
