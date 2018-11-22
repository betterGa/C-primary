#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "minesweeping.h"

int main()
{
	char playing[line][rank] = { 0 };
    int strench[line+2][rank+2] = { 0 };
   int sum1[line + 2][rank + 2] = { 0 };
	memset(playing,sizeof(playing), '\0');
	//将棋盘初始化除了雷以外都是\0。
	int input=0;
	srand((unsigned int)time(NULL));
	do{menu();
	scanf_s("%d", &input);switch (input)
		{case 1:play(); break;
		case 0:break;
		default:printf("无效！请重新输入:\n"); break;}
	} while (input);


	system("pause");
	return 0;
}

void play()
{
	int i = 0; int j = 0;
	int x = 0; int y = 0;
	initboundary(line, rank);//展示初始棋盘
	setmines(playing, line, rank, mines);//先随机数把雷放好
	/*for (i = 0; i < line; i++)
	{
		for (j = 0; j < rank; j++)
			printf("%c", playing[i][j]);
		printf("\n");
	}  */   //测试时检验雷盘雷放好了没有
	printf("请输入打开方格的坐标\n");
	scanf_s("%d,%d", &x, &y);
	

firstplay(playing,line,rank,x,y);//为保证玩家第一次点开不被炸死。
//for (i = 0; i < line; i++)
//{
//	for (j = 0; j < rank; j++)
//		printf("%c", playing[i][j]);
//	printf("\n");
//}     //测试时检验雷盘雷放好了没有
convert(strench,playing,line,rank);//放好雷后需要给全部数字数组赋值,只赋值，不求和。
//printf("strench\n");
//for (i = 0; i < line + 2; i++)
//{
//	for (j = 0; j < rank + 2; j++)
//		printf("%d", strench[i][j]);
//	printf("\n");
//}

	  //用于检验两个数组是否正常，已检验。
    setmathboundary(strench, sum1, x, y, line, rank);//在sum数组中放好九宫格和。

	putmathboundary(sum1,line,rank,x,y);//展示界面。
	while (1)
	{
		printf("请输入打开方格的坐标\n");
		scanf_s("%d,%d", &x, &y);
		if (strench[x + 1][y + 1] == 1)
		{
			printf("踩雷！游戏结束\n");
			for (i = 0; i < line; i++)
			{
				for (j = 0; j < rank; j++)
					printf("_%c_|", playing[i][j]);
				printf("\n");
			}break;
		}
		else setmathboundary(strench, sum1, x, y, line, rank);
		putmathboundary(sum1, line, rank, x, y);
	}
   //nextplay();//继续点开 
   //判断是否被炸死。
   //展示界面
   //继续点开······


	
}