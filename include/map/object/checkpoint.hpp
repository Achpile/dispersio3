#ifndef __MAP_OBJECT_CHECKPOINT
#define __MAP_OBJECT_CHECKPOINT


namespace ach
{
	struct MapObjectCheckpoint : MapObject
	{
		ach::Map *map;

		bool active;


		 MapObjectCheckpoint(ach::ProcessWorld *_world, json_t *obj);
		~MapObjectCheckpoint();

		void touch();

		void animate();
	};
}

#endif
