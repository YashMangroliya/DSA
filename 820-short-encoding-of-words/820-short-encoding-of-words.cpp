class Solution {
public:
    // Compare function for the condition of the sorting i.e. according to decreasing length 
    static bool compare (string& first, string& second) {
        return first.size() > second.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
//         sort(words.begin(),words.end(),[](string &e1,string &e2){ return e1.length()<e2.length(); });
//         string s="";
//         bool flag=false;
//         for(int i=words.size()-1;i>=0;i--)
//         {
//             flag=false;
//             string word=words[i]+"#";
//             int index=s.find(word);
//             // cout<<"Index value: "<<index<<endl;
//             // cout<<s<<endl;
//             while(index!=-1)
//             {
//                 if(s[index+word.length()]=='#')
//                 {
//                     flag=true;
//                     break;
//                 }
//                 index=s.find(word,index+1);
//             }
//             if(flag) continue;
//             s+=(word+"#");
//         }
//         return s.length();
        
        
        // More optimizewd
    
        unordered_map<string, int> mp;
        int ans = 0;
        
        //sorting the array in decreasing length sequence
        sort(words.begin(), words.end(), compare);

        //Entering each word in hash map.
        for(int i=0; i<words.size(); i++){
            mp[words[i]]++;
        }
        
        //For each word if it exist in hash map then add its length+1 to ans as # is also included.
        for(int i=0; i<words.size(); i++){
            int k = words[i].size();
            if(mp[words[i]] >0){
                ans += (k+1);
            }
            
            //Deleting record of any suffix of the word from hash map as it is already covered.
            for(int j=k-1; j>=0; j--){
                string s = words[i].substr(j, k-j);
                mp[s] = 0;
            }
        }
        return ans;
    }
};