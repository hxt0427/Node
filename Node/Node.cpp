// Node.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int Data;
	struct Node * Next;
};

struct Node* Creat() {
	struct Node * L;
	L = (struct Node*)malloc(sizeof(struct Node));
	L->Next = NULL;
	return L;
}

void Insert(struct Node *L,int x) {     //链表尾插入
	struct Node *p,*q;
	p = L;
	while (p->Next != NULL)
		p = p->Next;
	q = (struct Node*)malloc(sizeof(struct Node));
	q->Data = x;
	q->Next = p->Next;
	p->Next = q;
}

int Size(struct Node * L) {    //返回链表元素个数
	int sum = 0;
	struct Node *p;
	p = L;
	while (p->Next != NULL) {
		p = p->Next;
		sum++;
	}
	return sum;
}

void InsertP(struct Node* p, int X) {    //在节点P后面插入
	struct Node *q;
	q = (struct Node *)malloc(sizeof(struct Node));
	q->Data = X;
	q->Next = p->Next;
	p->Next = q;
}

void Print(struct Node *L) {
	struct Node *p;
	p = L->Next;
	while (p != NULL) {
		printf("%d ", p->Data);
		p = p->Next;
	}
	printf("\n");
}

void Slim(struct Node*L) {
	struct Node *p,*q;
	p = L->Next;
	if (p->Next == NULL)
		return;
	q = p->Next;
	while (q != NULL) {
		while (p->Data == q->Data) {
			p->Next = q->Next;
			free(q);
			if (p->Next == NULL)
				return;
			q = p->Next;
		}
		p = q;
		q = p->Next;
	}
}

void InsertSort(struct Node *L, int x) {    //排序插入
	struct Node *p, *q;
	p = L;
	while (p->Next != NULL && p->Data < x) {
		if (p->Next->Data >= x)
			break;
		p = p->Next;
	}
		
	q = (struct Node*)malloc(sizeof(struct Node));
	q->Data = x;
	q->Next = p->Next;
	p->Next = q;
}

struct Node* split(struct Node*L) {  //将链表L分为两个单链表，L存放所有的非负整数,L1存放所有的负整数
	struct Node *p, *q,*L2,*r;
	L2 = (struct Node*)malloc(sizeof(struct Node));
	p = L;
	q = L2;
	r = L->Next;
	while (r !=NULL)
	{
		if (r->Data < 0) {
			q->Next = r;
			q = q->Next;
		}	
		else {
            p->Next = r;
			p = p->Next;
		}		
		r = r->Next;
	}
	p->Next = NULL;
	q->Next = NULL;
	return L2;
}

int main()
{
	struct Node *L,*L1;
	L = Creat();
	int num;
	for (int i = 0; i < 10; i++) {
		scanf_s("%d", &num);
		InsertSort(L, num);
	}
	Print(L);
	printf("%d\n", Size(L));
	L1 = split(L);
	Print(L);
	Print(L1);
	printf("%d\n", Size(L));
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
