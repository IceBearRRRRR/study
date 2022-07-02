#include"game.h"
#define _CRT_SECURE_NO_WARNINGS 1
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)\
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家行动!\n");
	//判断坐标合法性
	while (1)
	{
		printf("请输入下棋的坐标：>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			//下棋
			//判断坐标是否被占用
			if (board[x - 1][y - 1]==' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入：>");
			}
		}
		else
		{
			printf("坐标非法，请重新输入：\n");
		}
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑行动!\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//判断行
	for (i = 0; i < row; i++)
	{
		if ((board[i][0] == board[i][1]&&board[i][1] == board[i][2]) && (board[i][1] != ' '))
		{
			return board[i][1];
		}
	}
	//判断列
	for (i = 0; i < col; i++)
	{
		if ((board[0][i] == board[1][i]&&board[1][i] == board[2][i]) && (board[0][i] != ' '))
		{
			return board[0][i];
		}
	}
	//判断对角线
	if ((board[0][0] == board[1][1]&&board[1][1] == board[2][2]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	if ((board[0][2] == board[1][1]&&board[1][1] == board[2][0]) && (board[1][1] != ' '))
	{
		return board[1][1];
	}
	//判断平局
	int count=IsFull(board, row, col);
	if (count == 1)
	{
		return 'Q';
	}
	//游戏继续
		return 'C';
}