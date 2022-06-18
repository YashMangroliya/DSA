class WordFilter {
public:
    
    // TLE
    
//     vector<unordered_map<string,int>> * words;
//     WordFilter(vector<string>& words) {
//         this->words=new vector<unordered_map<string,int>>(26,unordered_map<string,int>());
//         int index=0;
//         for(string word : words)
//         {
//             // (this->words)->at(word[0]-'a').insert({word,index});
//             (this->words)->at(word[0]-'a')[word]=index;
//             index++;
//         }
//     }
    
//     int f(string prefix, string suffix) {
//         unordered_map<string,int> list;
//         list=(this->words)->at(prefix[0]-'a');
//         int index=-1;
        
//         for(auto entry : list)
//         {
//             if(entry.first.substr(0,prefix.length()).compare(prefix)==0 &&
//               entry.first.substr(entry.first.length()-suffix.length()).compare(suffix)==0)
//             {
//                 index=max(index,entry.second);
//             }
//         }
//         return index;
//     }
    
    
    unordered_map<string, int> mp; //stores preffix and suffix sequence in it
    
    WordFilter(vector<string>& words) 
    {
        int n = words.size();
        
        for(int i=0; i<n; i++) //cover each word in words
        {
            string word = words[i]; 
            int wordsize = word.size();
            
            //storing all possible sequence of prefix and suffix of a word in the hashmap
            for(int j=1; j<=wordsize; j++) //for preffix 
            {
                string pre = word.substr(0,j);
                
                for(int k=0; k<wordsize; k++) //for suffix
                {
                    string suff = word.substr(k, wordsize);
                    mp[pre + "|" + suff] = i+1; //set index i+1 for all possible sequence of a word
                    //we set i+1 to handle i=0 because by-default map initialized with 0 
                }
            }
        }
    }
    
    int f(string prefix, string suffix) 
    {
        string s = prefix + "|" + suffix;
        return mp[s]-1; //if sequence found in hashmap we return its index
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */