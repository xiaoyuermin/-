
#include"chess.h"
void menu()//提示玩家是继续游戏还是终止游戏
{
	printf("****\n********");
	printf("*1.play*0.exit");
	printf("****\n********");

}
void game()//游戏的实现过程
{
	char board[ROWS][COLS] = { 0 };
	char win = 0;
	InitBoard(board, ROWS, COLS);//初始化棋盘
	PrintBoard(board, ROWS, COLS);//打印棋盘
	do
	{
		PlayerMove(board, ROWS, COLS);//玩家走
		PrintBoard(board, ROWS, COLS);//打印棋盘
		win=CheckWin(board, ROWS, COLS);//玩家赢（X),电脑赢（0），平局（Q），继续游戏（‘ ’）
		if (win != ' ')
			break;
		ComputerMove(board, ROWS, COLS);//电脑走
		PrintBoard(board, ROWS, COLS);//打印棋盘
		win = CheckWin(board, ROWS, COLS);//判断输赢
		if (win != ' ')
			break;

		
	} while (1);
	if (win == 'X')
	{
		printf("玩家赢\n");
	}
	 else if (win == '0')
	{
		printf("电脑赢\n");
	}
	else if (win== 'Q')
	{
		printf("平局\n");
	}
	 
} 
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏");
			break;
		case 1:
			game();
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main()
{

	test();
	system("pause");
	return 0;
}
