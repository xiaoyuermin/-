
#include"chess.h"
void menu()//��ʾ����Ǽ�����Ϸ������ֹ��Ϸ
{
	printf("****\n********");
	printf("*1.play*0.exit");
	printf("****\n********");

}
void game()//��Ϸ��ʵ�ֹ���
{
	char board[ROWS][COLS] = { 0 };
	char win = 0;
	InitBoard(board, ROWS, COLS);//��ʼ������
	PrintBoard(board, ROWS, COLS);//��ӡ����
	do
	{
		PlayerMove(board, ROWS, COLS);//�����
		PrintBoard(board, ROWS, COLS);//��ӡ����
		win=CheckWin(board, ROWS, COLS);//���Ӯ��X),����Ӯ��0����ƽ�֣�Q����������Ϸ���� ����
		if (win != ' ')
			break;
		ComputerMove(board, ROWS, COLS);//������
		PrintBoard(board, ROWS, COLS);//��ӡ����
		win = CheckWin(board, ROWS, COLS);//�ж���Ӯ
		if (win != ' ')
			break;

		
	} while (1);
	if (win == 'X')
	{
		printf("���Ӯ\n");
	}
	 else if (win == '0')
	{
		printf("����Ӯ\n");
	}
	else if (win== 'Q')
	{
		printf("ƽ��\n");
	}
	 
} 
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ");
			break;
		case 1:
			game();
			break;
		default:
			printf("ѡ�����\n");
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
