//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"IP:", "curl -s ipinfo.io | sed -n '1,4p' | grep -e city -e ip |  awk '{print $2}' | sed 's/,//g;s/\"//g' |tr -s '\n' '/'",	30,		0},
	{"Battery:", "db_battery", 30, 0},
	{"", "db_volume", 1, 0},
	{"Mem:", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},
	{"ACPI Temp:", "sensors | grep edge | awk '{print $2}'",	5,		0},

	{"", "date '+%b %d (%a) %I:%M%p'",					5,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
