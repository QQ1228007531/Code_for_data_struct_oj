#include <stdlib.h>
#include <stdio.h>
#define MaxSize 40   // 数组容量
//想看分析的建议直接划到最后
#define PUSH 0
#define POP 1
#define GET_TOP 2
#define STACK_EMPTY 3
#define EXIT -1
#define ENQUEUE 4
#define DEQUEUE 5
#define GET_HEAD 6
#define QUEUE_EMPTY 7
#define EXIT -1

typedef int DataType;
typedef struct
{
    DataType data[MaxSize];
    int top; // 栈顶指针
} Stack;     // 结构体类型名

typedef struct
{
    Stack *stack_in;
    Stack *stack_out;
} Queue;


/**
 * 初始化一个栈
 * @param S
 */
void InitStack(Stack *s)
{
    s->top = -1;
}

/**
 * 向栈插入一个元素
 * @param S 操作栈
 * @param e 操作数
 * @return 成功返回1，否则返回0
 */
int Push(Stack *s, DataType e)
{
    //todo
    if ( s->top < MaxSize -1 )
    {
        s -> data [ ++( s -> top ) ] = e ;//先++再赋值
        return 1 ;
    }
    else 
    {
        return 0 ;
    }

}

/**
 * 从栈中弹出一个元素
 * @param S 操作栈
 * @param e 接受栈弹出的值
 * @return 成功返回1，否则返回0
 */
int Pop(Stack *S, DataType *e)
{
    //todo
    if ( S->top == -1 )
    {
        return 0 ;
    }
    else 
    {
        *e = S -> data[ ( S->top )-- ] ;//先返回再--
        return 1 ; 
    }

}

/**
 * 获取栈顶元素，不删除该元素
 * @param S 操作栈
 * @param e 接受栈顶元素
 * @return 成功返回1，否则返回0
 */
int GetTop(Stack S, DataType *e)
{
    //todo
    if ( S.top == -1 )
    {
        return 0 ;
    }
    else
    {
        *e = S.data [ S.top ] ;
        return 1 ;
    }
}

/**
 * 判断栈是否空，为空返回1，否则返回0
 * @param S
 * @return
 */
int StackEmpty(Stack S)
{
    //todo
    if ( S.top == -1 )
    {
        return 1 ;
    }
    else return 0 ;
}

/**
 * 获取栈的一个数组拷贝
 * @param S 操作栈
 * @param seq 栈中元素的一个拷贝
 */
void StackToArray(Stack S, DataType *seq)
{
    int i = 0;
    for (; i <= S.top; i++)
    {
        seq[i] = S.data[S.top-i];
    }
}

/**
 * 返回栈已使用长度
 * @param S 操作栈
 * @return 返回栈的长度
 */
int StackLength(Stack S)
{
    return S.top + 1;
}

/**
 * 初始化队列
 * @param Q 操作队列
 */
void InitQueue(Queue *Q)
{
    Q->stack_in = (Stack *)malloc(sizeof(Stack));
    Q->stack_out = (Stack *)malloc(sizeof(Stack));
    InitStack(Q->stack_in);
    InitStack(Q->stack_out);
}

/**
 * 获取队列头（不删除元素）
 * @param Q 操作队列
 * @param e 接受队列头元素
 * @return 如果成功获取返回1，否则返回0
 */
int GetHead(Queue Q, DataType *e)
{
    //todo
    if ( Q.stack_out->top != -1 )
    {
        *e = Q.stack_out->data[ Q.stack_out->top ] ;
        return 1 ;       
    }
    else
    {
        if ( Q.stack_in->top != -1 )
        {
            *e = Q.stack_in->data [ 0 ];
            return 1 ;
        }
        else return 0 ;
    }
    
    
}

/**
 * 判断队列是否为空
 * @param Q 操作队列
 * @return 如果为空返回1，否则返回0
 */
int QueueEmpty(Queue Q)
{
    //todo
    if ( Q.stack_in->top == -1 && Q.stack_out->top == -1 ) return 1 ;
    else return 0 ;

}

/**
 * 入队操作，将元素插入队列，需要处理队列满的情况（真满和假满）
 * @param Q 操作队列
 * @param e 插入的元素
 * @return 如果插入成功返回1，否则返回0
 */
int EnQueue(Queue *Q, DataType e)
{
    //todo
    if ( Q->stack_in->top + Q->stack_out->top == MaxSize - 2 ) return 0 ;
    else return Push( Q->stack_in , e ) ;
}

/**
 * 出队操作，从队列中取出一个元素
 * @param Q 操作队列
 * @param e 接受出队元素
 * @return 如果成功取出返回1，否则返回0
 */
int DeQueue(Queue *Q, DataType *e)
{
    //todo
    if ( Q->stack_out->top != -1 ) return Pop( Q->stack_out , e );
    while ( Q->stack_in->top != -1 )
    {
        DataType i;
        i = Q->stack_in->data [ ( Q->stack_in->top )-- ];
        Push( Q->stack_out , i ) ;
    }
    if ( Q->stack_out->top == -1 ) return 0 ;
    else return Pop( Q->stack_out , e ) ;    
}
    


