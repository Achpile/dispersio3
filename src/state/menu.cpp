#include "meta/headers.hpp"


/***********************************************************************
     * StateMenu
     * constructor

***********************************************************************/
ach::StateMenu::StateMenu()
{
	menu = new ach::Menu("Main");

	menu->setPosition(sf::Vector2f(100.0f, 100.0f));
	menu->setWidth(400.0f);
	menu->setHeight(6);

	fill();
}



/***********************************************************************
     * StateMenu
     * destructor

***********************************************************************/
ach::StateMenu::~StateMenu()
{
	delete menu;
}



/***********************************************************************
     * StateMenu
     * update

***********************************************************************/
void ach::StateMenu::update()
{
	if (!menu->isActive)
		app->isRunning = false;

	render();

	menu->controls();
	menu->update();
}



/***********************************************************************
     * StateMenu
     * render

***********************************************************************/
void ach::StateMenu::render()
{
	bg->stars->update();
}



/***********************************************************************
     * StateMenu
     * event

***********************************************************************/
void ach::StateMenu::event(sf::Event e)
{
	switch(e.type)
	{
		case sf::Event::MouseMoved:
			hover(rm->transform(sf::Vector2f(e.mouseMove.x, e.mouseMove.y), ach::RenderLayer::rlGUI));
			break;


		case sf::Event::MouseButtonReleased:
			if ((e.mouseButton.button != sf::Mouse::Button::Left) && (e.mouseButton.button != sf::Mouse::Button::Right))
				break;

			click(rm->transform(sf::Vector2f(e.mouseButton.x, e.mouseButton.y), ach::RenderLayer::rlGUI), e.mouseButton.button == sf::Mouse::Button::Left);
			break;


		default:
			break;
	}
}



/***********************************************************************
     * StateMenu
     * hover

***********************************************************************/
void ach::StateMenu::hover(sf::Vector2f pos)
{
	menu->hover(pos);
}



/***********************************************************************
     * StateMenu
     * click

***********************************************************************/
void ach::StateMenu::click(sf::Vector2f pos, bool left)
{
	menu->click(pos, left);
}



/***********************************************************************
     * StateMenu
     * fill

***********************************************************************/
void ach::StateMenu::fill()
{
	menu->add("Main"   , new ach::MenuItemFolder  (menu, "Start"     ));
	menu->add("Main"   , new ach::MenuItemFolder  (menu, "Options"   ));
	menu->add("Main"   , new ach::MenuItemAction  (menu, "Credits"   ));

	menu->add("Options", new ach::MenuItemFolder  (menu, "Game"      ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Video"     ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Audio"     ));
	menu->add("Options", new ach::MenuItemFolder  (menu, "Controls"  ));

	menu->add("Game"   , new ach::MenuItemList    (menu, "Language"  ));

	menu->add("Audio"  , new ach::MenuItemSlider  (menu, "Sound"     , 0, 10));
	menu->add("Audio"  , new ach::MenuItemSlider  (menu, "Music"     , 0, 10));

	menu->add("Video"  , new ach::MenuItemCheckbox(menu, "Fullscreen"));
	menu->add("Video"  , new ach::MenuItemCheckbox(menu, "Aspect"    ));
	menu->add("Video"  , new ach::MenuItemCheckbox(menu, "Smooth"    ));

	menu->finalize();
}
