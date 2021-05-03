#include<stdio.h>
#include<math.h>
int main()
{
int points[5][2]={{5,10},{10,20},{10,5},{20,25},{20,5}};
int size=5;
int firstPoint,secondPoint,e,f;
float smallest,d;
smallest=sqrt(pow((points[1][0]-points[0][0]),2)+pow((points[1][1],points[0][1]),2));
for(e=0;e<size-1;e++)
{
for(f=e+1;f<size;f++)
{
d=sqrt(pow((points[e][0]-points[f][0]),2)+pow((points[e][1]-points[f][1]),2));
if(d<smallest)
{
smallest=d;
firstPoint=e;
secondPoint=f;
//printf("%f\n",d);
//printf("%d\n",e);
//printf("%d\n",f);
}
}
}

printf("Closest pair is (%d,%d) ,(%d,%d)",points[firstPoint][0],points[firstPoint][1],points[secondPoint][0],points[secondPoint][1]);
return 0;
}