//ʲô�ǵ�����
//���壺��ʽ�洢�����Ա�ÿ���ڵ���˴������Ԫ���⣬��Ҫ�洢ָ����һ���ڵ��ָ��
//�ŵ㣺��Ҫ���Ƭ�����ռ䣬�ı���������
//ȱ�㣺���������ȡ��Ҫ�ķ�һ���ռ���ָ��

//ͷָ�룺ͨ����ͷָ������ʶһ���������絥����L��ͷָ��ΪNULLʱ��ʾһ���ձ����⣬Ϊ�˲����Ϸ��㣬�ڵ������
		//��һ���ڵ�ǰ����һ���ڵ㣬��Ϊͷ��㡣ͷ������������Բ����κ���Ϣ��Ҳ���Լ�¼����ͷ����ָ����
		//ָ���һ��Ԫ�صĽڵ�


//�ô��붨��һ��������

	//���������нڵ�
	#include<stdio.h>

	typedef struct LNode {
		int data;
		struct LNode* next;
	}LNode, * LinkList;

	//����ͷ�巨����������
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
	//����Ų��ҽڵ�ֵ
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
	//��ֵ���ҽڵ�
	LNode* LocateElem(LinkList L, int e) {
		LNode* p = L->next;
		while (p != NULL && p->data != e)
			p = p->next;
		return p;
	}
	//����ڵ�
	/*p = GetElem(L, i - 1);
	s->next = p->next;
	p->next = s;*/
	//ɾ���ڵ�*p
	/*p = GetElem(L, i - 1);
	q = p->next;
	p->next = q->next;
	free(q);*/
	//���
