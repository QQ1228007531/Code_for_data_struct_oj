#include <stdlib.h>
#include <stdio.h>
#define MaxSize 40   // ��������
//�뿴����������ֱ�ӻ������
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
        seq[i] = S.data[S.top-i]; // ��ջ����ջ��
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

int main(int argc, char **argv)
{
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
        case PUSH:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                scanf("%d", &e);
                status = Push(S, e);
            }
            outputStack(S);
            break;
        case POP:
            num = 0;
            scanf("%d", &num);
            while (num > 0)
            {
                num--;
                status = Pop(S, &e);
                if(status)
                {
                    printf("Pop: %d\n", e);
                    outputStack(S);
                }
                else
                {
                    printf("Pop failed\n");
                }
            }
            break;
        case GET_TOP:
            status = GetTop(*S, &e);
            if(status)
            {
                printf("GetTop: %d\n", e);
                outputStack(S);
            }
            else
            {
                printf("GetTop failed\n");
            }
            break;
        case STACK_EMPTY:
            status = StackEmpty(*S);
            if(status)
            {
                printf("The Stack is Empty\n");
            }
            else
            {
                printf("The Stack is not Empty\n");
                outputStack(S);
            }
            break;
        default:
            break;
        }
    }
    free(S);
    return 0;
}
/**
 * 1002��Ψһһ���Ҿ������������Ŀ
�Ͼ�������Ŀ������������������Щ��ȭ���ȵ�
����Ҫд�ľ�ֻ�ǶԴ���ע�͵�һЩ�������
������pop��push������++��--��λ�����⣨�����ʵҲӦ���ǿ���Ҫ���ġ�����
pushԪ�ص�ʱ����Ҫ���ƶ�top��top�����þ����ó�����ʵ�������ϴ���ָ�룩�ٷ�Ԫ��
|	|						|	|
|	|			�����ƶ�top  	|	|
|	|			------	--------> 	|	|
|	|						|	|
|	|						|	|	<--top == 0�����Է���Ԫ�أ���ʱջ��Ϊ�գ�						

	<-- ��ʼtop==-1 ����Ϊջ��������
ͨ���򵥵�ʾ��ͼ��ϣ�����ܽ����pushԪ�ز����������Լ�ΪʲôҪ���ƶ�ָ���ٷ���Ԫ��
pop����Ҳ�����������ͼ���Ƶر�ʾ�������û��ˡ���Ӳ��Ҫ˵���ҿɲ�����������ֻ�ƶ�top���⵱Ȼû����
����һ���������pop��Ԫ�غ����ǻ��ڴ��ܹ��������pop������Ԫ�ؼ�¼����
���Ի���Ҫ�ȸ�ֵ���ƶ�ָ�롣
*/