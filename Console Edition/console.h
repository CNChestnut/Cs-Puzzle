
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../main.h"

void p_newGame();
void p_about();

void menu()
{
	char op;
	do
	{
		system("cls");
		printf("\n\n\n");
		printf("\t%s\n\n", program_info_loaded.program_name);
		printf("\t新游戏/教程  [N]\n");//ing
		printf("\t加 载 游 戏  [L]\n");
		printf("\t编 辑 地 图  [M]\n");
		printf("\t关 于 游 戏  [A]\n");//ok
		printf("\t退 出 游 戏  [E]\n");//ok
		op = getch();
		switch (op)
		{
			case 'N':
			case 'n':
				p_newGame();
				break;
			case 'L':
			case 'l':
				printf("developing");
				break;
			case 'M':
			case 'm':
				printf("developing");
				break;
			case 'A':
			case 'a':
				p_about();
				break;
		}
	}
	while ((op != 'E') & (op != 'e'));
}

void p_newGame()
{
	system("cls");
	printf("\n\n\n");
	printf("\t新游戏/教程\n\n");
	getch();
	
}

void p_about()
{
	system("cls");
	printf("\n\n\n");
	printf("\t关于 %s\n\n",program_info_loaded.program_name);
	printf("\t 版  本 :%s\n",program_info_loaded.program_version);
	printf("\t发行时间:%s\n",program_info_loaded.program_buildTime);
	printf("\t 作  者 :%s\n",program_info_loaded.auth_name);
	printf("\t作者网站:%s\n\n",program_info_loaded.auth_site);
	printf("\t[Press any kry to exit]");
	getch();
}
