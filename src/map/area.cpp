#include "meta/headers.hpp"


/***********************************************************************
     * MapArea
     * constructor

***********************************************************************/
ach::MapArea::MapArea(json_t *obj)
{
	rect = vector_json_rect(obj);
}



/***********************************************************************
     * MapArea
     * destructor

***********************************************************************/
ach::MapArea::~MapArea()
{
}
