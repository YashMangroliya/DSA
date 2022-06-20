class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(),words.end(),[](string e1,string e2){ return e1.length()<e2.length(); });
        string s="";
        bool flag=false;
        for(int i=words.size()-1;i>=0;i--)
        {
            flag=false;
            string word=words[i];
            int index=s.find(word);
            // cout<<"Index value: "<<index<<endl;
            // cout<<s<<endl;
            while(index!=-1)
            {
                if(s[index+word.length()]=='#')
                {
                    flag=true;
                    break;
                }
                index=s.find(word,index+1);
            }
            if(flag) continue;
            s+=(word+"#");
        }
        return s.length();
    }
};