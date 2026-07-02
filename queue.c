#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
//队列需要一个头指针和尾指针（节点指针），这样访问更加高效，不然用尾插法需要一直遍历到尾部
typedef struct queue
{
    Node* front;
    Node* rear;
}queue;
//初始化头尾都是空
void init_queue(queue* q)
{
    q->front = NULL;
    q->rear = NULL;
}
//进队：传入头尾节点指针
void enqueue(queue* q,int value)
{
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    //在尾部插入，节点下一个直接指向空
    new_node->next = NULL;
    //判断队列是否为空，头尾指针等价，如果为空头尾指针都指向插入的节点
    if(q->rear == NULL)
    {
        q->front = new_node;
        q->rear = new_node;
    }
    else
    {
        q->rear->next = new_node;//现在的rear是还没插队的队尾，以前的队尾下一个是新节点
        q->rear = new_node;
    }
}
//出队
int dequeue(queue* q)
{
    //队列为空则直接返回
    if(q->front == NULL)
    {
        return -999;
    }
    //出队需要从头部出，保存目前头指针
    Node* temp = q->front;
    //出队取出数据
    int value = temp->data;
    //头指针变为之前后面的节点
    q->front = q->front->next;
    //当头指针为0说明取完，尾指针也要置为0
    if(q->front == NULL)
    {
        q->rear = NULL;
    }
    //释放头指针空间
    free(temp);
    return value;
}
void print_queue(queue* q)
{
    Node* temp = q->front;
    while(temp != NULL)
    { 
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main(void)
{
    queue q;
    init_queue(&q);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    print_queue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    print_queue(&q);
    return 0;
}