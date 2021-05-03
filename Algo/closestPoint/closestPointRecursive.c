#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct point
{
int x,y;
}Point;

typedef struct pointPair
{
Point *point1;
Point *point2;
float distance;
}PointPair;

PointPair* closestPoints(int points[][2],int lb,int ub)
{
int even,divider,size;
size=ub-lb+1;
even=!(size%2);
if(even) divider=size/2-1;
else divider=size/2;
PointPair *pointPair,*lowerClosestPair,*upperClosestPair;
if(size>2)
{
if(even)
{
lowerClosestPair=closestPoints(points,lb,lb+divider);
upperClosestPair=closestPoints(points,lb+divider+1,ub);
}
else
{
lowerClosestPair=closestPoints(points,lb,lb+divider);
upperClosestPair=closestPoints(points,lb+divider,ub);
}
if(lowerClosestPair->distance<upperClosestPair->distance)
{
free(upperClosestPair->point1);
free(upperClosestPair->point2);
free(upperClosestPair);
return lowerClosestPair;
}
else 
{
free(lowerClosestPair->point1);
free(lowerClosestPair->point2);
free(lowerClosestPair);
return upperClosestPair;
}
}
else
{
pointPair=(PointPair*)malloc(sizeof(PointPair));
Point* point1=(Point*)malloc(sizeof(Point));
Point* point2=(Point*)malloc(sizeof(Point));
point1->x=points[lb][0];
point1->y=points[lb][1];
point2->x=points[ub][0];
point2->y=points[ub][1];
pointPair->point1=point1;
pointPair->point2=point2;
pointPair->distance=sqrt(pow(points[lb][0]-points[ub][0],2)+pow(points[lb][1]-points[ub][1],2));
return pointPair;
}
}



int main()
{
int points[][2]={{1,3},{1,3},{4,8},{1,6},{2,7},{1,8},{2,3},{5,10},{3,9},{4,10},{5,7},{3,5}};
PointPair* pointPair;
int y,z,numX,numY,size,e;
size=12;
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
pointPair=closestPoints(points,0,size-1);
printf("Closest pair is (%d,%d) ,(%d,%d)\n",pointPair->point1->x,pointPair->point1->y,pointPair->point2->x,pointPair->point2->y);
free(pointPair->point1);
free(pointPair->point2);
free(pointPair);
return 0;
}