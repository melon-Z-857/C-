#include "game.h"

void InitBoard(char mine[ROWS][COLS], int rows, int cols, char set) {
	int i = 0;
	for (i = 0; i < rows; i++) {
		int j = 0;
		for (j = 0; j < cols; j++) {
			mine[i][j] = set;
		}
	}
}

void DisplayBoard(char mine[ROWS][COLS], int row, int col) {
	printf("---------扫雷--------\n");
	int i = 0;
	for (i = 0; i <= col; i++) {//打印列号
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {//打印行号
		printf("%d ", i);
		int j = 0;
		for (j = 1; j <= col; j++) {
			printf("%c ", mine[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}

void SetMine(char mine[ROWS][COLS], int row, int col) {
	int count = MineCount;
	while (count)
	{
		int x = 0;
		int y = 0;
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (mine[x][y] != '1') {
			mine[x][y] = '1';
			count--;
		}
	}
}

//统计周围雷的个数
char GetMineCount(char mine[ROWS][COLS], int x, int y) {
	int i = 0;
	int j = 0;
	char count = '0';
	for (i = -1; i <= 1; i++) {
		for (j = -1; j <= 1; j++) {
			count += mine[x+i][y+j] - '0';
		}
	}
	return count;
}
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int win = row * col - MineCount;
	while (win)
	{
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] != '1') {
				show[x][y] = GetMineCount(mine, x, y);//没有踩雷就用GetMineCount函数统计周围雷的个数
				DisplayBoard(show, ROW, COL);
				win--;
			}
			else {
				DisplayBoard(mine, ROW, COL);
				printf("抱歉踩到雷了，游戏结束了\n");
				break;
			}
		}
		else
			printf("输入的坐标有误，请重新输入\n");
	}
	if (win == 0) {
		DisplayBoard(mine, ROW, COL);
		printf("恭喜你，排雷成功！\n");
	}
}