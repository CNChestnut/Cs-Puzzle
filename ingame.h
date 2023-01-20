
#include <fstream>
#include <string>
#include "main.h"
#include "SimpleIni.h"
#include <graphics.h>
#include <iostream>

using namespace std;

struct _map_info_about {
	char *name;
	char *time;
	char *auth;
};

struct _map_info_map {
	int width;
	int height;
};

struct _map_info_xy {
	int x;
	int y;
};

struct _map_info {
	_map_info_about about;
	_map_info_map map;
	_map_info_xy start;
	_map_info_xy end;
};

_map_info map_info;

bool map_wall_loaded[128][128];

int load_map() {
	ini.LoadFile("testmap/map.info");
	map_info.about.name = (char*)ini.GetValue("about", "name");
	map_info.about.time = (char*)ini.GetValue("about", "time");
	map_info.about.auth = (char*)ini.GetValue("about", "auth");
	map_info.map.width = stoi((char*)ini.GetValue("map", "width"));
	map_info.map.height = stoi((char*)ini.GetValue("map", "height"));
	map_info.start.x = stoi((char*)ini.GetValue("start", "x"));
	map_info.start.y = stoi((char*)ini.GetValue("start", "y"));
	map_info.end.x = stoi((char*)ini.GetValue("end", "x"));
	map_info.end.y = stoi((char*)ini.GetValue("end", "y"));
	//ini.SaveFile("testmap/map.info");

	fin.open("testmap/map.wall");
	int sx, sy, ex, ey;
	char nullchar;
	while (!fin.eof()) {
		fin >> sx >> sy >> nullchar >> ex >> ey;
		if (sx == ex) {
			for (int i = sy; i < ey; ++i) {
				map_wall_loaded[sx][i] = true;
			}

		} else if (sy == ey) {
			for (int i = sx; i < ex; ++i) {
				map_wall_loaded[i][sy] = true;
			}
		}
	}
	return 0;
}

int in_Game() {
	system("cls");
	printf("地 图 名:%s\n",map_info.about.name);
	printf("编辑时间:%s\n",map_info.about.time);
	printf("shu地图作者:%s\n",map_info.about.auth);
	for (int i = 0; i < map_info.map.width+2; ++i) {
		printf("－");
	}
	printf("\n");
	for (int i = 0; i < map_info.map.width; ++i) {
		printf("｜");
		for (int j = 0; j < map_info.map.height; ++j) {
			if (map_wall_loaded[i][j] == true) {
				printf("Ｘ");
			} else {
				printf("　");
			}
		}
		printf("｜\n");
	}
	for (int i = 0; i < map_info.map.width+2; ++i) {
		printf("－");
	}
	
	initgraph(1280,720);
	setbkcolor(EGERGB(255,255,255));
	setcaption("Maps");
	setcolor(EGERGB(0,0,0));
	outtext("Hello,ege");
	getch();
	closegraph();
}
