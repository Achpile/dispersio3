#ifndef __MAP_BASE
#define __MAP_BASE


namespace ach
{
	struct Map
	{
		ach::MapTile ***tiles;
		ach::Tileset   *tileset;
		sf::Vector2i    size;


		 Map(const char *filename);
		~Map();

		void update();
		void render();

		void renderTiles();

		void load(const char *filename);
		void loadMeta(json_t *mapdata);
		void loadInit();
		void loadTileset(json_t *mapdata, const char *path);
		void loadLayers(json_t *mapdata);
		void loadLayerTiles(json_t *layer);
	};
}

#endif
