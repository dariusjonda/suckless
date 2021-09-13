/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx    = 3;        /* border pixel of windows */
static const int gappx                = 3;        /* gaps between windows */
static const unsigned int snap        = 0;        /* snap pixel */
static const int swallowfloating      = 0;        /* 1 means swallow floating windows by default */
static const int showbar              = 1;        /* 0 means no bar */
static const int topbar               = 1;        /* 0 means bottom bar */
static const char *fonts[]            = { "FiraCode-Regular:size=15" };
static const char dmenufont[]         = "FiraCode-Regular:size=15";
static const char col_cyan[]          = "#005577";
static const char col_dark_grey[]     = "#030303";
static const char col_green[]         = "#a3be8c";
static const char col_white[]         = "#ffffff";
static const char *colors[][3]      = {
	/*               fg                  bg                   border   */
	[SchemeNorm] = { col_white,          col_dark_grey,       col_dark_grey },
	[SchemeSel]  = { col_green,          col_dark_grey,       col_green },
};

/* tagging */
static const char *tags[] = { "main", "tune", "wiki", "book", "mail", "work", "rest"};

static const Rule rules[] = {
	/* class     instance  title      tags mask  switchtotag  isfloating  iscentered  isterminal  noswallow  monitor */
	{ "st",      NULL,     NULL,           0,         0,  		0,          1,          1,           0,        -1 },
	{ "st",      "pop",    NULL,           0,         0,  		1,          1,          1,           0,        -1 },
	{ "st",      "popmaster", NULL,       -1,         0,  		1,          1,          1,           0,        -1 },
	{ "plexmediaplayer", NULL, NULL,      -1,         0,  		1,          1,          1,           0,        -1 },
	{ "st",      "tune",  NULL,            1 << 1,    1,  		0,          1,          1,           0,        -1 },
	{ "st",      "wiki",  NULL,            1 << 2,    1,  		0,          1,          1,           0,        -1 },
	{ "st",      "ebook",  NULL,           1 << 3,    1,  		0,          1,          1,           0,        -1 },
	{ "st",      "email",  NULL,           1 << 4,    1,  		0,          1,          1,           0,        -1 },
	{ "st",      "vinagre", NULL,          1 << 5,    1,  		0,          1,          1,           0,        -1 },
	{ "st",      "media",  NULL,           1 << 6,    1,  		0,          1,          1,           0,        -1 },
	{ NULL,      NULL,     "Event Tester", 0,         0,  		0,          0,          0,           1,        -1 }, /* xev */
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]          = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, NULL };
static const char *termcmd[]           = { "st", NULL };
static const char *popcmd[]            = { "st", "-n", "pop", "-g", "70x20", "-f", "FiraCode-Regular:size=8", NULL };
static const char *cr_pop[]            = { "st", "-n", "popmaster", "-e", "cr_kiosk", "-tml", NULL };
static const char *waka_pop[]          = { "st", "-n", "popmaster", "-e", "waka_kiosk", "-tml", NULL };
static const char *netflix[]           = { "st", "-n", "media", "-e", "netflix_kiosk", "-tml", NULL };
static const char *netflix_pop[]       = { "st", "-n", "popmaster", "-e", "netflix_kiosk", "-tml", NULL };
static const char *ebook[]             = { "st", "-n", "ebook", "-e", "zathura_ebook", NULL };
static const char *ebookpop[]          = { "st", "-n", "pop", "-e", "zathura_ebook", NULL };
static const char *email[]             = { "st", "-n", "email", "-e", "tutanota-desktop", NULL };
static const char *emailpop[]          = { "st", "-n", "pop", "-g", "70x20", "-f", "FiraCode-Regular:size=8", "-e", "mutt", NULL };
static const char *browsercmd[]        = { "firefox", NULL };
static const char *flameshotgui[]      = { "st", "-e", "flameshot", "gui", NULL };
static const char *plexpop[]           = { "plexmediaplayer", NULL };
static const char *vimwiki[]           = { "st", "-n", "wiki", "-e", "vimwiki", NULL };
static const char *vim[]               = { "st", "-e", "nvim", NULL };
static const char *vimwiki_quick[]     = { "st", "-e", "vimwiki", NULL };
static const char *ranger[]            = { "st", "-e", "ranger", NULL };
static const char *ncmpcpp_tune[]      = { "st", "-n", "tune", "-e", "ncmpcpp", NULL };
static const char *ncmpcpp_pop[]       = { "st", "-n", "pop", "-g", "60x12", "-f", "FiraCode-Regular:size=8", "-e", "ncmpcpp", NULL };
static const char *ytfzf[]             = { "st", "-e", "ytfzf", "-tq", NULL };
static const char *ytfzf_audio_pop[]   = { "st", "-n", "pop", "-f", "FiraCode-Regular:size=8", "-e", "ytfzf", "-mqs", NULL };
static const char *ytfzf_audio_tune[]  = { "st", "-n", "tune", "-e", "ytfzf", "-mqs", NULL };
static const char *ytfzf_subs[]        = { "st", "-e", "ytfzf", "-St", NULL };
static const char *rangerpop[]         = { "st", "-n", "pop", "-e", "ranger", NULL };
static const char *vinagre[]           = { "st", "-n", "vinagre", "-e", "vinagre", NULL };
static const char *suspend[]           = { "/bin/sh", "-c", "systemctl suspend", NULL };
static const char *slock[]             = { "/bin/sh", "-c", "slock", NULL };

