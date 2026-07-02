#include    <stdio.h>
#include    <stdlib.h>
//typedef 重命名结构体的用法：struct Node是一个结构体标签，重命名为Node
typedef struct  Node 
{
    int data;
    struct Node *next;//不能直接用Node*
}Node;

void print_list(Node* head)
{
    Node* p = head->next;
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
/*头插法*/
void push_ahead(Node* head, int value)
{
    //给新节点创建空间
    Node* new_node = (Node*)malloc(sizeof(Node));
    //先把后面串起来
    new_node->next = head->next;
    //在断开前面
    head->next = new_node;
    new_node->data = value;
}
/*尾插法*/
void push_back(Node* head, int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    //因为是最后，先把下一个节点地址定位空
    new_node->next = NULL;
    //创建一个临时指针
    Node* temp = head;
    //因为要判断是否是表尾
    while(temp->next != NULL)
    {
        //节点下一个不是空，还得接着找
        temp = temp->next;
    }
    //这个节点下一个为空，直接把他接到新节点前面
    temp->next = new_node;
}
/*初始化一个空链表*/
Node* Init_list(void)
{
    //这种链表是带头结点的，头节点不包含数据，指针域永远指向第一个有效节点
    Node* head = (Node*)malloc(sizeof(Node));
    if(head == NULL)
    {
        printf("fail\n");
        return NULL;
    }
    head->next = NULL;
    return head;
}
/*查找*/
Node* find_node(Node* head, int value)
{
    //头节点不用找，所以从head->next开始
    Node* temp = head->next;
    while(temp != NULL)
    {
        if(temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
/*删除节点*/
void delete_node(Node* head, int value)
{
    //如果从head->next开始就会漏掉第一个
    Node* temp = head;
    //判断下一个是否为空
    while(temp->next != NULL)
    {
        //要保证123，2掉后，13能连接，所以要通过1的指针域去判断
        if(temp->next->data == value)
        {
            //保存2的地址，2丢了的话3的地址也丢了
            Node* delete = temp->next;
            //将1的指针域改为3的地址
            temp->next = delete->next;
            //释放2的空间
            free(delete);
            return;
        }
        temp = temp->next;
    }
}
/*摧毁链表*/
void destroy_list(Node** head)//一定要传递二级指针，要将头节点置为空
{
    Node* temp = *head;
    while(temp->next != NULL)
    {
        //存储当下一个节点的地址
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("success to destroy\n");
}
int main(void)
{
    Node* head = Init_list();
    push_back(head,1);
    push_back(head,2);
    push_back(head,3);
    //printf("%p\n",(void*)find_node(head, 3));
    delete_node(head,1);
    print_list(head);    
    destroy_list(&head);
    printf("%p\n",(void*)head);
    return 0;
}