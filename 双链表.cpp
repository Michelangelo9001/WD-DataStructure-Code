//˫��������а�������ָ��prior��next���ֱ�ָ��ǰ�����ͺ�̽ڵ㡣����ڵ����������ǰ������ʱ�临�Ӷ�Ϊ
		 //O(1)

//�����������
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinklist;

//˫����Ĳ���
//s->next = p->next;
//p->next->prior = s;
//s->prior = p;
//p->next = s;

//˫�����ɾ��
//p->next = q->next;
//q->next->prior = p;
//free(q);
