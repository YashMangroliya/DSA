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
int x[10],y,largest,num,k,dc,e,f,size;
Queue queues[10];
y=0;
while(y<10)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
y++;
}

for(y=0;y<=9;y++) initQueue(&queues[y]);

size=10;
int tmp[size];

int lb1,ub1,lb2,ub2,i,j,index;
lb1=-1;
ub1=-1;
lb2=size;
ub2=size;
for(y=0;y<size;y++)
{
if(x[y]<0)
{
lb1=0;
ub1++;
num=x[y]*(-1);
tmp[ub1]=num;
}
else
{
lb2--;
ub2=size-1;
tmp[lb2]=x[y];
}
}


// for negative numbers

largest=tmp[lb1];
printf("Largest: %d\n",largest);
i=lb1+1;
while(i<=ub1)
{
if(tmp[i]>largest) largest=tmp[i];
i++;
}
printf("Largest: %d\n",largest);
dc=1;
while(largest>9)
{
largest/=10;
dc++;
}
printf("dc: %d\n",dc);
e=10;
f=1;
while(dc>0)
{
for(i=lb1;i<=ub1;i++)
{
index=(tmp[i]%e)/f;
addToQueue(&queues[index],tmp[i]);
}
for(i=0,j=lb1;i<10;i++)
{
while(!isQueueEmpty(&queues[i]))
{
tmp[j]=removeFromQueue(&queues[i]);
j++;
}
}
e*=10;
f*=10;
dc--;
}
printf("lb2 %d\n",lb2);
printf("ub2 %d\n",ub2);
printf("lb1 %d\n",lb1);
printf("ub1 %d\n",ub1);

//for positive numbers

largest=tmp[lb2];
printf("Largest: %d\n",largest);
i=lb2+1;
while(i<=ub2)
{
if(tmp[i]>largest) largest=tmp[i];
i++;
}
printf("Largest: %d\n",largest);
dc=1;
while(largest>9)
{
largest/=10;
dc++;
}
printf("dc: %d\n",dc);
e=10;
f=1;
while(dc>0)
{
for(i=lb2;i<=ub2;i++)
{
index=(tmp[i]%e)/f;
addToQueue(&queues[index],tmp[i]);
}
for(i=0,j=lb2;i<10;i++)
{
while(!isQueueEmpty(&queues[i]))
{
tmp[j]=removeFromQueue(&queues[i]);
j++;
}
}
e*=10;
f*=10;
dc--;
}

// copying back to x array

int lb3=0;
i=ub1;
while(i>=lb1)
{
x[lb3]=tmp[i]*(-1);
i--;
lb3++;
}

i=lb2;
while(i<=ub2)
{
x[lb3]=tmp[i];
lb3++;
i++;
}






for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}