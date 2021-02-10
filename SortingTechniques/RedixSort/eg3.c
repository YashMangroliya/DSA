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
int x[10],y,largest,num,k,dc,e,f,i,j,lb1,ub1,lb2,ub2,size,g,index;
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

size=10;
i=0;
j=-1;
lb1=-1;
ub1=-1;
lb2=size;
ub2=size;
while(i<size)
{
if(x[i]<0)
{
lb1=0;
j++;
g=x[i]*(-1);
x[i]=x[j];
x[j]=g;
}
i++;
}

ub1=j;
lb2=j+1;
if(j!=size-1) ub2=size-1;

// for negative numbers
largest=x[lb1];
i=lb1+1;
while(i<=ub1)
{
if(x[i]>largest) largest=x[i];
i++;
}
dc=1;
while(largest>9)
{
largest/=10;
dc++;
}
e=10;
f=1;
while(dc>0)
{
for(i=lb1;i<=ub1;i++)
{
index=(x[i]%e)/f;
addToQueue(&queues[index],x[i]);
}
for(i=0,j=lb1;i<10;i++)
{
while(!isQueueEmpty(&queues[i]))
{
x[j]=removeFromQueue(&queues[i]);
j++;
}
}
e*=10;
f*=10;
dc--;
}
//for positive numbers

largest=x[lb2];
i=lb2+1;
while(i<=ub2)
{
if(x[i]>largest) largest=x[i];
i++;
}
dc=1;
while(largest>9)
{
largest/=10;
dc++;
}
e=10;
f=1;
while(dc>0)
{
for(i=lb2;i<=ub2;i++)
{
index=(x[i]%e)/f;
addToQueue(&queues[index],x[i]);
}
for(i=0,j=lb2;i<10;i++)
{
while(!isQueueEmpty(&queues[i]))
{
x[j]=removeFromQueue(&queues[i]);
j++;
}
}
e*=10;
f*=10;
dc--;
}


i=lb1;
j=ub1;
while(i<=j)
{
g=x[i]*(-1);
x[i]=x[j]*(-1);
x[j]=g;
i++;
j--;
}


for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}