#include <stdlib.h>
#include <stdio.h>
#define MaxSize 40   // ��������
//�뿴�����Ľ���ֱ�ӻ������
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
    int top; // ջ��ָ��
} Stack;     // �ṹ��������

typedef struct
{
    Stack *stack_in;
    Stack *stack_out;
} Queue;


/**
 * ��ʼ��һ��ջ
 * @param S
 */
void InitStack(Stack *s)
{
    s->top = -1;
}

/**
 * ��ջ����һ��Ԫ��
 * @param S ����ջ
 * @param e ������
 * @return �ɹ�����1�����򷵻�0
 */
int Push(Stack *s, DataType e)
{
    //todo
    if ( s->top < MaxSize -1 )
    {
        s -> data [ ++( s -> top ) ] = e ;//��++�ٸ�ֵ
        return 1 ;
    }
    else 
    {
        return 0 ;
    }

}

/**
 * ��ջ�е���һ��Ԫ��
 * @param S ����ջ
 * @param e ����ջ������ֵ
 * @return �ɹ�����1�����򷵻�0
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
        *e = S -> data[ ( S->top )-- ] ;//�ȷ�����--
        return 1 ; 
    }

}

/**
 * ��ȡջ��Ԫ�أ���ɾ����Ԫ��
 * @param S ����ջ
 * @param e ����ջ��Ԫ��
 * @return �ɹ�����1�����򷵻�0
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
 * �ж�ջ�Ƿ�գ�Ϊ�շ���1�����򷵻�0
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
 * ��ȡջ��һ�����鿽��
 * @param S ����ջ
 * @param seq ջ��Ԫ�ص�һ������
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
 * ����ջ��ʹ�ó���
 * @param S ����ջ
 * @return ����ջ�ĳ���
 */
int StackLength(Stack S)
{
    return S.top + 1;
}

/**
 * ��ʼ������
 * @param Q ��������
 */
void InitQueue(Queue *Q)
{
    Q->stack_in = (Stack *)malloc(sizeof(Stack));
    Q->stack_out = (Stack *)malloc(sizeof(Stack));
    InitStack(Q->stack_in);
    InitStack(Q->stack_out);
}

/**
 * ��ȡ����ͷ����ɾ��Ԫ�أ�
 * @param Q ��������
 * @param e ���ܶ���ͷԪ��
 * @return ����ɹ���ȡ����1�����򷵻�0
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
 * �ж϶����Ƿ�Ϊ��
 * @param Q ��������
 * @return ���Ϊ�շ���1�����򷵻�0
 */
int QueueEmpty(Queue Q)
{
    //todo
    if ( Q.stack_in->top == -1 && Q.stack_out->top == -1 ) return 1 ;
    else return 0 ;

}

/**
 * ��Ӳ�������Ԫ�ز�����У���Ҫ���������������������ͼ�����
 * @param Q ��������
 * @param e �����Ԫ��
 * @return �������ɹ�����1�����򷵻�0
 */
int EnQueue(Queue *Q, DataType e)
{
    //todo
    if ( Q->stack_in->top + Q->stack_out->top == MaxSize - 2 ) return 0 ;
    else return Push( Q->stack_in , e ) ;
}

/**
 * ���Ӳ������Ӷ�����ȡ��һ��Ԫ��
 * @param Q ��������
 * @param e ���ܳ���Ԫ��
 * @return ����ɹ�ȡ������1�����򷵻�0
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
 * ��ն��� ��������
 * @param Q
 */
void ClearQueue(Queue *Q)
{
    InitStack(Q->stack_in);
    InitStack(Q->stack_out);
}

/**
 *
 * @param Q ��������
 * @return ���ض�����ʹ�ó���
 */
int QueueLength(Queue Q)
{
    return StackLength(*Q.stack_in) + StackLength(*Q.stack_out);
}

/**
 * ��ȡ���е�һ�����鿽��
 * @param Q ��������
 * @param seq ջ��Ԫ�ص�һ������
 */
/**void QueueToArray(Queue Q, DataType *seq)
{
    //todo
    for (int i = 0 ; i <= Q.stack_out->top ; i++ )
    {
        seq[ i ] = Q.stack_out->data [ Q.stack_out-> top - i ] ; // ��ջ����ջ��
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
�����һ���Ҫ�²۵������ĸ����������ķ�������ʵ��ʵ����Ϊ��ľ��»�ƿ�ˡ���
�����Ŀ��˼����ʵ���Դ����������Ǹ���length������֪һ��
������������һ������stackout���³ơ���ջ�����ĸ����ռ䣨ͬ���³�stackinΪ����ջ����
ÿ�ε����������ʱ�����ǾͰ����ݽ���push����ջ
����������Ҫ������ʱ������Ҫʵ��ջ�ġ��Ƚ��ȳ���ԭ����������Ҫ��ͷԪ�ظ�pop����
����Ϊ����˳���ʾ��ջ������һ����ֱ�۵�˼·����������ǰ���ջ������������������ڸ�ջ�ͺ���
�����Ļ���ջ�������Ԫ�ؾͻ��ɸ�ջ�ĵ�һ��Ԫ�أ�����ֻҪֱ��pop��ջ�ĵ�һ��Ԫ�ؾ����
��ŵ�һ�����̿����������ʾ��ͼ��ʾ
|     |   |   |         |   |   |     |         |     |   |     |
|  4  |   |   |         |   |   |  1  |         |     |   |  1  |
|  3  |   |   |  ---->  |   |   |  2  | ---->   |  7  |   |  2  |
|  2  |   |   |         |   |   |  3  |         |  6  |   |  3  |
|  1  |   |   |         |   |   |  4  |         |  5  |   |  4  |
  in     out              in       out            in     out
| 1 2 3 4 |                                     | 5 6 7 1 2 3 4 |
*/