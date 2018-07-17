#include"chess.h"

void InitBoard(char board[ROWS][COLS], int row, int col)//��ʼ������
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
void PrintBoard(char board[ROWS][COLS], int row, int col)//����Ļ�ϴ�ӡ���̣�ʹ����
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i<row-1)
		  printf("---|---|---\n");
		
	}

}
void PlayerMove(char board[ROWS][COLS], int row, int col)//�����
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("�����\n");
		printf("����������:>");
		scanf("%d%d", &x, &y);
		if (((x >= 1) && (x <= ROWS)) && ((y >= 1) && (y <= COLS)))//�������귶Χ
		{
			if (board[x-1][y-1] == ' ')//��û�б�ռ��
			{
				board[x-1][y-1] = 'X';
				break;
			}
			else
			{
				printf("�����Ѿ���ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�\n");
		}
	}
}
void ComputerMove(char board[ROWS][COLS], int row, int col)//������
{
	int x = 0;
	int y = 0;
	printf("������:>\n");
	
	while (1)
	{
		 x = rand() % 3;//�������һ�����꣬��0
	     y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}
 static int IsFull(char board[ROWS][COLS], int row, int col)//�ж������Ƿ�����
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')//�ж�����λ���Ƿ�����
				return 0;
		}
	}
	return 1;//������
}

char CheckWin(char board[ROWS][COLS], int row, int col)//�ж���Ӯ�����ӮֵΪX,����ӮֵΪ0
{
	int i = 0;
	for (i = 0; i < row; i++)//���������
	{
		if ((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]) && (board[i][0] != ' '))
		{
			return board[i][0];
		}
	}
	for (i = 0; i < row; i++)//���������
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
		return 'Q';//ƽ��
	}
	return ' ';

}

		
	

	
		

