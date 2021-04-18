/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int bottom = 1;
static int embedded = 1;
static int minpwlen = 10;
static int mon = -1;

static const char *asterisk = "*";
static const char *fonts[] = {
	"FiraCode-Regular:size=30"
};
static const char *prompt = NULL;
static const char *colors[SchemeLast][4] = {
	[SchemePrompt] = { "#bbbbbb", "#222222" },
	[SchemeNormal] = { "#000000", "#A2BD8B" },
	[SchemeSelect] = { "#eeeeee", "#005577" },
	[SchemeDesc]   = { "#bbbbbb", "#222222" }
};