#include "movestack.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
	/* modifier                     key                         function        argument */
	{ MODKEY,                       XK_comma,                   focusmon,       {.i = -1 } },
 	{ MODKEY|ShiftMask,             XK_comma,                   tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_period,                  focusmon,       {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_period,                  tagmon,         {.i = +1 } },
 	{ MODKEY|ControlMask,           XK_period,                  setcentered,    {0} },
	{ MODKEY,                       XK_Return,                  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_Return,                  spawn,          {.v = termcmd } },
	{ MODKEY|ControlMask,           XK_Return,                  spawn,          {.v = popcmd } },
  { MODKEY,                       XK_space,                   togglefloating, {0} },
	{ NULL,                         XK_Super_R,                 spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Tab,                     view,           {0} },
	{ MODKEY,                       XK_a,                       spawn,          {.v = cr_pop } },
	{ MODKEY|ShiftMask,             XK_a,                       spawn,          {.v = waka_pop } },
	{ MODKEY,                       XK_b,                       togglebar,      {0} },
	{ MODKEY|ShiftMask,             XK_c,                       killclient,     {0} },
  { MODKEY,                       XK_d,                       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_e,                       spawn,          {.v = email } },
	{ MODKEY|ShiftMask,             XK_e,                       spawn,          {.v = emailpop } },
	{ MODKEY,                       XK_f,                       spawn,          {.v = browsercmd } },
	{ MODKEY|ShiftMask,             XK_f,                       spawn,          {.v = flameshotgui } },
	{ MODKEY,                       XK_g,                       setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_g,                       setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_g,                       setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_h,                       setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_h,                       tagmon,         {.i = -1 } },
	{ MODKEY,                       XK_i,                       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_j,                       focusstack,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_j,                       movestack,      {.i = +1 } },
	{ MODKEY,                       XK_k,                       focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_k,                       movestack,      {.i = -1 } },
	{ MODKEY,                       XK_l,                       setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_l,                       tagmon,         {.i = +1 } },
	{ MODKEY|ControlMask,           XK_l,                       spawn,          {.v = slock } },
	{ MODKEY,                       XK_m,                       spawn,          {.v = ncmpcpp_tune } },
	{ MODKEY|ShiftMask,             XK_m,                       spawn,          {.v = ncmpcpp_pop } },
	{ MODKEY|ControlMask,           XK_m,                       spawn,          {.v = ytfzf_audio_tune } },
	{ MODKEY,                       XK_n,                       spawn,          {.v = netflix } },
	{ MODKEY|ControlMask,           XK_n,                       spawn,          {.v = netflix_pop } },
	{ MODKEY,                       XK_p,                       spawn,          {.v = plexpop } },
	{ MODKEY|ControlMask,           XK_q,                       spawn,          {.v = suspend} },
	{ MODKEY,                       XK_r,                       spawn,          {.v = ranger } },
	{ MODKEY|ShiftMask,             XK_r,                       spawn,          {.v = rangerpop } },
	{ MODKEY,                       XK_s,                       spawn,          SHCMD ("amixer sset Master 5%+ unmute")},
	{ MODKEY|ControlMask,           XK_s,                       spawn,          SHCMD ("amixer sset Master mute")},
	{ MODKEY|ShiftMask,             XK_s,                       spawn,          SHCMD ("amixer sset Master 5%- unmute")},
	{ MODKEY,                       XK_t,                       setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_v,                       spawn,          {.v = vimwiki_quick } },
	{ MODKEY|ShiftMask,             XK_v,                       spawn,          {.v = vimwiki } },
	{ MODKEY|ControlMask,           XK_v,                       spawn,          {.v = vim } },
	{ MODKEY,                       XK_w,                       spawn,          {.v = vinagre } },
	{ MODKEY,                       XK_y,                       spawn,          {.v = ytfzf } },
	{ MODKEY|ShiftMask,             XK_y,                       spawn,          {.v = ytfzf_audio_pop } },
	{ MODKEY|ControlMask,           XK_y,                       spawn,          {.v = ytfzf_subs } },
	{ MODKEY,                       XK_z,                       spawn,          {.v = ebook } },
	{ MODKEY|ShiftMask,             XK_z,                       spawn,          {.v = ebookpop } },
 	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 50y 0w 0h" } },
 	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -50y 0w 0h" } },
 	{ MODKEY,                       XK_Right,  moveresize,     {.v = "50x 0y 0w 0h" } },
 	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-50x 0y 0w 0h" } },
 	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 50h" } },
 	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -50h" } },
 	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 50w 0h" } },
 	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -50w 0h" } },
 	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
 	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
 	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
 	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY,                       XK_0,                       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                       tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                                       0)
	TAGKEYS(                        XK_2,                                       1)
	TAGKEYS(                        XK_3,                                       2)
	TAGKEYS(                        XK_4,                                       3)
	TAGKEYS(                        XK_5,                                       4)
	TAGKEYS(                        XK_6,                                       5)
	TAGKEYS(                        XK_7,                                       6)
	TAGKEYS(                        XK_8,                                       7)
	TAGKEYS(                        XK_9,                                       8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
