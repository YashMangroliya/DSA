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
int x[10],y,largest,num,k,dc,e,f;
Queue queues[10];
y=0;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}

for(y=0;y<=9;y++) initQueue(&queues[y]);
largest=x[0];
for(y=0;y<=9;y++) if(x[y]>largest) largest=x[y];

dc=1;
while(largest>9)
{
largest=largest/10;
dc++;
}

e=10;
f=1;
while(dc>0)
{
y=0;
while(y<=9)
{
k=(x[y]%e)/f;
addToQueue(&queues[k],x[y]);
y++;
}
for(y=0,k=0;k<=9;k++)
{
while(!isQueueEmpty(&queues[k]))
{
num=removeFromQueue(&queues[k]);
x[y]=num;
y++;
}
}
e=e*10;
f=f*10;
dc--;
}
for(y=0;y<=9;y++) clearQueue(&queues[y]);

for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}