#include "minesweeping.h"

void menu()
{
	printf("*************************\n");
	printf("*********请选择:*********\n");
	printf("*********1.play**********\n");
	printf("*********0.exit**********\n");
}



void initboundary(int line1,int rank1)
{
	int i = 0; int j = 0;
	for (i = 0; i < line1; i++)
	{
		for (j = 0; j < rank1; j++)
			printf("___|");
		printf("\n");
	}

}

void setmines(char playing[line ][rank ], int line2, int rank2, int mines2)//随机数放雷
{
	int x = 0; int y = 0; 
	while (mines2)
	{
		while (1)
		{
			x = (rand()) % line2;
			y = (rand()) % rank2;
			if (playing[x][y] != '*') { playing[x][y] = '*'; mines2--; break; }
		}
	}
}

void resetmine(char playing[line ][rank ], int line5,int rank5,int x,int y)
{
	int e = 0; int f = 0;
	while (1)
	{
		e = (rand()) % line5;
		f = (rand()) % rank5;
		if (playing[e][f] != '*'&&e!=x-1&&f!=y-1) { playing[e][f] = '*'; break; }
	}
}




void firstplay(char playing[line ][rank], int line3, int rank3,int x,int y)
{
	int i = 0; int j = 0;
	if (playing[x - 1][y - 1] == '*') { playing[x - 1][y - 1] = '\0'; resetmine(playing, line, rank, x, y); }
}//如果点开的第一个是雷，偷偷移走，重新放这个雷。
	
	
void convert(int strench[line+2][rank+2],char playing[line][rank], int line4, int rank4)
{
		int i = 0; int j = 0;
		for (i = 0; i < line; i++)
		{
			for (j = 0; j < rank; j++)
			{
				if (playing[i][j] == '*') strench[i + 1][j + 1] = 1;
				else strench[i + 1][j + 1] = 0;
			}
		}
			for (j = 0; j < rank; j++) strench[0][j] = 0;
			for (i = 0; i < line; i++)  strench[i][0] = 0;

	}
	
	
void setmathboundary(int strench[line + 2][rank + 2],int sum1[line+2][rank+2],int x, int y, int line6, int rank6)
{
	int i = 0; int j = 0;
//if (strench[x ][y - 1] + strench[x ][y+1] + strench[x - 1][y] + strench[x+1][y ] + strench[x - 1][y - 1] + strench[x+1][y - 1] + strench[x - 1][y+1] + strench[x+1][y+1]!=0)
sum1[x][y] = strench[x][y -1] + strench[x][y+1] + strench[x -1][y] + strench[x+1][y] + strench[x-1][y -1] + strench[x+1][y -1] + strench[x - 1][y+1] + strench[x+1][y+1];
//else sum1[x][y] =8;
//printf("sum\n");
//for (i = 0; i < line + 2; i++)
//{
//	for (j = 0; j < rank + 2; j++)
//		printf("%d", sum1[i][j]);
//	printf("\n");
//}


/*setmathboundary(strench,sum1, x,y-1,line, rank);
setmathboundary(strench,sum1,x,y+1, line, rank);
setmathboundary(strench,sum1,x-1,y,line,rank);
setmathboundary(strench,sum1,x+1,y,line, rank);
setmathboundary(strench,sum1,x-1,y-1, line,rank);
setmathboundary(strench,sum1,x+1,y-1,line, rank);
setmathboundary(strench,sum1,x-1,y+1,line, rank);
setmathboundary(strench,sum1,x+1,y+1,line,rank);*///感觉这里的递归写错了，先注释掉试一下。
}


void putmathboundary(int sum1[line+2][rank+2],int line7,int rank7,int x,int y)
{
	int i = 0; int j = 0;
for (i = 1; i < line7+1; i++)
{
	for (j = 1; j < rank7 + 1; j++)
	{
		if ((i == x) && (j == y)) printf("_%d_|", sum1[i][j]);
		else printf("___|");
	}
		printf("\n");
}//通过遍历输出展开后的界面.只需要输出9*9，不用+2.


}       
	
	
	
	//如果第一个点开的不是雷，就第一次展示数字方阵。



