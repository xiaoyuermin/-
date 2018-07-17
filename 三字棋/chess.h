#ifndef __CHESS_H__
#define __CHESS_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 3
#define COLS 3
#pragma warning(disable:4996)
void InitBoard(char board[ROWS][COLS], int row, int col);
void PrintBoard(char board[ROWS][COLS], int row, int col);//����Ļ�ϴ�ӡ���̣�ʹ������
void PlayerMove(char board[ROWS][COLS], int row, int col);//�����
void ComputerMove(char board[ROWS][COLS], int row, int col);//������
char CheckWin(char board[ROWS][COLS], int row, int col);//�ж���Ӯ���ӮֵΪX,����ӮֵΪ0
static int IsFull(char board[ROWS][COLS], int row, int col);//�ж������Ƿ�����
#endif