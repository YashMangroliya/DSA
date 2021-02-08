#include<stdio.h>
#include<stdlib.h>
int divisor=1;

int getHashCode(int num)
{
return (num/divisor);
}

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
int x[10],y,size,hashCode,i,largest,dc,j;
LinkedList boxes[10];
for(i=0;i<10;i++) initLinkedList(&boxes[i]);

size=10;
for(y=0;y<size;y++)
{
printf("Enter a number: ");
scanf("%d",&x[y]);
}
largest=x[0];
int num;
for(y=1;y<size;y++)
{
if(x[y]>largest) largest=x[y];
}
dc=1;
while(largest>9)
{
largest/=10;
dc++;
}
i=0;
while(i<(dc-1))
{
divisor*=10;
i++;
}
for(i=0;i<size;i++)
{
hashCode=getHashCode(x[i]);
addElementToLinkedList(&boxes[hashCode],x[i]);
}
for(j=0,i=0;i<10;i++)
{
while(isLinkedListEmpty(&boxes[i])==0)
{
x[j]=removeFromLinkedList(&boxes[i]);
j++;
}
}
for(i=0;i<size;i++) printf("%d\n",x[i]);
return 0;
}

void addElementToLinkedList(LinkedList *linkedList,int data)
{
linkedList->size++;
LinkedListNode *node=linkedList->front;
LinkedListNode *newNode=(LinkedListNode*)malloc(sizeof(LinkedListNode));
newNode->data=data;
newNode->next=NULL;
if(node==NULL)
{
linkedList->front=newNode;
linkedList->rear=newNode;
return;
}
if(node->data>data)
{
newNode->next=node;
linkedList->front=newNode;
return;
}
while(node->next!=NULL && node->next->data<data)
{
node=node->next;
}
newNode->next=node->next;
node->next=newNode;
return;
}
