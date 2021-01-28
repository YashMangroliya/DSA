#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void bubbleSort(void * ptr,int cs,int es,int (*p2f)(void* ,void *))
{
int m,e,f,w;
m=cs-2;
void *a,*b,*c;
c=(void*)malloc(es);
while(m>=0)
{
e=0;
f=1;
while(e<=m)
{
a=ptr+(e*es);
b=ptr+(f*es);
w=p2f(a,b);
if(w>0)
{
memcpy(c,(const void*)a,es);
memcpy(a,(const void*)b,es);
memcpy(b,(const void*)c,es);
}
e++;
f++;
}
m--;
}
free(c);
}



struct Student
{
int rollNumber;
char name[21];
};

int studentComparator(void * left,void* right)
{
struct Student *s1,*s2;
s1=(struct Student*) left;
s2=(struct Student*) right;
return strcmp(s1->name,s2->name);
}

int main()
{
int req,y;
printf("Enter requirement: ");
scanf("%d",&req);
struct Student *students,*j;
students=(struct Student*)malloc(sizeof(struct Student)*req);
j=students;
for(y=0;y<req;y++)
{
printf("Enter roll number: ");
scanf("%d",&((j+y)->rollNumber));
printf("Enter name: ");
scanf("%s",(j+y)->name);
}
bubbleSort(students,req,sizeof(struct Student),studentComparator);
for(y=0;y<req;y++)
{
printf("RollNumber %d Name %s\n",students[y].rollNumber,students[y].name);
}
free(students);
return 0;
}