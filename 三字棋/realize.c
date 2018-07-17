#include"chess.h"

void InitBoard(char board[ROWS][COLS], int row, int col)//初始化棋盘
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
void PrintBoard(char board[ROWS][COLS], int row, int col)//在屏幕上打印棋盘，使其美
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i<row-1)
		  printf("---|---|---\n");
		
	}

}
void PlayerMove(char board[ROWS][COLS], int row, int col)//玩家走
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家走\n");
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);
		if (((x >= 1) && (x <= ROWS)) && ((y >= 1) && (y <= COLS)))//控制坐标范围
		{
			if (board[x-1][y-1] == ' ')//即没有被占用
			{
				board[x-1][y-1] = 'X';
				break;
			}
			else
			{
				printf("坐标已经被占用\n");
			}
		}
		else
		{
			printf("坐标非法\n");
		}
	}
}
void ComputerMove(char board[ROWS][COLS], int row, int col)//电脑走
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");
	
	while (1)
	{
		 x = rand() % 3;//随机产生一个坐标，赋0
	     y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
 static int IsFull(char board[ROWS][COLS], int row, int col)//判断棋盘是否下满
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')//判断棋盘位置是否下满
				return 0;
		}
	}
	return 1;//棋盘满
}

char CheckWin(char board[ROWS][COLS], int row, int col)//判断输赢行玩家赢值为X,电脑赢值为0
{
	int i = 0;
	for (i = 0; i < row; i++)//处理行相等
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	for (i = 0; i < row; i++)//处理列相等
	{
		if ((board[0][i] == board[1][i]) && (board[1][i] == board[2][i]) && (board[0][i] != ' '))
		{
			return board[0][i];
		}
	}
	if ((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]) && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if ((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]) && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (IsFull(board, row, col) == 1)
	{
		return 'Q';//平局
	}
	return ' ';

}

		
	

	
		

