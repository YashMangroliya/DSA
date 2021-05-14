import java.util.*;
class pair
{
public static void main(String gg[])
{
int x[]={2,4,5,7,-1};
int num,rSum=6;
Set<Integer> set=new HashSet<>();
int count=0;
for(int e=0;e<5;e++)
{
num=x[e];
if(set.contains(rSum-num)) count++;
set.add(num);
}
System.out.println(count);
}
}