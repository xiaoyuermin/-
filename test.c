//#define _CRT_SECURE_NO_WARNINGS -1
//
//#include "snake.h"
//
////������Ϸ����
//void menu()
//{
//	system("mode con cols=100 lines=30");//���ÿ���̨���ڵĴ�С
//	SetPos(40, 15);
//	printf("��ӭʹ��̰����");
//	SetPos(40, 17);
//	printf("���������ʼ");
//	getchar();
//	system("cls");
//}
//
//void SnakeStart(pSnake s)//̰���߿�ʼ׼���׶�
//{
//	srand((unsigned int)time(NULL));
//
//	system("mode con cols=100 lines=30");//���ÿ���̨���ڵĴ�С
//	DrawMap();
//
//	InitSnake(s);
//	CreatFood(s);
//}
//
//int main()
//{
//	menu();
//	Snake s;
//	memset(&s, 0, sizeof(Snake));
//
//	SnakeStart(&s);
//
//	SnakeRun(&s);
//
//	getchar();
//	//system("pause");
//	return 0;
//}