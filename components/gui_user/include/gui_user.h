/* gui_user.h */

typedef enum {
    USRCMD_GOTOMAINMENU = 0,
    USRCMD_SETDIRECTION,
    USRCMD_STOPSTEPPER,
    USRCMD_ADDDIRECTION,
    USRCMD_EXIT,
    USRCMD_INVALID
} userCommands_e;