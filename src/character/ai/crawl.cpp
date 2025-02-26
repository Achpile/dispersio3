#include "meta/headers.hpp"


/***********************************************************************
     * AICrawl
     * constructor

***********************************************************************/
ach::AICrawl::AICrawl(ach::Character *_owner, json_t *obj) : AI(_owner, obj)
{
}



/***********************************************************************
     * AICrawl
     * destructor

***********************************************************************/
ach::AICrawl::~AICrawl()
{
}



/***********************************************************************
     * AICrawl
     * control

***********************************************************************/
void ach::AICrawl::control()
{
	ground();
}



/***********************************************************************
     * AICrawl
     * reset

***********************************************************************/
void ach::AICrawl::reset()
{
	owner->phys.acc.y = PHYS_GRAVITY;
}



/***********************************************************************
     * AICrawl
     * collide

***********************************************************************/
void ach::AICrawl::collide(ach::PhysLine*)
{
}
