#pragma once
#include<stdio.h>
#include<windows.h>
#define ROWS 6
#define COLS 6
#define MAX 100
typedef struct {
	int x;
	int y;
}Position;
typedef Position datatype;
typedef struct Stack{
	datatype data[MAX];
	int top;
}Stack;
void GoMazeR();