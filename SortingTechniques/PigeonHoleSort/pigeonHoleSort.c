#include<stdio.h>
#include<stdlib.h>
typedef struct _linked_list_node
{
int data;
struct _linked_list_node *next;
}LinkedListNode;

typedef struct _linked_list
{
LinkedListNode *front;
LinkedListNode *rear;
int size;
}LinkedList;

void addElementToLinkedList(LinkedList *linkedList,int data);

void initLinkedList(LinkedList *linkedList)
{
linkedList->front=NULL;
linkedList->rear=NULL;
linkedList->size=0;
}

void appendToLinkedList(LinkedList *linkedList,int num)
{
LinkedListNode *node=(LinkedListNode*)malloc(sizeof(LinkedListNode));
node->data=num;
node->next=NULL;
if(linkedList->size==0)
{
linkedList->front=node;
linkedList->rear=node;
linkedList->size++;
return;
}
linkedList->rear->next=node;
linkedList->rear=node;
linkedList->size++;
}

int removeFromLinkedList(LinkedList *linkedList)
{
LinkedListNode *node=linkedList->front;
int data=node->data;
linkedList->front=linkedList->front->next;
free(node);
linkedList->size--;
return data;
}

int isLinkedListEmpty(LinkedList *linkedList)
{
return linkedList->size==0;
}

void insertIntoLinkedList(LinkedList *linkedList,int data,int index)
{
LinkedListNode *newNode=(LinkedListNode*)malloc(sizeof(LinkedListNode));
newNode->data=data;
newNode->next=NULL;
LinkedListNode *node=linkedList->front;
for(int i=0;i<(index-1);i++) node=node->next;
newNode->next=node->next;
node->next=newNode;
linkedList->size++;
}

int main()
{
int x[10],y,size,i,max,min,range;
size=10;
for(y=0;y<size;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}

max=x[0];
for(i=1;i<size;i++)
{
if(x[i]>max) max=x[i];
}
min=x[0];
for(i=1;i<size;i++)
{
if(x[i]<min) min=x[i];
}

range=max-min+1;
LinkedList linkedList[range];
for(i=0;i<range;i++) initLinkedList(&linkedList[i]);

for(i=0;i<size;i++)
{
appendToLinkedList(&linkedList[(x[i]-min)],x[i]);
}

y=0;
for(i=0;i<range;i++)
{
while(!isLinkedListEmpty(&linkedList[i])) 
{
x[y]=removeFromLinkedList(&linkedList[i]);
y++;
}
}

for(i=0;i<size;i++) printf("%d\n",x[i]);
return 0;
}