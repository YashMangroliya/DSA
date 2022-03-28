// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long x[],long lb1,long ub1,long lb2,long ub2,long long tmp[])
    {
        int size1=ub1-lb1+1;
        int size2=ub2-lb2+1;
        int size=size1+size2;
        int i1,i2,i3;
        i1=lb1;
        i2=lb2;
        i3=lb1;
        long long int invCount=0;
        while(i1<=ub1 && i2<=ub2)
        {
            if(x[i1]<=x[i2])
            {
                tmp[i3]=x[i1];
                i1++;
            }
            else
            {
                tmp[i3]=x[i2];
                i2++;
                invCount=invCount+(ub1-i1)+1;
            }
            i3++;
        }
        while(i1<=ub1)
        {
            tmp[i3]=x[i1];
            i3++;
            i1++;
        }
        while(i2<=ub2)
        {
            tmp[i3]=x[i2];
            i3++;
            i2++;
        }
        i3=lb1;
        i1=lb1;
        while(i1<=ub1)
        {
            x[i1]=tmp[i3];
            i3++;
            i1++;
        }
        i2=lb2;
        while(i2<=ub2)
        {
            x[i2]=tmp[i3];
            i3++;
            i2++;
        }    
        return invCount;
    }
    long long int mergeSort(long long x[],long lb,long ub,long long tmp[])
    {
        int mid;
        long long int count=0;
        if(lb<ub)
        {
            mid=(ub+lb)/2;
            count+=mergeSort(x,lb,mid,tmp);
            count+=mergeSort(x,mid+1,ub,tmp);
            count+=merge(x,lb,mid,mid+1,ub,tmp);
        }
        return count;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        long long tmp[N];
        long long int count=mergeSort(arr,0,N-1,tmp);
        return count;
        // return invCo
    }
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends