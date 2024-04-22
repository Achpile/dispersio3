#ifndef __META_HEADERS
#define __META_HEADERS

#include <sys/stat.h>

#include <jansson.h>
#include <string.h>
#include <libgen.h>
#include <regex.h>
#include <math.h>

#include <random>
#include <ctime>
#include <experimental/filesystem>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


#include "meta/defines.hpp"
#include "meta/forward.hpp"

#include "framework/string/pair.hpp"
#include "framework/string/option.hpp"
#include "framework/string/check.hpp"
#include "framework/string/regex.hpp"
#include "framework/string/color.hpp"
#include "framework/string/utf8.hpp"

#include "framework/log/base.hpp"
#include "framework/log/pair.hpp"

#include "framework/misc/arch.hpp"
#include "framework/misc/flag.hpp"
#include "framework/misc/handler.hpp"
#include "framework/misc/list.hpp"
#include "framework/misc/file.hpp"

#include "framework/math/base.hpp"
#include "framework/math/interval.hpp"
#include "framework/math/random.hpp"
#include "framework/math/vector.hpp"

#include "framework/time/timer.hpp"
#include "framework/time/framer.hpp"

#include "framework/json/branch.hpp"
#include "framework/json/merge.hpp"
#include "framework/json/macros.hpp"

#include "framework/datamodel/directive.hpp"
#include "framework/datamodel/attr.hpp"
#include "framework/datamodel/pair.hpp"
#include "framework/datamodel/trait.hpp"
#include "framework/datamodel/type.hpp"
#include "framework/datamodel/check.hpp"
#include "framework/datamodel/default.hpp"
#include "framework/datamodel/preprocessor.hpp"
#include "framework/datamodel/base.hpp"

#include "framework/control/key.hpp"
#include "framework/control/pad.hpp"
#include "framework/control/pair.hpp"

#include "framework/gfx/sprite.hpp"
#include "framework/gfx/sheet.hpp"
#include "framework/gfx/layer.hpp"

#include "framework/manager/render.hpp"
#include "framework/manager/sound.hpp"
#include "framework/manager/time.hpp"

#include "framework/text/align.hpp"
#include "framework/text/draw.hpp"

#include "framework/menu/item.hpp"
#include "framework/menu/action.hpp"
#include "framework/menu/back.hpp"
#include "framework/menu/checkbox.hpp"
#include "framework/menu/control.hpp"
#include "framework/menu/folder.hpp"
#include "framework/menu/list.hpp"
#include "framework/menu/slider.hpp"
#include "framework/menu/base.hpp"

#include "framework/particle/base.hpp"
#include "framework/particle/system.hpp"

#include "misc/handler.hpp"

#include "particle/stars.hpp"

#include "container/resources.hpp"
#include "container/settings.hpp"
#include "container/background.hpp"
#include "container/language.hpp"

#include "process/base.hpp"
#include "process/world.hpp"

#include "state/base.hpp"
#include "state/pair.hpp"
#include "state/start.hpp"
#include "state/menu.hpp"
#include "state/game.hpp"
#include "state/credits.hpp"

#include "meta/app.hpp"
#include "meta/externs.hpp"

#endif
