#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "threechessgame.h"
char a[3][3] = { '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0', '\0' };
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;

	
	do{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case(1) : memset(a, '\0', 9);
				  play(); 
				  break;
		case(0) : break;
		default:printf("无效，请重新输入：\n"); break;
		}
	}
	while (input);
	system("pause");
	return 0;
}



void menu()
{
	printf("*********请选择：**********\n");
	printf("*********1.play************\n");
	printf("*********0.exit************\n");
	printf("***************************\n");
}
void play()
{initboundary(a);
	 while (1)
	 {player(a);
		boundary(a);
		if (judgement(a) == 1) { printf("游戏结束，玩家赢！\n"); break; }
		else if (judgement(a) == 2) { printf("游戏结束，电脑赢！\n"); break; }
		else if (draw(a) == 1) { printf("本轮棋盘已满，平局！\n"); break; }
			computer(a);
			boundary(a);
			if (judgement(a) == 1) { printf("游戏结束，玩家赢！\n"); break; }
			else if (judgement(a) == 2) { printf("游戏结束，电脑赢！\n"); break; }
			else if (draw(a) == 1) { printf("本轮棋盘已满，平局！\n"); break; }
		}
	}


