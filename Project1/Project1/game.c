#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include "threechessgame.h"
#include <time.h>
void initboundary()
{
	int i;
	int j;
	
	for (i = 0; i < 3; i++)
	{
		for(j = 0; j< 3; j++)
		{
			printf("___|");
		}
		printf("\n");
	}
}
void player(char a[3][3])
{
	int x = 0; int y = 0;
	while (1)
	{
		printf("请玩家输入下棋坐标x,y\n");
		scanf_s("%d,%d", &x, &y);
		if (a[x - 1][y - 1] == '\0') {
			a[x - 1][y - 1] = '*'; break;
		}
		else printf("无效坐标，请重新输入！\n");

	}
}
void boundary(char a[3][3])
{
	int i;
	int j;
for (i = 0; i < 3; i++)
	{for (j = 0; j < 3; j++)
		{
			printf("_%c_|",a[i][j]);
		}
		printf("\n");
	}
}
void computer(char a[3][3])
{
	int x = 0; int y = 0;
	printf("电脑下棋'$'\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (a[x][y] != '*'&&a[x][y]!='$') { a[x][y] = '$'; break; }
	}
}

int judgement(char a[3][3])
{
	int num = 0;
	
	if ((a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][2] == '*') || (a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][2] == '*') || (a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][2] == '*') || (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == '*') || (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] == '*') || (a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[2][0] == '*') || (a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[2][1] == '*') || (a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[2][2] == '*'))
		return 1;
	else if ((a[0][0] == a[0][1] && a[0][1] == a[0][2] && a[0][2] == '$') || (a[1][0] == a[1][1] && a[1][1] == a[1][2] && a[1][2] == '$') || (a[2][0] == a[2][1] && a[2][1] == a[2][2] && a[2][2] == '$') || (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[2][2] == '$') || (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[2][0] == '$') || (a[0][0] == a[1][0] && a[1][0] == a[2][0] && a[2][0] == '$') || (a[0][1] == a[1][1] && a[1][1] == a[2][1] && a[2][1] == '$') || (a[0][2] == a[1][2] && a[1][2] == a[2][2] && a[2][2] == '$'))
		return 2;
	}


int draw(char a[3][3])
{
	int i = 0; int j = 0; int num = 0;
for (i = 0; i < 3;i++)
for (j = 0; j < 3;j++)
if (a[i][j] != '\0') num++;
if (num == 9) return 1;
else return 0;
}