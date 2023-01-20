
#include <iostream>
#include <string.h>
#include <graphics.h>
#include "main.h"

using namespace std;

int main() {
	init_program();
	initgraph(800,600);
	setcaption(program_info_loaded.program_name);
	menu();
	getch();
	closegraph();
}
