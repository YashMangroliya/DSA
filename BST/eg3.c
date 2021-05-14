// here we have implemented BST inorder using STACK ( NON-RECURSIVE ALGORITHM )
// and implemented DELETE , Height of BST, Number of Leaf Node
#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef struct _BSTNode
{
int data;
struct _BSTNode *left,*right;
}BSTNode;

BSTNode *root=NULL;
BSTNode* createBSTNode(int data)
{
BSTNode *t=(BSTNode*)malloc(sizeof(BSTNode));
t->data=data;
t->left=NULL;
t->right=NULL;
return t;
}
void insert(int data)
{
BSTNode *t,*j;
t=createBSTNode(data);
if(root==NULL)
{
root=t;
return;
}
j=root;
while(1)
{
if(t->data < j->data)
{
if(j->left==NULL)
{
j->left=t;
break;
}
else
{
j=j->left;
}
}
else
{
if(j->right==NULL)
{
j->right=t;
break;
}
else
{
j=j->right;
}
}
}
}

stack<BSTNode*> stk;
void inOrder()
{
// pushing nodes from root to extreme left in stack
BSTNode *t,*j;
t=root;
while(t!=NULL)
{
stk.push(t);
t=t->left;
}

// loop starts

while(!stk.empty())
{
j=stk.top();
stk.pop();
t=j->right;
while(t!=NULL)
{
stk.push(t);
t=t->left;
}
printf("%d\n",j->data);
}
}

void printLeftNodes(BSTNode *t,int b)
{
if(t==NULL) return;
printLeftNodes(t->left,1);
if(b) printf("%d\n",t->data);
printLeftNodes(t->right,0); 
}

void deleteNode(int data)
{
// inititally implementing searching algorithm
BSTNode *t,*j,*predecessor,*successor,*predecessorParent,*successorParent,*rightChild;
t=root;
// finding data to delete
while(t!=NULL)
{
if(t->data==data) break;
j=t;
if(data < t->data)
{
t=t->left;
}
else t=t->right;
}

if(t==NULL)
{
printf("Data not found");
return;
}

BSTNode ** p2p;
if(t==root)
{
p2p=&root;
}
else
{
if(t==j->left)
{
p2p=&(j->left);
}
else
{
p2p=&(j->right);
}
}


// handling leafNode case
if(t->right==NULL && t->left==NULL)
{
*p2p=NULL;
return;
}

// handling part where node will be replaced by successor
if(t->right!=NULL)
{
successor=t->right;
successorParent=NULL;
while(successor->left!=NULL)
{
successorParent=successor;
successor=successor->left;
}
if(successorParent!=NULL) successorParent->left=successor->right;
successor->left=t->left;
if(t->right!=successor) successor->right=t->right;
*p2p=successor;
}
else
{
// handling part where node will be replaced by predecor
predecessor=t->left;
predecessorParent=NULL;
while(predecessor->right!=NULL)
{
predecessorParent=predecessor;
predecessor=predecessor->right;
}
if(predecessorParent!=NULL) predecessorParent->right=predecessor->left;
predecessor->right=t->right;
if(t->left!=predecessor) predecessor->left=t->left;
*p2p=predecessor;
}
}

int getHeight(BSTNode *t)
{
if(t==NULL) return 0;
return max(getHeight(t->left),getHeight(t->right))+1;
}

int countLeafNodes()
{
// pushing nodes from root to extreme left in stack
int leafNodeCount=0;
BSTNode *t,*j;
t=root;
while(t!=NULL)
{
stk.push(t);
t=t->left;
}

// loop starts

while(!stk.empty())
{
j=stk.top();
stk.pop();
t=j->right;
while(t!=NULL)
{
stk.push(t);
t=t->left;
}
if(j->right==NULL && j->left==NULL) leafNodeCount++;
}
return leafNodeCount;
}

int main()
{
int ch,num;
while(1)
{
printf("1. Insert Data\n");
printf("2. In Order Traversal\n");
printf("3. Print Left Nodes\n");
printf("4. Delete Data\n");
printf("5. Get Height of BST\n");
printf("6. Number of Leaf Nodes\n");
printf("10. Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter data to insert: ");
scanf("%d",&num);
insert(num);
}
else if(ch==2)
{
inOrder();
}
else if(ch==3)
{
printLeftNodes(root,0);  // 0 for false;
}
else if(ch==4)
{
printf("Enter number: ");
scanf("%d",&num);
deleteNode(num);
}
else if(ch==5)
{
printf("Height of BST is %d\n\n",getHeight(root));
}
else if(ch==6)
{
printf("Number of Leaf Nodes : %d\n\n",countLeafNodes());
}
else if(ch==10) break;
}
}