#include "meta/headers.hpp"


/***********************************************************************
     * Datamodel
     * constructor

***********************************************************************/
ach::Datamodel::Datamodel()
{
	traits = json_preprocess_dir("traits", "data/dm");
	dm     = json_preprocess_include("main.json", "data/dm/model");

	json_dm_trait_process(dm, traits);

	load();

	json_dump_file(dm, "test.json", JSON_INDENT(4) | JSON_SORT_KEYS);
}



/***********************************************************************
     * Datamodel
     * destructor

***********************************************************************/
ach::Datamodel::~Datamodel()
{
	json_decref(data);
	json_decref(traits);
	json_decref(dm);
}



/***********************************************************************
     * Datamodel
     * load

***********************************************************************/
void ach::Datamodel::load()
{
	data = json_dm_generate_default(NULL, dm);

	loadPath("data/base");
}



/***********************************************************************
     * Datamodel
     * loadPath

***********************************************************************/
void ach::Datamodel::loadPath(const char *path)
{
	logger->log(ach::llInfo, "Loading data from: \"%s\"", path);

	json_t *pack = json_preprocess_include("json/main.json", path);

	json_dm_check_datatypes(pack, dm, path);
	json_merge(data, pack);
	json_dm_check_links(data, data, dm);
	json_dm_generate_default(data, dm);

	json_decref(pack);
}