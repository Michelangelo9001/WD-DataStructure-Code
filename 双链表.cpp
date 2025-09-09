//双链表：结点中包含两个指针prior和next，分别指向前驱结点和后继节点。相较于单链表，其访问前驱结点的时间复杂度为
		 //O(1)

//结点类型描述
typedef struct DNode {
	int data;
	struct DNode* prior, * next;
}DNode,*DLinklist;

//双链表的插入
//s->next = p->next;
//p->next->prior = s;
//s->prior = p;
//p->next = s;

//双链表的删除
//p->next = q->next;
//q->next->prior = p;
//free(q);
