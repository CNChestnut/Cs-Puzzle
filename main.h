
#include <fstream>
#include "SimpleIni.h"

#ifndef _MAIN_H
#define _MAIN_H

using namespace std;

struct program_info
{
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

void init_program()
{
	system("echo off");
	system("mode con cols=100 lines=31");
	system("chcp 65001");//use UTF-8
	ini.LoadFile("../info.ini");
	program_info_loaded.program_name = (char*)ini.GetValue("maininfo", "Program.Name");
	program_info_loaded.program_version = (char*)ini.GetValue("maininfo", "Program.Version");
	program_info_loaded.program_buildTime = (char*)ini.GetValue("maininfo", "Program.BuildTime");
	program_info_loaded.auth_name = (char*)ini.GetValue("maininfo", "Auth.Name");
	program_info_loaded.auth_site = (char*)ini.GetValue("maininfo", "Auth.Site");
	//ini.SaveFile("../info.ini");
	char command_ChangeTitle[128];
	sprintf(command_ChangeTitle, "title %s %s by %s",
	        program_info_loaded.program_name,
	        program_info_loaded.program_version,
	        program_info_loaded.auth_name);
	system(command_ChangeTitle);
	ini.SaveFile("../info.ini");
}

#endif
