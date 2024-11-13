#include "meta/headers.hpp"


/***********************************************************************
     * handler_menu_language

***********************************************************************/
void handler_menu_language(void *, json_t *)
{
	lang->refresh();
	app->state->translate();
}



/***********************************************************************
     * handler_menu_theme

***********************************************************************/
void handler_menu_theme(void *, json_t *)
{
	theme->refresh();
	app->state->style();
}



/***********************************************************************
     * handler_menu_fullscreen

***********************************************************************/
void handler_menu_fullscreen(void *, json_t *)
{
	app->create();
}



/***********************************************************************
     * handler_menu_audio

***********************************************************************/
void handler_menu_audio(void *, json_t *)
{
	sm->volume();
}



/***********************************************************************
     * handler_menu_state

***********************************************************************/
void handler_menu_state(void *, json_t *data)
{
	app->stateSet((ach::GameState)pair_get_enum(json_string_value(data), pairGameState));
}



/***********************************************************************
     * handler_menu_reset

***********************************************************************/
void handler_menu_reset(void *, json_t *)
{
	json_object_del(settings->data, "Control");
	json_dm_generate_default(settings->data, json_object_get(dm->dm, "Settings"));

	ctrl->init();
	ctrl->reset();
}
