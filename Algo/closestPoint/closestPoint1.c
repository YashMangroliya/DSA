#include<stdio.h>
#include<math.h>
int main()
{
int points[][2]={{1,3},{4,8},{1,6},{2,7},{1,8},{2,3},{5,10},{2,3},{4,10},{5,7}};
int y,z,size,numX,numY,e,even,divider,size1,size2,l,u,i,j,dividerX;
int lowerFirstPoint,lowerSecondPoint,f;
float lowerSmallest,upperSmallest,d;
int upperFirstPoint,upperSecondPoint;
int firstPoint,secondPoint;
size=10;
size2=size;
even=!(size%2);
// sorting given array of points according on the basis of X-axis
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

// deciding divider
if(even) divider=size/2-1;
else divider=size/2;

// agar even hai to divider ko add karna hai lower side me
// agar odd hai to divider ko dono side add karna hai 



// lower half

size1=divider+1;
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

if(even) e=divider+1;
else e=divider;
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

// checking for the remaining values around divider.(Lecture 54/3 Assignment)

printf("Closest pair of upper half is (%d,%d) ,(%d,%d)\n",points[upperFirstPoint][0],points[upperFirstPoint][1],points[upperSecondPoint][0],points[upperSecondPoint][1]);
printf("Lower Smallest: %f\n",lowerSmallest);
printf("Upper Smallest: %f\n",upperSmallest); 
if(lowerSmallest<=upperSmallest)
{
firstPoint=lowerFirstPoint;
secondPoint=lowerSecondPoint;
if(even) dividerX=(points[divider][0]+points[divider+1][0])/2;
else dividerX=points[divider][0];
printf("DividerX: %d\n",dividerX);
l=divider;
while(l>=0 && (dividerX-points[l][0])<=lowerSmallest) l--;
l++;
printf("l: %d\n",l);
if(even) u=divider+1;
else u=divider;
while(u<size && (points[u][0]-dividerX)<=lowerSmallest) u++;
u--;
printf("u: %d\n",u);
printf("Divider: %d\n",divider);
// if there are event number of points then we have to consider divider line's points on left side
if(even)
{
for(i=l;i<=divider;i++)
{
for(j=divider+1;j<=u;j++)
{
printf("%d,%d\n",i,j);
if(sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2))<lowerSmallest)
{
printf("Here also\n");
lowerSmallest=sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2));
firstPoint=i;
secondPoint=j;
}
}
}//for
}
else
{
for(i=l;i<divider;i++)
{
for(j=divider;j<=u;j++)
{
printf("%d,%d\n",i,j);
if(sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2))<lowerSmallest)
{
printf("Here also\n");
lowerSmallest=sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2));
firstPoint=i;
secondPoint=j;
}
}
}//for
}







}
else
{
printf("Reached Here\n");
int dividerX;
firstPoint=upperFirstPoint;
secondPoint=upperSecondPoint;
if(even) dividerX=(points[divider][0]+points[divider+1][0])/2;
else dividerX=points[divider][0];
printf("DividerX: %d\n",dividerX);
l=divider;
while(l>=0 && (dividerX-points[l][0])<=upperSmallest) l--;
l++;
printf("l: %d\n",l);
if(even) u=divider+1;
else u=divider;
while(u<size && (points[u][0]-dividerX)<=upperSmallest) u++;
u--;
printf("u: %d\n",u);
printf("Divider: %d\n",divider);
for(i=l;i<=divider;i++)
{
for(j=divider+1;j<=u;j++)
{
printf("%d,%d\n",i,j);
if(sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2))<upperSmallest)
{
printf("Here also\n");
upperSmallest=sqrt(pow((points[i][0]-points[j][0]),2)+pow((points[i][1]-points[j][1]),2));
firstPoint=i;
secondPoint=j;
}
}
}//for
}
printf("Marked pair is (%d,%d) ,(%d,%d)\n",points[firstPoint][0],points[firstPoint][1],points[secondPoint][0],points[secondPoint][1]);
return 0;
}