#include "meta/headers.hpp"


/***********************************************************************
     * Map
     * collide

***********************************************************************/
void ach::Map::collide()
{
	list_foreach(characters)
		collidePhysSteps(&characters[i]->phys);

	list_foreach(projectiles)
		collideProjectile(projectiles[i]);

	list_foreach(characters)
		collideCharacter(characters[i]);
}



/***********************************************************************
     * Map
     * collidePhysSteps

***********************************************************************/
void ach::Map::collidePhysSteps(ach::Phys *phys)
{
	phys->grounded = false;

	float left = tm->frame;
	float velocity;
	float chunk;

	phys->vel  += phys->acc * tm->frame;
	phys->vel.x = interval_set(phys->vel.x, -PHYS_MAX_VEL, PHYS_MAX_VEL);
	phys->vel.y = interval_set(phys->vel.y, -PHYS_MAX_VEL, PHYS_MAX_VEL);


	while (left > 0.0f)
	{
		velocity = vector_len(phys->vel);
		chunk    = (velocity == 0.0f) ? left : 1.5f / velocity;

		if (chunk > left)
			chunk = left;

		phys->pos += phys->vel * chunk;
		phys->calc();

		while (collidePhys(phys));

		left -= chunk;
	}

	phys->calc();
}



/***********************************************************************
     * Map
     * collidePhys

***********************************************************************/
bool ach::Map::collidePhys(ach::Phys *phys)
{
	std::vector<ach::PhysLine*> list;

	collision->fill(&list, &phys->rect);
	collision->sort(&list, phys);

	if (!list.size()) return false;

	list_foreach(list)
		if (list[i]->collide(phys))
			return true;

	return false;
}



/***********************************************************************
     * Map
     * collideProjectile

***********************************************************************/
bool ach::Map::collideProjectile(ach::Projectile *projectile)
{
	list_foreach(characters)
		if (characters[i]->hit(projectile))
			return true;


	std::vector<ach::PhysLine*> list;

	collision->fill(&list, &projectile->line.r);
	collision->sort(&list, &projectile->line);

	list_foreach(list)
	{
		if (list[i]->collide(&projectile->line))
		{
			projectile->phys.pos = projectile->line.b;
			projectile->hit(vector_alike(list[i]->line.n, -projectile->line.v));
			return true;
		}
	}

	return false;
}



/***********************************************************************
     * Map
     * collideCharacter

***********************************************************************/
bool ach::Map::collideCharacter(ach::Character *character)
{
	if (character->enemy)
		return false;

	if (!character->alive)
		return false;

	sf::Vector2f c;
	sf::Vector2f n;

	list_foreach(characters)
	{
		if (!characters[i]->alive)
			continue;

		if (character->enemy == characters[i]->enemy)
			continue;

		if (collision_box_vs_box(character->phys.rect, characters[i]->phys.rect, &c, &n))
		{
			character->damage(1, c, n);
			return true;
		}
	}

	return false;
}
