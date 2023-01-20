
#include <fstream>
#include <string>
#include <graphics.h>
#include "SimpleIni.h"

#ifndef _MAIN_H
#define _MAIN_H

using namespace std;

struct program_info {
	char* program_name;
	char* program_version;
	char* program_buildTime;
	char* auth_name;
	char* auth_site;
};

program_info program_info_loaded;
CSimpleIniA ini;
ifstream fin;
ofstream fout;

void init_program() {
	ini.LoadFile("info.ini");
	program_info_loaded.program_name = (char*)ini.GetValue("maininfo", "Program.Name");
	program_info_loaded.program_version = (char*)ini.GetValue("maininfo", "Program.Version");
	program_info_loaded.program_buildTime = (char*)ini.GetValue("maininfo", "Program.BuildTime");
	program_info_loaded.auth_name = (char*)ini.GetValue("maininfo", "Auth.Name");
	program_info_loaded.auth_site = (char*)ini.GetValue("maininfo", "Auth.Site");
	//ini.SaveFile("../info.ini");
	//这里读取一个储存基本信息ini文件
	char command_ChangeTitle[128];
	sprintf(command_ChangeTitle, "title %s %s by %s",
	        program_info_loaded.program_name,
	        program_info_loaded.program_version,
	        program_info_loaded.auth_name);
	system(command_ChangeTitle);
	ini.SaveFile("../info.ini");
}

void menu() {
	int mousex, mousey;//鼠标位置
	while (true) {//循环绘制
		setbkcolor(EGERGB(255, 255, 255));
		cleardevice();
		setcolor(EGERGB(0, 0, 0));
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		//绘图初始化 & 清空画布

		setfont(-36, 0, "Microsoft Yahei UI");
		outtextxy(400, 150, program_info_loaded.program_name);
		setfont(-24, 0, "Microsoft Yahei UI");
		outtextxy(400, 250, "加载游戏/教程");
		outtextxy(400, 300, "读取游戏");
		outtextxy(400, 350, "地图编辑器");
		outtextxy(400, 400, "关于");
		//标准主页

		mousepos(&mousex, &mousey);
		if ((mousex > 200) && (mousex < 600)) {
			setfillcolor(BLACK);
			setcolor(WHITE);
			setbkcolor(BLACK);
			if ((mousey > 225) && (mousey < 275)) {
				bar(200, 225, 600, 275);
				outtextxy(400, 250, "加载游戏/教程");
			} else if ((mousey > 275) && (mousey < 325)) {
				bar(200, 275, 600, 325);
				outtextxy(400, 300, "读取游戏");
			} else if ((mousey > 325) && (mousey < 375)) {
				bar(200, 325, 600, 375);
				outtextxy(400, 350, "地图编辑器");
			} else if ((mousey > 375) && (mousey < 425)) {
				bar(200, 375, 600, 425);
				outtextxy(400, 400, "关于");
			};
			setbkcolor(WHITE);
			//反色
		}
		delay_fps(60);//更新速度
		system("cls");
	}
}

#endif
