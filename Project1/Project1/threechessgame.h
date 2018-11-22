#define _CRT_SECURE_NO_WARNINGS_
#ifndef _THREECHESSGAME_H_

void menu();
void play();
void initboundary();
void player();
void boundary(char a[3][3]);
void computer(char a[3][3]);
int judgement(char a[3][3]);
int draw(char a[3][3]);
#endif