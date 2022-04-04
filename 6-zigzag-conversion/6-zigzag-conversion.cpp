class Solution {
public:
    string convert(string s, int numRows) {
        int i=0,j=0,count=0;
        // while(count<s.length())
        // {
        //     for(i=0;i<numRows;i++)
        //     {
        //         count++;
        //     }
        //     for(i--,j++;i>=0;i--,j++)
        //     {
        //         count++;
        //     }
        //     j--;
        // }
        
        if(numRows==1) return s;
        string arr[numRows];
        string ans="";
        for(i=0;i<numRows;i++)
        {
            arr[i]="";
        }
        int index=0;
        bool flag=true;
        for(i=0;i<s.length();i++)
        {
            arr[index]+=s[i];
            if(flag) index++;
            else if(!flag) index--;
            if(index==numRows)
            {
                index=numRows-2;
                flag=false;
            }
            else if(index==-1)
            {
                index=1;
                flag=true;
            }
        }
        for(i=0;i<numRows;i++)
        {
            ans+=arr[i];
        }
        return ans;
    }
};