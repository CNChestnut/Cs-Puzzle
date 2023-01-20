
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
	//�����ȡһ�����������Ϣini�ļ�
	char command_ChangeTitle[128];
	sprintf(command_ChangeTitle, "title %s %s by %s",
	        program_info_loaded.program_name,
	        program_info_loaded.program_version,
	        program_info_loaded.auth_name);
	system(command_ChangeTitle);
	ini.SaveFile("../info.ini");
}

void menu() {
	int mousex, mousey;//���λ��
	while (true) {//ѭ������
		setbkcolor(EGERGB(255, 255, 255));
		cleardevice();
		setcolor(EGERGB(0, 0, 0));
		settextjustify(CENTER_TEXT, CENTER_TEXT);
		//��ͼ��ʼ�� & ��ջ���

		setfont(-36, 0, "Microsoft Yahei UI");
		outtextxy(400, 150, program_info_loaded.program_name);
		setfont(-24, 0, "Microsoft Yahei UI");
		outtextxy(400, 250, "������Ϸ/�̳�");
		outtextxy(400, 300, "��ȡ��Ϸ");
		outtextxy(400, 350, "��ͼ�༭��");
		outtextxy(400, 400, "����");
		//��׼��ҳ

		mousepos(&mousex, &mousey);
		if ((mousex > 200) && (mousex < 600)) {
			setfillcolor(BLACK);
			setcolor(WHITE);
			setbkcolor(BLACK);
			if ((mousey > 225) && (mousey < 275)) {
				bar(200, 225, 600, 275);
				outtextxy(400, 250, "������Ϸ/�̳�");
			} else if ((mousey > 275) && (mousey < 325)) {
				bar(200, 275, 600, 325);
				outtextxy(400, 300, "��ȡ��Ϸ");
			} else if ((mousey > 325) && (mousey < 375)) {
				bar(200, 325, 600, 375);
				outtextxy(400, 350, "��ͼ�༭��");
			} else if ((mousey > 375) && (mousey < 425)) {
				bar(200, 375, 600, 425);
				outtextxy(400, 400, "����");
			};
			setbkcolor(WHITE);
			//��ɫ
		}
		delay_fps(60);//�����ٶ�
		system("cls");
	}
}

#endif
