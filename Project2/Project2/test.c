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
	//�����̳�ʼ�����������ⶼ��\0��
	int input=0;
	srand((unsigned int)time(NULL));
	do{menu();
	scanf_s("%d", &input);switch (input)
		{case 1:play(); break;
		case 0:break;
		default:printf("��Ч������������:\n"); break;}
	} while (input);


	system("pause");
	return 0;
}

void play()
{
	int i = 0; int j = 0;
	int x = 0; int y = 0;
	initboundary(line, rank);//չʾ��ʼ����
	setmines(playing, line, rank, mines);//����������׷ź�
	/*for (i = 0; i < line; i++)
	{
		for (j = 0; j < rank; j++)
			printf("%c", playing[i][j]);
		printf("\n");
	}  */   //����ʱ���������׷ź���û��
	printf("������򿪷��������\n");
	scanf_s("%d,%d", &x, &y);
	

firstplay(playing,line,rank,x,y);//Ϊ��֤��ҵ�һ�ε㿪����ը����
//for (i = 0; i < line; i++)
//{
//	for (j = 0; j < rank; j++)
//		printf("%c", playing[i][j]);
//	printf("\n");
//}     //����ʱ���������׷ź���û��
convert(strench,playing,line,rank);//�ź��׺���Ҫ��ȫ���������鸳ֵ,ֻ��ֵ������͡�
//printf("strench\n");
//for (i = 0; i < line + 2; i++)
//{
//	for (j = 0; j < rank + 2; j++)
//		printf("%d", strench[i][j]);
//	printf("\n");
//}

	  //���ڼ������������Ƿ��������Ѽ��顣
    setmathboundary(strench, sum1, x, y, line, rank);//��sum�����зźþŹ���͡�

	putmathboundary(sum1,line,rank,x,y);//չʾ���档
	while (1)
	{
		printf("������򿪷��������\n");
		scanf_s("%d,%d", &x, &y);
		if (strench[x + 1][y + 1] == 1)
		{
			printf("���ף���Ϸ����\n");
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
   //nextplay();//�����㿪 
   //�ж��Ƿ�ը����
   //չʾ����
   //�����㿪������������


	
}