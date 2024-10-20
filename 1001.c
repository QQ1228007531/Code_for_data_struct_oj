#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/// @brief 
typedef struct node
{
    char studentID[ 15 ] ;
    int Grade ;
    struct node *next ;
}StudentListNode;

StudentListNode *p , *q , *head ;

int m = sizeof ( StudentListNode ) ;

void createCrossLink(StudentListNode* a, StudentListNode* b, int beforeCross1, int beforeCross2)
{
    while(beforeCross1--)
    {
        a=a->next;
    }
    while(--beforeCross2)
    {
        b=b->next;
    }
    p = b->next;
    b->next = a;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
}

void destroyCrossLink(StudentListNode* a, StudentListNode* b, StudentListNode* crossNode){
    StudentListNode* p = crossNode->next, *q;
    while(p){
        q = p->next;
        free(p);
        p = q;
    }
    while(a != crossNode){
        q = a->next;
        free(a);
        a = q;
    }
    while(b != crossNode){
        q = b->next;
        free(b);
        b = q;
    }
    free(crossNode);
}

void printLinkedListNode(StudentListNode * node){
    printf("{ID:%s, Grade:%d}", node->studentID, node->Grade);
    if(node->next!=NULL){
        printf("->");
    }else{
        printf("\n");
    }
}

/** 以下部分是需要学生自己实现的 **/
/** 打印整个列表 **/
void outputStudentLinkedList(StudentListNode* head){
    // 用于单个节点输出的函数printLinkedListNode已提供
    // 请你实现遍历链表的逻辑
	// TODO
    p = head ;
    while ( p != NULL)
    {
        printLinkedListNode ( p ) ;
        p = p -> next ;
    }
    
}

/** 新建一个链表node并返回 **/
StudentListNode* createStudentLinkedList(char student_id[], int grade) {
    //tips:malloc的时候记得为转化为结构体指针
	//TODO
    p = malloc ( m ) ;
    //p -> studentID = student_id ; 
    //字符串不能直接赋值！
    strcpy ( p -> studentID , student_id ) ;
    p -> Grade = grade ;
    p -> next = NULL ;
    return p ;
}

/** 按照降序插入学生的成绩情况,并返回链表头指针 **/
StudentListNode* addStudentLinkedList(StudentListNode* head, StudentListNode* node) 
{
    if (head == NULL || head->Grade >= node->Grade) //根据样例结果要加=
    {
        node->next = head;
        return node; // 新节点成为新的头节点
    }
    StudentListNode *current = head;
    while (current->next != NULL && current->next->Grade >= node->Grade) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    return head;
}


/** 反转链表 **/
StudentListNode* reverseStudentLinkedList(StudentListNode* head)
{
    //TODO
    p = head , q = NULL ;
    while ( p != NULL )
    {
        StudentListNode *r = p -> next ;
        p -> next = q ;
        q = p ;
        p = r ;
    }
    return q ;
}

/** 找到相交的第一个结点 **/
StudentListNode* findCrossBeginNode(StudentListNode* class1, StudentListNode* class2) {
    // class1和class2在后一部分完全重合（结点的内存地址相同），请找出并返回开始相交的第一个结点。
    // 请不要简单地通过结点结构体的成员来判断。
    // TODO
    p = class1 , q = class2 ;
    while ( p != q )
    {
        p = p -> next ;
        q = q -> next ;
        if ( p == NULL )
        {
            p = class2 ;
        }
        if ( q == NULL )
        {
            q = class1 ;
        }
        
    }
    return p ;
}

int main()
{
    StudentListNode *class1=NULL, *class2=NULL;
    int num1, num2, i;
    char student_id[11];
    int grade;
    int beforeCross1, beforeCross2;
    StudentListNode *node;

    // 读取两个班级的人数
    scanf("%d%d", &num1, &num2);
    class1 = class2 = NULL;
    // 读取班级1的成绩
    for(i = 0;i < num1;i++){
        scanf("%s%d", student_id, &grade);
        node = createStudentLinkedList(student_id, grade);
        class1 = addStudentLinkedList(class1, node);
    }
    // 读取班级2的成绩
    for(i = 0;i < num2;i++){
        scanf("%s%d", student_id, &grade);
        node = createStudentLinkedList(student_id, grade);
        class2 = addStudentLinkedList(class2, node);
    }
    // 读取链表交叉之前的结点个数
    scanf("%d%d", &beforeCross1 , &beforeCross2 );

    // 输出1：存储列表结果
    printf("Store Linkedlist\n");
    outputStudentLinkedList(class1);
    outputStudentLinkedList(class2);

    // 执行反转链表操作
    class1 = reverseStudentLinkedList(class1);
    class2 = reverseStudentLinkedList(class2);

    // 输出2：反转列表结果
    printf("Reverse Linkedlist\n");
    outputStudentLinkedList(class1);
    outputStudentLinkedList(class2);

    // 创建交叉链表并找到第一个交点
    createCrossLink(class1, class2, beforeCross1, beforeCross2);
    node = findCrossBeginNode(class1, class2);

    // 输出3：链表交点
    printf("Cross node\n");
    printf("{ID:%s, Grade:%d}\n", node->studentID, node->Grade);

    // 销毁交叉链表
    destroyCrossLink(class1, class2, node);

    return 0;
}

