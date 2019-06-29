#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void Page()
{
	printf("************************************\n");
	printf("*********1.创建通讯录***************\n");
	printf("*********2.显示通讯录信息***********\n");
	printf("*********3.查找通讯录信息***********\n");
	printf("*********4.删除通讯录信息***********\n");
	printf("************************************\n");
}

typedef struct Linklist
{
	char name[10];//存放名字//存放电话号码
	char street[20];
	char city[20];
	char eip[40];
	char state[20];
	struct Linklist *next;
}Linklist, *LNode;

//创建链表
void Found(Linklist *L){
	char flag = 'y';
	Linklist *p, *s;
	p = L;
	puts("创建一个通讯录：");
	while (flag == 'Y' || flag == 'y'){
		//初始化生成块
		s = (LNode)malloc(sizeof(Linklist));
		printf("Please Enter Name: ");
		scanf("%s", s->name);
		printf("Please Enter Street: ");
		scanf(" %s", s->street);
		printf("Please Enter City: ");
		scanf(" %s", s->city);
		printf("Please Enter Eip: ");
		scanf(" %s", s->eip);
		printf("Please Enter State: ");
		scanf(" %s", s->state);
		//尾插法核心语句开始
		s->next = NULL;//注意封口
		p->next = s;
		p = s;
		getchar();
		printf("继续输入？(y/n)");
		scanf("%c", &flag);
	}
}
//输出链表
void Show(Linklist *L)
{
	int count = 1;
	Linklist *p;
	p = L->next;
	puts("编号\t姓名\t街道\t城市\t邮编\t国家");
	puts("-------------------------------------------------\n");
	while (p){
		printf("%d\t%s\t%s\t%s\t%s\t%s\n", count, p->name, p->street,p->city,p->eip,p->state);
		p = p->next;
		count++;
	}
}

void Find(Linklist  *L)
{
	Linklist *p;
	char name[10];
	p = L;
	printf("请输入要查询的用户姓名：");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("联系人姓名：");
			puts(p->name);
			printf("联系人街道：");
			puts(p->street);
			printf("联系人城市：");
			puts(p->city);
			printf("联系人邮编：");
			puts(p->eip);
			printf("联系人国家：");
			puts(p->state);
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		printf("没有该联系人记录！\n");
}



void del(Linklist *L){//不写delete是因为delete是C语言的关键字
	Linklist *p, *q;
	p = L;
	int n;
	puts("需要删除哪一项？");
	scanf("%d", &n);
	//这里的指针定位不同于修改，我们需要把指针定位到要删除的前一项，进行删除
	for (int i = 1; i<n; i++){
		p = p->next;
	}
	if (p == NULL){
		puts("没有这项！");
	}
	else{//删除的核心语句
		q = p->next;
		p->next = q->next;
		free(q);
	}
}
int main(){
	char n = 0;
	Linklist *L;
	int i = 255;
	L = (LNode)malloc(sizeof(Linklist));//熟记malloc的用法，词句为开创一个长为Linklist的空间，而后被L所指向
	L->next = NULL;//此处头结点的尾指针必须封口，否则不同的编译器会编译出不同的成分。
	while (i != 0){
		Page();
		scanf("%d", &i);
		switch (i){
		case 1:
           Found(L);
		   break;
		case 2:
			Show(L);
			break;
		case 3:
			 Find(L);
			break;
		case 4:
			del(L);
			break;
		
		}
	}
return 0;
}
