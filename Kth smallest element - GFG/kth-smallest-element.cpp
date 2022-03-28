// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        int size=r+1;
        int ci,ri,lci,rci,swi;
        // code to create min heap
        for(int i=1;i<size;i++)
        {
            ci=i;
            ri=(ci-1)/2;
            while( ri>=0 && arr[ci]<arr[ri] )
            {
                swap(arr[ci],arr[ri]);
                ci=ri;
                ri=(ci-1)/2;
            }
        }
        int i=1;
        int ub=size-1;
        while(i<k)
        {
            swap(arr[0],arr[ub]);
            ub--;
            //code to adjust heap
            ri=0;
            while(1)
            {
                lci=ri*2+1;
                rci=lci+1;
                if(lci>ub)
                {
                    break;
                }
                if(rci>ub) swi=lci;
                else if(arr[lci]<arr[rci]) swi=lci;
                else swi=rci;
                
                if(arr[swi]<arr[ri])
                {
                    swap(arr[swi],arr[ri]);
                    ri=swi;
                }
                else break;
            }
            i++;
        }
        return arr[0];
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends