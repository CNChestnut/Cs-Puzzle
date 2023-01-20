
#include <stdio.h>
#include <conio.h>
#include "../main.h"

void menu()
{
	char op;
	do
	{
		printf("\n\n\n");
		printf("\t%s\n\n", program_info_loaded.program_name);
		printf("\t新游戏/教程[N]\n");
		printf("\t加 载 游 戏[L]\n");
		printf("\t编 辑 地 图[M]\n");
		printf("\t关 于 游 戏[A]\n");
		printf("\t退 出 游 戏[E]\n");
		op = _getch();
		switch (op)
		{
		case 'N':
		case 'n':
			printf("developing");
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
			printf("developing");
			break;
		}
	}
	while (op != 'E' & op != 'e');
}
