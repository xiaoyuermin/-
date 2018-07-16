#define _CRT_SECURE_NO_WARNINGS -1
#include "snake.h"
void SetPos(int x, int y)//���ù��λ��
{
	//��ȡ��׼����ľ��
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { 0 };
	pos.X = x;
	pos.Y = y;
	//���õ�ǰ����Ϊ��׼����ľ��
	SetConsoleCursorPosition(handle, pos);
}

void DrawMap(void)//������
{
	//����Ϸ����
	int i;
	for (i = 0; i < 58; i += 2)
	{
		SetPos(i, 0);
		printf(FOOD);
	}
	for (i = 0; i < 58; i += 2)
	{
		SetPos(i, 26);
		printf(FOOD);
	}
	for (i = 0; i < 26; i++)
	{
		SetPos(0, i);
		printf(FOOD);
	}
	for (i = 0; i <= 26; i++)
	{
		SetPos(58, i);
		printf(FOOD);
	}

	//����������
	for (i = 58; i < 84; i += 2)
	{
		SetPos(i, 0);
		printf(FOOD);
	}
	for (i = 58; i < 84; i += 2)
	{
		SetPos(i, 26);
		printf(FOOD);
	}
	for (i = 0; i <= 26; i++)
	{
		SetPos(84, i);
		printf(FOOD);
	}
	SetPos(64, 10);
	printf("�ո���ͣ/����\n");
	SetPos(64, 11);
	printf("Esc   ���˳�\n");
	SetPos(64, 13);
	printf("�����������Ʒ���");
	SetPos(64, 14);
	printf("�������������");
}

void InitSnake(pSnake ps)//��ʼ��
{
	pSnakeNode cur = NULL;
	int i = 0;

	cur = (SnakeNode*)malloc(sizeof(SnakeNode));
	memset(cur, 0, sizeof(SnakeNode));

	cur->x = INIT_X;
	cur->y = INIT_Y;
	cur->next = NULL;

	for (i = 1; i < 5; i++)
	{
		ps->_pSnake = (SnakeNode*)malloc(sizeof(SnakeNode));
		ps->_pSnake->next = cur;
		ps->_pSnake->x = INIT_X + i * 2;
		ps->_pSnake->y = INIT_Y;
		cur = ps->_pSnake;
	}

	while (cur->next != NULL)
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}

	ps->_SleepTime = MIN_SPEED;
	ps->_Status = OK;
	ps->_Dir = RIGHT;
	ps->_Mark = 0;
}

void CreatFood(pSnake ps)//����ʳ��
{
	pSnakeNode cur = NULL;
	pSnakeNode food = NULL;

	food = (SnakeNode*)malloc(sizeof(SnakeNode));
flag:
	memset(food, 0, sizeof(SnakeNode));

	//�������ʳ����ֵ�λ��
	do
	{
		food->x = rand() % 56 + 2;
	} while (food->x % 2 != 0);

	food->y = rand() % 25 + 1;

	cur = ps->_pSnake;
	while (cur != NULL)
	{
		if (cur->x == food->x&&cur->y == food->y)
		{
			goto flag;
		}
		cur = cur->next;
	}
	ps->_pFood = food;
	SetPos(food->x, food->y);
	printf(FOOD);
}

int NextIsFood(pSnake ps, pSnakeNode nNode)//�жϵ�ǰλ���Ƿ���ʳ��
{
	return ps->_pFood->x == nNode->x &&\
		ps->_pFood->y == nNode->y;
}

void EatFood(pSnake ps, pSnakeNode nNode)//��ʳ���ʳ����ӽ��
{
	pSnakeNode cur = ps->_pSnake;
	nNode->next = cur;
	ps->_pSnake = nNode;

	cur = ps->_pSnake;

	while (cur != NULL)
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}
	CreatFood(ps);
}

void NoFood(pSnake ps, pSnakeNode nNode)//��ʳ�ﲻ��
{
	pSnakeNode cur = ps->_pSnake;
	nNode->next = cur;
	ps->_pSnake = nNode;

	cur = ps->_pSnake;
	while (cur->next->next != NULL)
	{
		SetPos(cur->x, cur->y);
		printf(FOOD);
		cur = cur->next;
	}
	//�����ڶ���������ɻ��ƿɲ����ƣ�����δ�ı�
	//SetPos(cur->x, cur->y);
	//printf("��");
	SetPos(cur->next->x, cur->next->y);
	printf("  ");
	free(cur->next);
	cur->next = NULL;
}

