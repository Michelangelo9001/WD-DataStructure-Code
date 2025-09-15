//队列的定义：队列简称队，也是一种操作受限的线性表，只允许在表的一端进行插入，而在另一端进行删除。插入和删除操作分别称为入队和
//          出队。入队位置称为队尾，出队位置称为对头
//队列的顺序存储：队列的顺序实现是指分配一块连续的存储单元存放队列中的元素，并附设两个指针：队头指针 front 指向队头元素，队尾
//             指针rear 指向队尾元素下一个位置

//队列的顺序存储类型：
#define MaxSize 50
typedef struct{
    Elemtype data[MaxSize];
    int front,rear;
}SqQueue;

//初始状态（队空条件）：Q.front==Q.rear==0
//入队操作：队不满时，先送值到队尾元素，再将队尾指针加 1.
//出队操作：队不空时，先取队头元素值，再将队头指针加 1.
//顺序队列的缺点：会出现假溢出的情况
//循环队列：将循环队列臆造为一个环状的空间，即把存储队列元素的表从逻辑上视为一个环，称为循环队列。当对头指针Q.front=MaxSize
//        -1后，再前进一个位置自动到 0，这里可以利用取余运算实现
//        初始时：Q.front=Q.rear=0
//        队首指针进 1：Q.front=(Q.front+1)%MaxSize
//        队尾指针进 1：Q.rear=（Q.rear+1)%MaxSize
//        队列长度：（Q.rear+MaxSize-Q.front)%MaxSize
//出队入队时，指针都按顺时针进 1
//循环队列的操作：
    //（1）：初始化
    void InitQueue(SqQueue &Q){
        Q.rear=Q.front=0;
    }
    //（2）：判对空
    bool isEmpty(SqQueue Q){
        if(Q.rear==Q.front)
            return true;
        else
            return false;
    }
    //（3）：入队
    bool EnQueue(SqQueue &Q,ElemType x){
        if((Q.rear+1)%MaxSize==Q.front)
            return false;
        Q.data[Q.rear]=x;
        Q.rear=(Q.rear+1)%MaxSize;
        return true;
    }
    //（4）：出队
    bool DeQueue(SqQueue &Q,ElemType &x){
        if(Q.rear==Q.front)
            return false;
        x=Q.data[Q.front];
        Q.front=(Q.front+1)%MaxSize;
        return true;
    }
//队列的链式存储：队列的链式表示称为链队列，它实际上是一个同时带有队头指针和队尾指针的单链表。头指针指向队头节点，尾指针指向队
//             尾节点，即单链表的最后一个节点
//队列的链式存储类型
typedef struct LinkNode{
    Elemtype data;
    struct LinkNode* next;
}LinkNode; 
typedef struct{
    LinkNode *front,*rear;
}LinkQueue;
//链式队列的基本操作
    //（1）：初始化
    void InitQueue(LinkQueue &Q){
        Q.front=Q.rear=(LinkNode*)malloc(sizeof(LinkNode));
        Q.front->next=NULL;
    }
    //（2）：判空列
    bool IsEmpty(LinkQueue Q){
        if(Q.front==Q.rear)
            return true;
        else
            return false;
    }
    //（3）：入队
    void EnQueue(LinkQueue &Q,Elemtype x){
        LinkNode* s=(LinkNode*)malloc(sizeof(LinkNode));
        s->data=x;
        s->next=NULL;
        Q.rear->next=s;
        Q.rear=s;
    }
    //（4）：出队
    bool DeQueue(LinkQueue &Q,ElemType &x){
        if(Q.front==Q.rear)
            return false;
        LinkNode* p=Q.front->next;
        x=p->data;
        Q.front->next=p->next;
        if(Q.rear==p)
            Q.rear=Q.front;
        free(p);
        return true;
    }
//双端队列：双端队列是指允许两端都可以进行入队和出队操作的队列，其逻辑结构依然是线性结构。将队列两端分别称为前端和后端，两端都
//        可以进行入队和出队。
//        在双端队列进队时，前端进的元素排列在队列中后端进的元素的前面，在双端队列出队时，无论是前端还是后端出队，先出的元素
//        排列在后出的元素的前面。           