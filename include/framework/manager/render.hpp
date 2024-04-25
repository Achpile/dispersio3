#ifndef __FRAMEWORK_MANAGER_RENDER
#define __FRAMEWORK_MANAGER_RENDER


namespace ach
{
	enum RenderLayer
	{
		rlBG,
		rlGame,
		rlGUI
	};


	struct RenderManager
	{
		ach::Layer *bg;
		ach::Layer *game;
		ach::Layer *gui;


		 RenderManager();
		~RenderManager();

		void clear();
		void display(sf::RenderWindow *window);
		void resize(sf::RenderWindow *window);

		void draw(sf::Drawable *drawable, ach::RenderLayer layer = ach::RenderLayer::rlGUI, sf::RenderStates states = sf::RenderStates::Default);

		ach::Layer   *getLayer(ach::RenderLayer layer);
		sf::Vector2f  transform(sf::Vector2f v, ach::RenderLayer layer);
	};
}

#endif
