#include <stdlib.h>
#include <stdio.h>
#define MaxSize 40   // 数组容量
//想看分析的朋友直接划到最后
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
        seq[i] = S.data[S.top-i]; // 自栈顶至栈底
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
 * 1002是唯一一道我觉得有意义的题目
毕竟它是真的考察基础能力，不玩那些花拳绣腿的
这里要写的就只是对代码注释的一些扩充解释
首先是pop和push操作中++与--的位置问题（这个其实也应该是课上要讲的……）
push元素的时候，需要先移动top（top的作用就是用常量在实际意义上代替指针）再放元素
|	|						|	|
|	|			向上移动top  	|	|
|	|			------	--------> 	|	|
|	|						|	|
|	|						|	|	<--top == 0（可以放置元素，此时栈不为空）						

	<-- 初始top==-1 （即为栈空条件）
通过简单的示意图，希望我能讲清楚push元素操作的流程以及为什么要先移动指针再放置元素
pop操作也可以用上面的图类似地表示，我懒得画了。你硬是要说“我可不可以在这里只移动top”这当然没问题
可是一般而言我们pop出元素后我们会期待能够把这个被pop出来的元素记录下来
所以还是要先赋值再移动指针。
*/