#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int myComparator(void*,void*);
void quickSort(void *ptr,int cs,int es,int (*p2f)(void*,void*))
{
int top,e,f,lb,ub,pp;
int *stack;
void *c=(void*)malloc(es);
stack=(void*)malloc(es*cs*2);
top=cs;
top--;
*(stack+(top*2+0))=0;
*(stack+(top*2+1))=top;
while(top!=cs)
{
lb=*(stack+(top*2+0));
ub=*(stack+(top*2+1));
top++;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && p2f(ptr+(e*es),ptr+(lb*es))<=0) e++;
while(p2f(ptr+(f*es),ptr+(lb*es))>0) f--;
if(e<f)
{
memcpy(c,ptr+(e*es),es);
memcpy(ptr+(e*es),ptr+(f*es),es);
memcpy(ptr+(f*es),c,es);
}
else
{
memcpy(c,ptr+(f*es),es);
memcpy(ptr+(f*es),ptr+(lb*es),es);
memcpy(ptr+(lb*es),c,es);
}
}
pp=f;
if(pp+1<ub)
{
top--;
*(stack+(top*2+0))=pp+1;
*(stack+(top*2+1))=ub;
}
if(lb<pp-1)
{
top--;
*(stack+(top*2+0))=lb;
*(stack+(top*2+1))=pp-1;
}
}
}
struct Student
{
int rollNumber;
char name[20];
};
int myComparator(void* left,void* right)
{
struct Student *s1,*s2;
s1=(struct Student*)left;
s2=(struct Student*)right;
return s1->rollNumber-s2->rollNumber;
}
int main()
{
int y,req;
struct Student *students;
printf("Enter requirement: ");
scanf("%d",&req);
students=(struct Student*)malloc(sizeof(struct Student)*req);
for(y=0;y<req;y++)
{
printf("Enter roll number: ");
scanf("%d",&((students+y)->rollNumber));
printf("Enter name: ");
scanf("%s",(students+y)->name);
}
quickSort(students,req,sizeof(struct Student),myComparator);
for(y=0;y<req;y++)
{
printf("Roll Number: %d, Name: %s\n",(students+y)->rollNumber,(students+y)->name);
}
return 0;
}