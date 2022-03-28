class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size=strs.size();
        if(size==0) return "";
        else if(size==1) return strs[0];
        string smallest=strs[0];
        string str;
        int sz=smallest.size();
        if(sz==0) return "";
        for(auto str:strs)
        {
            if(str.size()<sz) smallest=str;
        }
        sz=smallest.size();
        bool flag=true;
        while(sz>0 && flag)
        {
            flag=false;
            for(auto str:strs)
            {
                if(str.find(smallest)!=0) 
                {
                    sz--;
                    flag=true;
                    smallest.resize(sz);
                    break;
                }
            }
        }
        return smallest;
    }
};