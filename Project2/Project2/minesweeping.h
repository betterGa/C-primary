#ifndef _MINESWEEPING_H_
#include <stdio.h>
#define line 9//行数
#define rank 9//列数
#define mines 10//雷数
void menu();
void initboundary(int line1,int rank1);
void play();
void setmines(char playing[line+2][rank+2],int line2,int rank2,int mines2);
void firstplay(char playing[line + 2][rank + 2],int line3,int rank3,int x,int y);
void nextplay();
void setmathboundary(int strench[line + 2][rank + 2], int sum1[line + 2][rank + 2], int x, int y, int line6, int rank6);
void putmathboundary(int sum1[line + 2][rank + 2], int line7, int rank7,int x,int y);
char playing[line][rank] ;
int strench[line+2][rank+2];
int sum1[line + 2][rank + 2];//展开给玩家看死法的矩阵
void convert(int strench[line + 2][rank + 2], char playing[line][rank], int line4, int rank4);
//放雷的矩阵







#endif