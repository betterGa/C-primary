#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning (disable:4996)
void Page()
{
	printf("************************************\n");
	printf("*********1.����ͨѶ¼***************\n");
	printf("*********2.��ʾͨѶ¼��Ϣ***********\n");
	printf("*********3.����ͨѶ¼��Ϣ***********\n");
	printf("*********4.ɾ��ͨѶ¼��Ϣ***********\n");
	printf("************************************\n");
}

typedef struct Linklist
{
	char name[10];//�������//��ŵ绰����
	char street[20];
	char city[20];
	char eip[40];
	char state[20];
	struct Linklist *next;
}Linklist, *LNode;

//��������
void Found(Linklist *L){
	char flag = 'y';
	Linklist *p, *s;
	p = L;
	puts("����һ��ͨѶ¼��");
	while (flag == 'Y' || flag == 'y'){
		//��ʼ�����ɿ�
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
		//β�巨������俪ʼ
		s->next = NULL;//ע����
		p->next = s;
		p = s;
		getchar();
		printf("�������룿(y/n)");
		scanf("%c", &flag);
	}
}
//�������
void Show(Linklist *L)
{
	int count = 1;
	Linklist *p;
	p = L->next;
	puts("���\t����\t�ֵ�\t����\t�ʱ�\t����");
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
	printf("������Ҫ��ѯ���û�������");
	scanf("%s", name);
	while (p != NULL)
	{
		if (strcmp(p->name, name) == 0)
		{
			printf("��ϵ��������");
			puts(p->name);
			printf("��ϵ�˽ֵ���");
			puts(p->street);
			printf("��ϵ�˳��У�");
			puts(p->city);
			printf("��ϵ���ʱࣺ");
			puts(p->eip);
			printf("��ϵ�˹��ң�");
			puts(p->state);
			break;
		}
		p = p->next;
	}
	if (p == NULL)
		printf("û�и���ϵ�˼�¼��\n");
}



void del(Linklist *L){//��дdelete����Ϊdelete��C���ԵĹؼ���
	Linklist *p, *q;
	p = L;
	int n;
	puts("��Ҫɾ����һ�");
	scanf("%d", &n);
	//�����ָ�붨λ��ͬ���޸ģ�������Ҫ��ָ�붨λ��Ҫɾ����ǰһ�����ɾ��
	for (int i = 1; i<n; i++){
		p = p->next;
	}
	if (p == NULL){
		puts("û�����");
	}
	else{//ɾ���ĺ������
		q = p->next;
		p->next = q->next;
		free(q);
	}
}
int main(){
	char n = 0;
	Linklist *L;
	int i = 255;
	L = (LNode)malloc(sizeof(Linklist));//���malloc���÷����ʾ�Ϊ����һ����ΪLinklist�Ŀռ䣬����L��ָ��
	L->next = NULL;//�˴�ͷ����βָ������ڣ�����ͬ�ı�������������ͬ�ĳɷ֡�
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
