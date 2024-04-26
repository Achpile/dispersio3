#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * constructor

***********************************************************************/
ach::Map::Map(const char *filename)
{
	load(filename);
}



/***********************************************************************
     * Map
     * destructor

***********************************************************************/
ach::Map::~Map()
{
	for (int x = 0; x < sizeMap.x; x++)
	{
		for (int y = 0; y < sizeMap.y; y++)
			delete tiles[x][y];

		delete tiles[x];
	}

	delete tiles;
	delete tileset;
}



/***********************************************************************
     * Map
     * update

***********************************************************************/
void ach::Map::update()
{
}



/***********************************************************************
     * Map
     * render

***********************************************************************/
void ach::Map::render()
{
	bg->stars->update();
	renderTiles();
}



/***********************************************************************
     * Map
     * renderTiles

***********************************************************************/
void ach::Map::renderTiles()
{
	for (int x = 0; x < sizeMap.x; x++)
		for (int y = 0; y < sizeMap.y; y++)
			tiles[x][y]->render(vector_mult(sizeTile, sf::Vector2i(x, y)));
}
