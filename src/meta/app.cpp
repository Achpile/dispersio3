#include "meta/headers.hpp"


/***********************************************************************
     * App
     * constructor

***********************************************************************/
ach::App::App()
{
	isRunning = true;
	isFocused = true;

	create();
}



/***********************************************************************
     * App
     * destructor

***********************************************************************/
ach::App::~App()
{
	delete window;
}



/***********************************************************************
     * App
     * update

***********************************************************************/
void ach::App::update()
{
	events();

	isFocused = window->hasFocus();
	isRunning = window->isOpen();

	if (!isFocused)
		return;

	window->clear();
	window->display();
}



/***********************************************************************
     * App
     * events

***********************************************************************/
void ach::App::events()
{
	sf::Event e;

	while (window->pollEvent(e))
		event(e);
}



/***********************************************************************
     * App
     * event

***********************************************************************/
void ach::App::event(sf::Event e)
{
	switch(e.type) {
		case sf::Event::Closed:
			window->close();
			break;


		case sf::Event::Resized:
			resize();
			break;


		default:
			break;
	}
}



/***********************************************************************
     * App
     * resize

***********************************************************************/
void ach::App::resize()
{
}



/***********************************************************************
     * App
     * create

***********************************************************************/
void ach::App::create()
{
	window = new sf::RenderWindow(sf::VideoMode(1280, 800, 32), // settings->getWindowMode
	                              PROJECT_NAME " v" PROJECT_VERS,
	                              sf::Style::Default);          // settings->getWindowStyle

	window->setMouseCursorVisible(true);
	window->setFramerateLimit(60);
	window->setVerticalSyncEnabled(true);

	// center window

	// set window icon
}
