#ifndef __CHESS_H__
#define __CHESS_H__
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 3
#define COLS 3
#pragma warning(disable:4996)
void InitBoard(char board[ROWS][COLS], int row, int col);
void PrintBoard(char board[ROWS][COLS], int row, int col);//在屏幕上打印棋盘，使其美观
void PlayerMove(char board[ROWS][COLS], int row, int col);//玩家走
void ComputerMove(char board[ROWS][COLS], int row, int col);//电脑走
char CheckWin(char board[ROWS][COLS], int row, int col);//判断输赢玩家赢值为X,电脑赢值为0
static int IsFull(char board[ROWS][COLS], int row, int col);//判断棋盘是否下满
#endif