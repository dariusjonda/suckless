//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  // DO NOT INPUT API TOKENS
	{"", "/bin/bash ~/.config/dwmhelper/ipinfo.sh && tail -n1 ~/.config/dwmhelper/log",	30,		0},
	{"", "curl -s wttr.in/Berlin?format=1", 600, 0},
	{"⚡", "db_battery", 30, 0},
  {"", "upower -i $(upower -e | grep 'BAT') | grep energy-rate | awk '{print $2 $3}'", 30, 0}, 
	{"", "db_volume", 1, 0},
	{"", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	600,		0},
	{"GPU ", "sensors | grep edge | awk '{print $2}'",	5,		0},
	{"CPU ", "sensors | grep Tctl | awk '{print $2}'",	5,		0},
	{"/ ", "df -h /dev/mapper/cryptroot | tail -n 1 | awk {'print $5'}",	600,		0},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
