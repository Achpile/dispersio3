#include "meta/headers.hpp"


/***********************************************************************
     * Projectile
     * constructor

***********************************************************************/
ach::Projectile::Projectile(ach::DataProjectile *_base, sf::Vector2f pos)
{
	base    = _base;
	flip    = false;
	alive   = true;
	angle   = 0.0f;
	bounces = base->bounces;
	model   = new ach::Model(base->sheet);
	tracer  = ach::Tracer::create(base->tracer, &phys);

	phys.init(sf::Vector2f(0.0f, 0.0f));
	phys.pos = pos;

	model->setScale(base->scale);
	model->setColor(base->color);

	tracer->color = base->colorTracer;
	tracer->init();

	if (flag_get(base->flags, ach::ProjectileFlag::pfGravity))
		phys.acc.y = PHYS_GRAVITY / 4.0f;
}



/***********************************************************************
     * Projectile
     * destructor

***********************************************************************/
ach::Projectile::~Projectile()
{
	delete model;
	delete tracer;
}



/***********************************************************************
     * Projectile
     * update

***********************************************************************/
bool ach::Projectile::update()
{
	phys.update();
	model->update();
	tracer->update();

	rotation();
	direction();

	return alive;
}



/***********************************************************************
     * Projectile
     * render

***********************************************************************/
void ach::Projectile::render()
{
	tracer->render();
	model->render(phys.pos);
}



/***********************************************************************
     * Projectile
     * rotation

***********************************************************************/
void ach::Projectile::rotation()
{
	if (!flag_get(base->flags, ach::ProjectileFlag::pfRotation))
		return;

	angle += phys.vel.x * tm->frame * 4.0f;

	model->angle = angle;
}



/***********************************************************************
     * Projectile
     * direction

***********************************************************************/
void ach::Projectile::direction()
{
	if (!flag_get(base->flags, ach::ProjectileFlag::pfDirection))
		return;

	if (vector_len(phys.vel) == 0.0f)
		return;

	angle = MATH_DEG * vector_angle(phys.vel);

	if (flip)
	{
		model->scale.x = -1.0f;
		model->angle   = 180 - angle;
	}
	else
	{
		model->scale.x = 1.0f;
		model->angle   = angle;
	}
}



/***********************************************************************
     * Projectile
     * hit

***********************************************************************/
void ach::Projectile::hit()
{
}
