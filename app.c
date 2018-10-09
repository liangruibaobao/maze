#define _CRT_SECURE_NO_WARNINGS 1
#include"app.h"
/*int maze[ROWS][COLS] = {
	{ 0,0,0,0,0,0 },
{ 0,0,1,0,0,0 },
{ 0,0,1,0,0,0 },
{ 0,0,1,1,1,0 },
{ 0,0,1,0,1,1 },
{ 0,0,1,0,0,0 }
};*/
/*int maze[ROWS][COLS] = {
{ 0,0,0,0,0,0 },
{ 0,0,1,1,1,1 },
{ 0,0,1,0,0,0 },
{ 0,0,1,0,0,0 },
{ 0,0,1,1,1,1 },
{ 0,0,1,0,0,0 }
};*/
int maze[ROWS][COLS] = {
{ 0,0,0,0,0,0 },
{ 0,1,1,1,1,0 },
{ 0,1,0,0,1,0 },
{ 0,1,0,0,1,0 },
{ 0,1,1,1,1,1 },
{ 0,1,0,0,0,0 }
};
void StackInit(Stack *stack)
{
	stack->top = 0;
}
void StackPush(Stack *stack,datatype data)
{
	stack->data[stack->top] = data;
	stack->top++;
}
void StackPop(Stack *stack)
{
	stack->top--;
}
datatype StackTop(Stack *stack)
{
	return stack->data[stack->top - 1];
}
int StackEmpty(Stack *stack)
{
	if (stack->top == 0)
	{
		return 1;
	}
	else
		return 0;
}
int IsExit(Position pos)
{
	if (pos.y == COLS - 1)
	{
		return 1;
	}
	else
		return 0;
}
int CanPass(Position pos)
{
	if (pos.x < 0 || pos.x >= ROWS)
	{
		return 0;
	}
	if (pos.y < 0 || pos.y >= COLS)
	{
		return 0;
	}
	if (maze[pos.x][pos.y] == 1)
	{
		return 1;
	}
	else
		return 0;
}
void PrintMaze()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (maze[i][j] == 1)
			{
				printf("  ");
			}
			else if (maze[i][j] == 0)
			{
				printf("■");
			}
			else
			{
				printf("◎");
			}
		}
		printf("\n");
	}
}
void GoMazeR(Position pos)
{
	Position nextpos = pos;

		//标记走过的位置
		maze[pos.x][pos.y] = 2;
		system("cls");//打印前清屏
		PrintMaze();
		Sleep(300);//有间隔效果看起来会好一点
		//当前是否走到出口
		if (IsExit(pos))
		{
			maze[pos.x][pos.y] = 1;
			printf("找到出口了！\n");
			return;
		}
		//没有走到出口，按照左上右下的顺序进行尝试
		nextpos.y -= 1;
		if (CanPass(nextpos))
		{
			GoMazeR(nextpos);
		}
		nextpos = pos;
		nextpos.x -= 1;
		if (CanPass(nextpos))
		{
			GoMazeR(nextpos);
		}
		nextpos = pos;
		nextpos.y += 1;
		if (CanPass(nextpos))
		{
			GoMazeR(nextpos);
		}
		nextpos = pos;
		nextpos.x += 1;
		if (CanPass(nextpos))
		{
			GoMazeR(nextpos);
		}
		//回溯之前把走过的路清空
		maze[pos.x][pos.y] = 1;
}
void test()
{
	Position entry = { 5,1 };
	GoMazeR(entry);
}