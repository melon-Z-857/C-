#include "game.h"

//菜单
void menu() {
	printf("----------扫雷游戏-----------\n");
	printf("--------输入1开始游戏--------\n");
	printf("----------输入0退出----------\n");
	printf("-----------------------------\n");

}

//游戏
void game()
{
	//创建棋盘
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//布置雷
	SetMine(mine, ROW, COL);

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//排雷
	FindMine(mine, show, ROW, COL);
}

void test() {
	int a = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		scanf_s("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0: 
			printf("已退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (a);
}

int main() {
	test();
	return 0;
}