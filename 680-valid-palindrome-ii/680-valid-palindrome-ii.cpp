class Solution {
public:
    
    bool checkPallindrome(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            if(s[i]!=s[j])
            {
                return (checkPallindrome(s,i+1,j) || checkPallindrome(s,i,j-1));
            }
        }
        return true;
    }

    
//     bool checkPallindrome(string s, int index)
//     {
//         string str="";
//         int i,j;
//         for(i=0;i<s.length();i++)
//         {
//             if(i!=index)
//             {
//                 str+=s[i];
//             }
//         }
//         for(i=0,j=str.length()-1;i<j;i++,j--)
//         {
//             if(str[i]!=str[j]) break;
//         }
//         return i>=j;
//     }
    
//     bool validPalindrome(string s) {
//         bool ans=true;
//         bool flag=false;
//         for(int i=0,j=s.length()-1;i<j;i++,j--)
//         {
//             if(s[i]!=s[j])
//             {
//                 return (checkPallindrome(s,i) || checkPallindrome(s,j));
//             }
//         }
//         return true;
//     }
};