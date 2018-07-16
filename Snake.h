
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
//�Ķ������Ǿ���������������ʲô֪ʶ
#define FOOD "��"    //ǽ������ͼ��
#define INIT_X 24   //�߳�������ʼ������
#define INIT_Y 4    //�߳�������ʼ������

#define MIN_SPEED 500   //����С����ʼ���ٶ�
#define MAX_SPEED 100   //������ٶ�
#define ADD_SPEED 50    //ÿ�μ��ٸı�50
//�ߵ��ٶ��ǿ�Sleep����ʵ�ֵģ�Sleep������������Ļ�ϴ�ӡ�ߵ�ʱ����
//��Sleep(int x)�е���ֵԽС����ӡʱ����Խ�̣��ٶȾ�Խ��

//�߽��
typedef struct node
{
	int x;  //�߽�������
	int y;  //�߽��������
	struct node *next;  //�߽��ָ�루ָ����һ��㣩
}SnakeNode, *pSnakeNode;

//�߱���
typedef struct snake
{
	pSnakeNode _pSnake; //��ͷָ��
	pSnakeNode _pFood;  //ʳ��
	enum DIRECTION _Dir;    //���߷���
	enum Status _Status;    //��ǰ״̬
	int _SleepTime; //ÿ��һ��ͣ����ʱ��
	int _Mark;  //����
}Snake, *pSnake;

//�ߵ�״̬
enum Status
{
	OK, //����
	KILL_BY_SELF,   //���Լ�ҧ��
	KILL_BY_WALL   //ײǽ��
};

//����
enum DIRECTION
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};
void SetPos(int x, int y);//���ù��λ��
void DrawMap(void);//������
void InitSnake(pSnake ps);//��ʼ��
void CreatFood(pSnake ps);//����ʳ��
void SnakeMove(pSnake ps);//�ƶ�
int NextIsFood(pSnake ps, pSnakeNode nNode);//�жϵ�ǰλ���Ƿ���ʳ��
void EatFood(pSnake ps, pSnakeNode nNode);//��ʳ���ʳ����ӽ��
void NoFood(pSnake ps, pSnakeNode nNode);//��ʳ�ﲻ��
int SnakeRun(pSnake ps);//���Ʒ���
int KillBySelf(pSnake ps);//ײ��������
int KillByWall(pSnake ps);//ײǽ����

