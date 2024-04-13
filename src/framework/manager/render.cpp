#include "meta/headers.hpp"


/***********************************************************************
     * RenderManager
     * constructor

***********************************************************************/
ach::RenderManager::RenderManager()
{
	bg  = new ach::Layer(RENDER_LAYER_BG_X , RENDER_LAYER_BG_Y );
	gui = new ach::Layer(RENDER_LAYER_GUI_X, RENDER_LAYER_GUI_Y);
}



/***********************************************************************
     * RenderManager
     * destructor

***********************************************************************/
ach::RenderManager::~RenderManager()
{
	delete bg;
	delete gui;
}



/***********************************************************************
     * RenderManager
     * getLayer

***********************************************************************/
ach::Layer* ach::RenderManager::getLayer(ach::RenderLayer layer)
{
	switch (layer)
	{
		case ach::RenderLayer::rlBG : return bg;
		case ach::RenderLayer::rlGUI: return gui;
		default                     : return NULL;
	}
}



/***********************************************************************
     * RenderManager
     * draw

***********************************************************************/
void ach::RenderManager::draw(sf::Drawable *drawable, ach::RenderLayer layer, sf::RenderStates states)
{
	getLayer(layer)->draw(drawable, states);
}



/***********************************************************************
     * RenderManager
     * clear

***********************************************************************/
void ach::RenderManager::clear()
{
	bg->clear(sf::Color::Black);
	gui->clear(sf::Color::Transparent);
}



/***********************************************************************
     * RenderManager
     * display

***********************************************************************/
void ach::RenderManager::display(sf::RenderWindow *window)
{
	bg->display();
	gui->display();

	bg->render(window);
	gui->render(window);
}



/***********************************************************************
     * RenderManager
     * resize

***********************************************************************/
void ach::RenderManager::resize(sf::RenderWindow *window)
{
	window->setView(sf::View(sf::FloatRect(0, 0, window->getSize().x, window->getSize().y)));

	bg->resize(window);
	gui->resize(window);
}
