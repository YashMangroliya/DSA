#include<stdio.h>
#include<stdlib.h>
typedef struct _queue_node
{
int data;
struct _queue_node * next;
}QueueNode;

typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;

void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}

void addToQueue(Queue *queue,int data)
{
QueueNode *node;
node=(QueueNode*)malloc(sizeof(QueueNode));
node->data=data;
node->next=NULL;
if(queue->start==NULL)
{
queue->start=node;
queue->end=node;
}
else
{
queue->end->next=node;
queue->end=node;
}
queue->size++;
}

int removeFromQueue(Queue *queue)
{
QueueNode *node;
node=queue->start;
int data=node->data;
queue->start=queue->start->next;
if(queue->start==NULL) queue->end=NULL;
free(node);
queue->size--;
return data;
}

int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}

void clearQueue(Queue *queue)
{
QueueNode *queueNode;
while(queue->start!=NULL)
{
queueNode=queue->start;
queue->start=queue->start->next;
queue->size--;
free(queueNode);
}
queue->end=NULL;
queue->size=0;
}

int main()
{
Queue queue;
initQueue(&queue);
addToQueue(&queue,10);
printf("%d",removeFromQueue(&queue));
return 0;
}