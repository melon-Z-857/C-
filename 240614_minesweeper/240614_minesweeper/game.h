#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9//行数
#define COL 9//列数
#define ROWS ROW+2
#define COLS COL+2
#define MineCount 10 //雷数
void InitBoard(char mine[ROWS][COLS], int rows, int cols, char set);

void DisplayBoard(char mine[ROWS][COLS], int row, int col);

void SetMine(char mine[ROWS][COLS], int row, int col);

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);