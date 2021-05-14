// here we have implemented BST inorder using RECURSIVE ALGORITHM
#include<stdio.h>
#include<stdlib.h>
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

void inOrder(BSTNode *t)
{
if(t==NULL) return;
inOrder(t->left);
printf("%d\n",t->data);
inOrder(t->right);
}

void printLeftNodes(BSTNode *t,int b)
{
if(t==NULL) return;
printLeftNodes(t->left,1);
if(b) printf("%d\n",t->data);
printLeftNodes(t->right,0); 
}

int main()
{
int ch,num;
while(1)
{
printf("1. Insert Data\n");
printf("2. In Order Traversal\n");
printf("3. Print Left Nodes\n");
printf("10. Exit\n");
printf("Enter your choice: ");
scanf("%d",&ch);
if(ch==1)
{
printf("Enter data to insert: ");
scanf("%d",&num);
insert(num);
}
if(ch==2)
{
inOrder(root);
}
if(ch==3)
{
printLeftNodes(root,0);  // 0 for false;
}
if(ch==10) break;
}
}