//栈的定义：栈（stack）只允许在一端进行插入和删除操作的线性表。首先栈是一种线性表，但限定这种线性表只能在某一端进行插入和删除
//        操作。允许操作的一端称为栈顶，固定的一端称为栈底，没有元素称为空栈
//注意：我们每接触一种新的数据结构类型，都应该从其逻辑结构，存储结构和对数据的运算三个方面着手
//栈的数学性质：n 个不同元素进栈，出栈元素不同排列的个数为C（n，2n）/（n+1），称为卡特兰数
//栈的基本操作：InitStack（&S）初始化一个空栈，StackEmpty（S）判断一个栈是否是为空栈，Push（&S，x）进栈，Pop（&S，&x）
//            GetTop（S，&x）读栈顶元素，DestroyStack（&S）销毁栈。在解答算法题时，若题干未做出限制，则可直接使用这些基
//            本操作
//栈的顺序存储结构：栈是一种操作首先的线性表，类似于线性表，它也有对应的两种存储方式。采用顺序存储的栈称为顺序栈，它利用一组地
//               址连续的存储单元存放自栈底到栈顶的数据元素，同时附设一个指针（top）来指示当前栈顶元素的位置。

//顺序栈的实现
#define MaxSize 50
typedef int Elemtype ;

typedef struct{
    Elemtype data[MaxSize];
    int top;
}SqStack;

//顺序栈的基本运算
    //（1）：初始化
    void InitStack(SqStack &S){
        S.top=-1;
    }
    //（2）：栈判空
    bool StackEmpty(SqStack S){
        if(S.top==-1)
            return true;
        else
            return false;
    }
    //（3）：进栈
    bool Push(SqStack &S,Elemtype x){
        if(S.top=MaxSize-1)
            return false;
        S.data[++S.top]=x;
        return true;
    }
    //（4）：出栈
    bool Pop(SqStack &S,Elemtype &x){
        if(S.top==-1)
            return false;
        x=S.data[S.top--];
        return true;
    }
    //（5）：读栈顶元素
    bool GetTop(SqStack S,Elemtype &x){
        if(S.top==-1)
            return false;
        x=S.data[S.top];
        return true;
    }
//共享栈：利用栈底位置相对不变的特性，可让两个顺序栈共享一个一维数组，将两个栈的栈底分别设置在共享空间的两端，两个栈顶向共享
//       空间的中间延伸，共享栈是为了更有效地利用存储空间
//栈的链式存储结构：采用链式存储的栈称为链栈，链栈的优点是便于多个栈共享存储空间和提高效率，且不存在栈满上溢的情况。通常采用
//               单链表实现，并规定所有操作都是在单链表的表头进行的。这里规定链栈没有头结点，Lhead 指向栈顶元素
//栈的链式存储
typedef struct Linknode{
    Elemtype data;
    struct Linknode *next;
}*LiStack;