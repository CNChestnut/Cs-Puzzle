
#include <fstream>
#include <string>
#include "main.h"
#include "SimpleIni.h"

using namespace std;

struct _map_info_about
{
	char *name;
	char *time;
	char *version;
	char *auth;
};

struct _map_info_map
{
	int width;
	int height;
};

struct _map_info_xy
{
	int x;
	int y;
};

struct _map_info
{
	_map_info_about about;
	_map_info_map map;
	_map_info_xy start;
	_map_info_xy end;
};

_map_info map_info;

int load_map(){
	ini.LoadFile("testmap/map.info");
	map_info.about.name=(char*)ini.GetValue("about","name");
	map_info.about.time=(char*)ini.GetValue("about","time");
	map_info.about.version=(char*)ini.GetValue("about","version");
	map_info.about.auth=(char*)ini.GetValue("about","auth");
	map_info.map.width=stoi((char*)ini.GetValue("map","width"));
	map_info.map.height=stoi((char*)ini.GetValue("map","height"));
	map_info.start.x=stoi((char*)ini.GetValue("start","x"));
	map_info.start.y=stoi((char*)ini.GetValue("start","y"));
	map_info.end.x=stoi((char*)ini.GetValue("end","x"));
	map_info.end.y=stoi((char*)ini.GetValue("end","y"));
	
	stastic bool map_base_loaded[map_info.map.width][map_info.map.width];
	
	return 0;
}