int KillBySelf(pSnake ps)//ײ��������
{
	pSnakeNode cur = ps->_pSnake->next;
	while (cur != NULL)
	{
		if (ps->_pSnake->x == cur->x && ps->_pSnake->y == cur->y)
		{
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

int KillByWall(pSnake ps)//ײǽ����
{

	if (ps->_pSnake->x == 0 || ps->_pSnake->x == 58 || \
		ps->_pSnake->y == 0 || ps->_pSnake->y == 26)
	{
		return 1;
	}
	return 0;
}

void SnakeMove(pSnake ps)//�ƶ�
{
	pSnakeNode nNode = NULL;
	nNode = (SnakeNode*)malloc(sizeof(SnakeNode));
	memset(nNode, 0, sizeof(SnakeNode));

	nNode->x = ps->_pSnake->x;
	nNode->y = ps->_pSnake->y;

	//�жϷ���
	switch (ps->_Dir)
	{
	case UP:
		nNode->y--;
		break;
	case DOWN:
		nNode->y++;
		break;
	case LEFT:
		nNode->x -= 2;
		break;
	case RIGHT:
		nNode->x += 2;
		break;
	default:
		break;
	}

	//����¸�λ����ʳ��
	if (NextIsFood(ps, nNode))
	{
		EatFood(ps, nNode);
		if (ps->_SleepTime > MAX_SPEED)
		{
			ps->_SleepTime -= ADD_SPEED;    //��ʳ����ٶ�
		}
		//��ӡ����
		ps->_Mark++;
	}
	else
	{
		NoFood(ps, nNode);
	}
}

int SnakeRun(pSnake ps)//���Ʒ���
{
	short x = 0;
	do
	{
		SetPos(66, 7);
		printf("������%d", ps->_Mark);

		if (0 != (x = GetAsyncKeyState(VK_DOWN)) && ps->_Dir != UP)
		{
			ps->_Dir = DOWN;
		}
		else if (0 != (x = GetAsyncKeyState(VK_UP)) && ps->_Dir != DOWN)
		{
			ps->_Dir = UP;
		}
		else if (0 != (x = GetAsyncKeyState(VK_LEFT)) && ps->_Dir != RIGHT)
		{
			ps->_Dir = LEFT;
		}
		else if (0 != (x = GetAsyncKeyState(VK_RIGHT)) && ps->_Dir != LEFT)
		{
			ps->_Dir = RIGHT;
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			SetPos(64, 20);
			printf("��Ϸ����");
			SetPos(64, 21);
			printf("ллʹ��");
			return 0;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			SetPos(64, 16);
			printf("��Ϸ��ͣ");
			while (!GetAsyncKeyState(VK_SPACE))
			{
				if (GetAsyncKeyState(VK_ESCAPE))
				{
					SetPos(64, 20);
					printf("��Ϸ����");
					SetPos(64, 21);
					printf("ллʹ��");
					return 0;
				}
			}
			SetPos(64, 16);
			printf("       ");
		}

		SnakeMove(ps);

		//�ж���������
		if (KillBySelf(ps))//ײ����
		{
			ps->_Status = KILL_BY_SELF;
		}
		if (KillByWall(ps))//ײǽ
		{
			ps->_Status = KILL_BY_WALL;
		}

		if (-32767 == x)//����
		{
			Sleep(MAX_SPEED);//��ӡ��
		}
		else//�ָ���ǰ��
		{
			Sleep(ps->_SleepTime);//��ӡ��
		}
	} while (ps->_Status == OK);//���߻��ţ�ѭ��

	//����ѭ����˵�����Լ�����
	//�ж�������ʽ
	if (ps->_Status == KILL_BY_WALL)
	{
		SetPos(24, 12);
		printf("�㱻ײ���ˣ�");
		return 1;
	}
	else if (ps->_Status == KILL_BY_SELF)
	{
		SetPos(24, 12);
		printf("�㱻�Լ�ҧ���ˣ�");
		return 1;
	}
	return 0;
}
