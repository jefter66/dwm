/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */

static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */

static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */

static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "Liberation Mono:size=12", "JoyPixels:pixelsize=10:antialias=true:autohint=true"  };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#15202B";
static const char active_border[]   = "#9F34BB";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,   active_border },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5"};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,      0,            1,           -1 },
	{ "Brave",  NULL,       NULL,       1 << 9,       0,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 9,       0,           -1 },
	{ "Chrome",  NULL,       NULL,       1 << 9,       0,           -1 },
	{ "Thunar",  NULL,       NULL,       1 << 9,       1,           -1 },
	{ "St",  NULL,   "pulsemixer",       1 << 9,       1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define ALTKEY Mod1Mask
#define MODKEY Mod4Mask


#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

static const char *emacs[]  = { "emacs", NULL };
static const char *brave[]  = { "brave", NULL };
static const char *chrome[]  = { "google-chrome-stable", NULL };
static const char *thunar[]  = { "thunar", NULL };
static const char *nitrogen[]  = {"nitrogen", NULL };
static const char *xreader[]  = { "xreader", NULL };
static const char *keepassxc[]  = { "keepassxc", NULL };
static const char *pavucontrol[]  = { "pavucontrol", NULL };
static const char *power_manager[]  = { "mate-power-preferences", NULL };
static const char *alarm_clock_applet[]  = { "alarm-clock-applet", NULL };
static const char *spotify[]  = { "spotify-tray", NULL };
static const char *xournalpp[]  = { "xournalpp", NULL };


//static const char *xournalpp[]  = { "xournalpp /home/jefter66/Dropbox/.xournalpp/template.xopp", NULL };

#include "movestack.c"
static Key keys[] = {

  /* movestack */
  { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },

	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },

	{ MODKEY|ShiftMask,             XK_e, spawn,          {.v = emacs} },
	{ MODKEY|ShiftMask,             XK_f, spawn,          {.v = brave} },
	{ MODKEY|ShiftMask,             XK_b, spawn,          {.v = chrome } },
	{ MODKEY|ShiftMask,             XK_n, spawn,          {.v = nitrogen } },
	{ MODKEY|ShiftMask,             XK_c, spawn,          {.v = thunar } },
	{ MODKEY|ShiftMask,             XK_p, spawn,          {.v = keepassxc}},
	{ MODKEY|ShiftMask,             XK_a, spawn,          {.v = alarm_clock_applet}},
	{ MODKEY|ShiftMask,             XK_x, spawn,          {.v = xournalpp}},
	{ MODKEY|ShiftMask,             XK_s, spawn,          {.v = spotify}},

	{ ALTKEY|ShiftMask,             XK_b, spawn,          {.v = power_manager}},
	{ ALTKEY|ShiftMask,             XK_v, spawn,          {.v = pavucontrol}},
	{ ALTKEY|ShiftMask,             XK_f, spawn,          {.v = xreader } },

    // Having to use xterm for now bc somehow st doesn't show pdf preview and idk i
	{ MODKEY|ShiftMask,	  	        XK_r,			spawn,		SHCMD("xterm -e ranger") },
	{ MODKEY|ShiftMask,	  	        XK_m,			spawn,		SHCMD("st -e ncmpcpp") },

	{ ALTKEY|ShiftMask,	  	        XK_p,			spawn,		SHCMD("st -e pulsemixer") },
	{ ALTKEY|ShiftMask,	  	        XK_r,			spawn,		SHCMD("st -e julia") },
//	{ MODKEY|ShiftMask,	  	        XK_x,			spawn,		SHCMD("xournalpp /home/jefter66/Dropbox/.xournalpp/template.xopp") },
	{0,	  	                        XK_Print,			spawn,  SHCMD("mate-screenshot -a") },

    /** gaps **/
    
    { ALTKEY|ShiftMask,      XK_0,      defaultgaps,    {0} },

    { MODKEY|ShiftMask,             XK_h,      incrgaps,       {.i = +5 } },
    { MODKEY|ShiftMask,             XK_l,      incrgaps,       {.i = -5 } },
    { ALTKEY|ShiftMask,             XK_h,      incrogaps,      {.i = +15 } },
    { ALTKEY|ShiftMask,             XK_l,      incrogaps,      {.i = -15 } },
//  { MODKEY|ALTKEY|ControlMask,    XK_h,      incrigaps,      {.i = +1 } },
//  { MODKEY|ALTKEY|ControlMask,    XK_l,      incrigaps,      {.i = -1 } },
//  { MODKEY|ALTKEY,                XK_0,      togglegaps,     {0} },
//  { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
//  { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
//  { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
//  { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
//  { MODKEY|ALTKEY,                XK_y,      incrohgaps,     {.i = +1 } },
//  { MODKEY|ALTKEY,                XK_o,      incrohgaps,     {.i = -1 } },
//  { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
//  { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },


	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
//	TAGKEYS(                        XK_6,                      5)
//	TAGKEYS(                        XK_7,                      6)
//	TAGKEYS(                        XK_8,                      7)
//	TAGKEYS(                        XK_9,                      8)
	{ MODKEY,             XK_F12,      quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
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