import java.util.*;
class frequency
{
private static HashMap<Integer,Integer> map;
public static void main(String gg[])
{
int x[]={0,1,1,2,0,0};
int e,num,z,y;
int n1,n2;
map=new HashMap<>();
for(e=0;e<x.length;e++)
{
n1=x[e];
if(map.containsKey(n1))
{
map.put(n1,map.get(n1)+1);
}
else map.put(n1,1);
}

// Insertion sort
y=1;
while(y<x.length)
{
z=y-1;
num=x[y];
while(z>=0 && fun(x[z],num))
{
x[z+1]=x[z];
z--;
}
x[z+1]=num;
y++;
}
for(e=0;e<x.length;e++) System.out.println(x[e]);
}
public static boolean fun(int x1,int x2)
{
if(map.get(x1)!=map.get(x2))
{
return map.get(x1)<map.get(x2);
}
return x2<x1;
}
}