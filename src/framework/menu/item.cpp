#include "meta/headers.hpp"


/***********************************************************************
     * MenuItem
     * constructor

***********************************************************************/
ach::MenuItem::MenuItem()
{
}



/***********************************************************************
     * MenuItem
     * destructor

***********************************************************************/
ach::MenuItem::~MenuItem()
{
	listDelete(items);
}
