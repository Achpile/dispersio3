#ifndef __GFX_IMPACT_BASE
#define __GFX_IMPACT_BASE


namespace ach
{
	struct Impact : Effect
	{
		sf::Vector2f pos;
		sf::Vector2f dir;
		sf::Color    color;


		         Impact(sf::Vector2f _pos, sf::Vector2f _dir, sf::Color _color);
		virtual ~Impact();

		virtual bool update();
		virtual void render() {};
	};
}

#endif
