#include<stdio.h>
#include<math.h>
int main()
{
int points[][2]={{1,3},{4,8},{1,6},{2,7},{1,8},{2,3},{5,10},{2,3},{4,10},{5,7}};
int y,z,size,numX,numY,e,even,divider,size1,size2;
int lowerFirstPoint,lowerSecondPoint,f;
float lowerSmallest,upperSmallest,d;
int upperFirstPoint,upperSecondPoint;
int firstPoint,secondPoint;
size=10;
size2=size;
even=!(size%2);
y=1;
while(y<size)
{
z=y-1;
numX=points[y][0];
numY=points[y][1];
while(points[z][0]>numX && z>=0)
{
points[z+1][0]=points[z][0];
points[z+1][1]=points[z][1];
z--;
}
points[z+1][0]=numX;
points[z+1][1]=numY;
y++;
}


for(e=0;e<size;e++)
{
printf("(%d,%d)\n",points[e][0],points[e][1]);
}


if(even) divider=size/2-1;
else divider=size/2;

// agar even hai to divider ko add karna hai lower side me
// agar odd hai to divider ko add NHI karna hai 



// lower half

if(even) size1=divider+1;
else size1=divider;
//printf("Size1: %d\n",size1);
lowerSmallest=sqrt(pow((points[1][0]-points[0][0]),2)+pow((points[1][1],points[0][1]),2));
for(e=0;e<size1-1;e++)
{
for(f=e+1;f<size1;f++)
{
d=sqrt(pow((points[e][0]-points[f][0]),2)+pow((points[e][1]-points[f][1]),2));
if(d<lowerSmallest)
{
lowerSmallest=d;
lowerFirstPoint=e;
lowerSecondPoint=f;
//printf("%f\n",d);
//printf("e: %d\n",e);
//printf("f: %d\n",f);
}
}
}
printf("Closest pair of lower half is (%d,%d) ,(%d,%d)\n",points[lowerFirstPoint][0],points[lowerFirstPoint][1],points[lowerSecondPoint][0],points[lowerSecondPoint][1]);



//upper half

e=divider+1;
upperSmallest=sqrt(pow((points[e+1][0]-points[e][0]),2)+pow((points[e+1][1],points[e][1]),2));
for(;e<size2-1;e++)
{
for(f=e+1;f<size2;f++)
{
d=sqrt(pow((points[e][0]-points[f][0]),2)+pow((points[e][1]-points[f][1]),2));
if(d<upperSmallest)
{
upperSmallest=d;
upperFirstPoint=e;
upperSecondPoint=f;
//printf("%f\n",d);
//printf("%d\n",e);
//printf("%d\n",f);
}
}
}

printf("Closest pair of upper half is (%d,%d) ,(%d,%d)\n",points[upperFirstPoint][0],points[upperFirstPoint][1],points[upperSecondPoint][0],points[upperSecondPoint][1]);

if(lowerSmallest<upperSmallest)
{
firstPoint=lowerFirstPoint;
secondPoint=lowerSecondPoint;
}
else
{
firstPoint=upperFirstPoint;
secondPoint=upperSecondPoint;
}
printf("Marked pair is (%d,%d) ,(%d,%d)\n",points[firstPoint][0],points[firstPoint][1],points[secondPoint][0],points[secondPoint][1]);
return 0;
}