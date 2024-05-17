#include "meta/headers.hpp"


/***********************************************************************
     * Database
     * constructor

***********************************************************************/
ach::Database::Database()
{
}



/***********************************************************************
     * Database
     * destructor

***********************************************************************/
ach::Database::~Database()
{
	listDelete(sheet);
	listDelete(model);
	listDelete(projectile);
	listDelete(weapon);
}



/***********************************************************************
     * loadContent

***********************************************************************/
template<class T> void loadContent(const char *section, std::vector<T*> *list) {
	json_t     *obj;
	const char *key;

	json_object_foreach(json_object_getv_branch(dm->data, "Data.%s", section), key, obj)
	{
		list->push_back(new T(obj));
		strncpy(list->back()->name, key, STR_LEN_NAME);
	}
}



/***********************************************************************
     * Database
     * load

***********************************************************************/
void ach::Database::load()
{
	loadContent<ach::DataSheet     >("Sheet"     , &sheet     );
	loadContent<ach::DataModel     >("Model"     , &model     );
	loadContent<ach::DataProjectile>("Projectile", &projectile);
	loadContent<ach::DataWeapon    >("Weapon"    , &weapon    );
}
