#include "meta/headers.hpp"


/***********************************************************************
     * handlerLanguage

***********************************************************************/
void handlerLanguage(json_t *)
{
	lang->refresh();
	app->state->translate();
}



/***********************************************************************
     * handlerFullscreen

***********************************************************************/
void handlerFullscreen(json_t *)
{
	app->create();
}



/***********************************************************************
     * handlerAudio

***********************************************************************/
void handlerAudio(json_t *)
{
	sm->volume();
}



/***********************************************************************
     * handlerState

***********************************************************************/
void handlerState(json_t *data)
{
	app->stateSet((ach::GameState)pair_get_enum(json_string_value(data), pairGameState));
}
