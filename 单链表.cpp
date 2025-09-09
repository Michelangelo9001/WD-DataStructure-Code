//什么是单链表
//定义：链式存储的线性表。每个节点除了存放数据元素外，还要存储指向下一个节点的指针
//优点：不要求大片连续空间，改变容量方便
//缺点：不可随机存取，要耗费一定空间存放指针

//头指针：通常用头指针来标识一个单链表，如单链表L，头指针为NULL时表示一个空表。此外，为了操作上方便，在单链表的
		//第一个节点前附加一个节点，称为头结点。头结点的数据域可以不设任何信息，也可以记录表长。头结点的指针域
		//指向第一个元素的节点


//用代码定义一个单链表

	//定义链表中节点
	#include<stdio.h>

	typedef struct LNode {
		int data;
		struct LNode* next;
	}LNode, * LinkList;

	//采用头插法建立单链表
	#include<stdlib.h>
	LinkList List_HeadInsert(LinkList& L) {
		LNode* s; int x;
		L = (LinkList)malloc(sizeof(LNode));
		L->next = NULL;
		scanf("%d", &x);
		while (x != 9999) {
			s = (LNode*)malloc(sizeof(LNode));
			s->data = x;
			s->next = L->next;
			L->next = s;
			scanf("%d", &x);
		}
		return L;
	}
	//按序号查找节点值
	LNode* GetElem(LinkList L, int i) {
		int j = 1;
		LNode* p = L->next;
		if (i == 0)
			return L;
		if (i < 1)
			return NULL;
		while (p && j < i) {
			p = p->next;
			j++;
		}
		return p;
	}
	//按值查找节点
	LNode* LocateElem(LinkList L, int e) {
		LNode* p = L->next;
		while (p != NULL && p->data != e)
			p = p->next;
		return p;
	}
	//插入节点
	/*p = GetElem(L, i - 1);
	s->next = p->next;
	p->next = s;*/
	//删除节点*p
	/*p = GetElem(L, i - 1);
	q = p->next;
	p->next = q->next;
	free(q);*/
	//求表长
