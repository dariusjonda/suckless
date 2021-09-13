//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"", "curl -s ipinfo.io | sed -n '2p;4p' | grep -e city -e ip |  awk '{print $2}' |tr -s '\n' ' ' | sed 's/\", \"/ /g' | sed 's/\"//g' | sed 's/,//g' | sed 's/.$//g'",	30,		0},
	{"", "curl -s wttr.in/Berlin?format=1", 30, 0},
	{"", "db_battery", 30, 0},
  {"", "upower -i $(upower -e | grep 'BAT') | grep energy-rate | awk '{print $2 $3}'", 30, 0}, 
	{"", "db_volume", 1, 0},
	{"", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	{"G:", "sensors | grep edge | awk '{print $2}'",	5,		0},
	{"C:", "sensors | grep Tctl | awk '{print $2}'",	5,		0},
	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;