/**
 * 清空队列 操作队列
 * @param Q
 */
void ClearQueue(Queue *Q)
{
    InitStack(Q->stack_in);
    InitStack(Q->stack_out);
}

/**
 *
 * @param Q 操作队列
 * @return 返回队列已使用长度
 */
int QueueLength(Queue Q)
{
    return StackLength(*Q.stack_in) + StackLength(*Q.stack_out);
}

/**
 * 获取队列的一个数组拷贝
 * @param Q 操作队列
 * @param seq 栈中元素的一个拷贝
 */
/**void QueueToArray(Queue Q, DataType *seq)
{
    //todo
    for (int i = 0 ; i <= Q.stack_out->top ; i++ )
    {
        seq[ i ] = Q.stack_out->data [ Q.stack_out-> top - i ] ; // 自栈顶至栈底
    }
    for (int i = 0; i <= Q.stack_in->top ; i++)
    {
        Q.stack_out->data [ i ] =  Q.stack_in->data [ Q.stack_in-> top - i ] ;
    }
    for (int i = 0 ; i <= Q.stack_in->top ; i++)
    {
        seq[ Q.stack_out->top + 1 + i ] = Q.stack_out->data [ Q.stack_in-> top - i ] ;
    }
    

}
*/

void QueueToArray(Queue Q, DataType *seq) {
    int index = 0;
    for (int i = Q.stack_out->top; i >= 0; i--) {
        seq[index++] = Q.stack_out->data[i];
    }
    for (int i = 0; i <= Q.stack_in->top; i++) {
        seq[index++] = Q.stack_in->data[i];
    }
}

void outputStack(Stack *S)
{
    int seq[MaxSize], i = 0;
    StackToArray(*S, seq);
    printf("Stack: ");
    for (i = 0; i < StackLength(*S); i++)
    {
        printf("%d", seq[i]);
        if(i<StackLength(*S)-1){
            printf(" ");
        }
    }
    printf("\n");
}


void outputQueue(Queue *Q)
{
    int seq[MaxSize], i = 0;
    QueueToArray(*Q, seq);
    printf("Queue: ");
    for (i = 0; i < QueueLength(*Q); i++)
    {
        printf("%d", seq[i]);
        if(i<QueueLength(*Q)-1){
            printf(" ");
        }
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    InitQueue(Q);
    Stack *S = (Stack *)malloc(sizeof(Stack));
    InitStack(S);

    int mode, num, e, status;
    while (scanf("%d", &mode))
    {
        if (mode == EXIT)
        {
            break;
        }
        switch (mode)
        {
        case ENQUEUE:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                scanf("%d", &e);
                status = EnQueue(Q, e);
            }
            outputQueue(Q);
            break;
        case DEQUEUE:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                status = DeQueue(Q, &e);
                if(status)
                {
                    printf("DeQueue: %d\n", e);
                    outputQueue(Q);
                }
                else
                {
                    printf("DeQueue failed\n");
                }
            }
            break;
        case GET_HEAD:
            status = GetHead(*Q, &e);
            if(status)
            {
                printf("GetHead: %d\n", e);
                outputQueue(Q);
            }
            else
            {
                printf("GetHead failed\n");
            }
            break;
        case QUEUE_EMPTY:
            status = QueueEmpty(*Q);
            if(status)
            {
                printf("The Queue is Empty\n");
            }
            else
            {
                printf("The Queue is not Empty\n");
                outputQueue(Q);
            }
            break;
        default:
            break;
        }
    }
    free(Q);
    free(S);
    return 0;
}
/**
首先我还是要吐槽到底是哪个天才想出来的方法，属实是实用性为零的精致花瓶了……
这个题目的思想其实可以从它给出的那个求length函数略知一二
就是他开辟了一个叫做stackout（下称“副栈”）的辅助空间（同理，下称stackin为“主栈”）
每次当我们输入的时候我们就把数据借助push进主栈
而当我们需要弹出的时候，由于要实现栈的“先进先出”原则，所以我们要把头元素给pop出来
又因为这是顺序表示的栈，所以一个很直观的思路就是如果我们把主栈的数据逐个弹出来放在副栈就好了
这样的话主栈的最底下元素就会变成副栈的第一个元素，这样只要直接pop副栈的第一个元素就完成
大概的一个过程可以用下面的示意图表示
|     |   |   |         |   |   |     |         |     |   |     |
|  4  |   |   |         |   |   |  1  |         |     |   |  1  |
|  3  |   |   |  ---->  |   |   |  2  | ---->   |  7  |   |  2  |
|  2  |   |   |         |   |   |  3  |         |  6  |   |  3  |
|  1  |   |   |         |   |   |  4  |         |  5  |   |  4  |
  in     out              in       out            in     out
| 1 2 3 4 |                                     | 5 6 7 1 2 3 4 |
*/