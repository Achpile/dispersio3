#ifndef __META_DEFINES
#define __META_DEFINES


/***********************************************************************
     * Project

***********************************************************************/
#define PROJECT_NAME       "Dispersio 3"
#define PROJECT_VERS       "0.1.2"



/***********************************************************************
     * Sizes

***********************************************************************/
#define RENDER_LAYER_BG_X  640
#define RENDER_LAYER_BG_Y  400

#define RENDER_LAYER_GUI_X 1280
#define RENDER_LAYER_GUI_Y 800



/***********************************************************************
     * Files

***********************************************************************/
#define FILE_SETTINGS      "settings.json"



/***********************************************************************
     * Strings

***********************************************************************/
#define STR_LEN_MENU       32
#define STR_LEN_NAME       128
#define STR_LEN_PATH       256
#define STR_LEN_LOG        512



/***********************************************************************
     * Regex

***********************************************************************/
#define PATH_BASE        "data/base"



/***********************************************************************
     * Regex

***********************************************************************/
#define STR_REGEX_NAME     "^[[:alnum:]_-]{1,128}$"
#define STR_REGEX_COLOR    "^#[[:xdigit:]]{2}{3,4}$"



/***********************************************************************
     * Menu

***********************************************************************/
#define MENU_PADDING       10
#define MENU_THICKNESS    -1
#define MENU_BOX_SHRINK    8
#define MENU_SLIDER_SIZE   5

#endif
