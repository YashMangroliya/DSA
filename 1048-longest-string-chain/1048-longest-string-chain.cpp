class Solution {
public:
    
    // Less Optimized
    
//     int dp[1000];
//     int solve(vector<string> &words,int index)
//     {
//         if(dp[index]!=-1) return dp[index];
//         int ans=0;
//         string word=words[index];
//         vector<string>::iterator itr;
//         string newWord;
//         for(int i=0;i<word.length();i++)
//         {
//             newWord=word.substr(0,i)+word.substr(i+1);
//             itr=find(words.begin()+index,words.end(),newWord);
//             if(itr!=words.end())
//             {
//                 ans=max(ans, solve(words,itr-words.begin()));
//             }
//         }
//         dp[index]=ans+1;;
//         return ans+1;
//     }
    
//     int longestStrChain(vector<string>& words) {
//         sort(words.begin(),words.end(), [] (const string &s1, const string &s2)         { 
//             return s1.length()>s2.length();
//         });
        
//         memset(dp,-1,sizeof(dp));
//         //for(string i: words) cout<<i<<end;
//         int ans=1;
//         for(int i=0;i<words.size();i++)
//         {
//             ans=max(ans,solve(words,i));
//         }
//         return ans;
//     }
    
    
    int longestStrChain(vector<string>& words) {
         sort(words.begin(),words.end(), [] (const string &s1, const string &s2)                { 
              return s1.length()<s2.length();
         });
        
        int ans=0;
        string newWord;
        unordered_map<string,int> map1;
        for(string word : words)
        {
            int longest=0;
            for(int i=0;i<word.length();i++)
            {
                newWord=word.substr(0,i) + word.substr(i+1,word.length()+1);
                longest=max(longest,map1[newWord]+1);
            }
            map1[word]=longest;
            ans=max(ans,longest);
        }
        return ans;
     }
};