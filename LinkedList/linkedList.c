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
