#include "meta/headers.hpp"


/***********************************************************************
     * MenuItemBack
     * constructor

***********************************************************************/
ach::MenuItemBack::MenuItemBack(ach::Menu *_menu, const char *_name) : MenuItem(_menu, _name)
{
}



/***********************************************************************
     * MenuItemBack
     * destructor

***********************************************************************/
ach::MenuItemBack::~MenuItemBack()
{
}



/***********************************************************************
     * MenuItemBack
     * action

***********************************************************************/
void ach::MenuItemBack::action()
{
	if (parent->parent)
		menu->go(parent->parent, parent);
	else
		menu->isActive = false;
}



/***********************************************************************
     * MenuItemBack
     * pick

***********************************************************************/
void ach::MenuItemBack::pick()
{
	action();
}



/***********************************************************************
     * MenuItemBack
     * click

***********************************************************************/
void ach::MenuItemBack::click()
{
	action();
}