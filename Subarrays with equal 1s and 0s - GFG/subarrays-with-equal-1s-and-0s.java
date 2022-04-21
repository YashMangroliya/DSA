// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.lang.*;
import java.io.*;
class Driverclass
 {
	public static void main (String[] args) {
	   
	   Scanner in = new Scanner(System.in);
	   int t= in.nextInt();
	   while(t-->0){
	       
	       int n = in.nextInt();
	       int [] arr= new int[n];
	       for(int i=0;i<n;i++) {
	           arr[i] = in.nextInt();
	       }
	       System.out.println(new Solution().countSubarrWithEqualZeroAndOne(arr, n));
	   }
	 }
}

// } Driver Code Ends


//User function Template for Java

class Solution
{
    //Function to count subarrays with 1s and 0s.
    static int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        HashMap<Integer,Integer> map1=new HashMap<>();
        int num,sum=0,count=0;
        map1.put(0,1);
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) num=-1;
            else num=1;
            sum+=num;
            if(map1.containsKey(sum))
            {
                count+=map1.get(sum);
                map1.put(sum,map1.get(sum)+1);
            }
            else map1.put(sum,1);
        }
        return count;
    }
}


