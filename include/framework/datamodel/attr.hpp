#ifndef __FRAMEWORK_DATAMODEL_ATTR
#define __FRAMEWORK_DATAMODEL_ATTR


namespace ach
{
	enum JSONtype
	{
		jtUnknown,
		jtObject,
		jtString,
		jtInteger,
		jtBoolean,
		jtFilename,
		jtColor,
		jtArray,
		jtMulti,
		jtLink
	};
}


ach::JSONtype  json_attr_get_type(json_t *obj);
json_t        *json_attr_get_default(json_t *obj);
size_t         json_attr_get_maxlen(json_t *obj);
int            json_attr_get_min(json_t *obj);
int            json_attr_get_max(json_t *obj);
const char    *json_attr_get_dir(json_t *obj);
const char    *json_attr_get_data(json_t *obj);

#endif
