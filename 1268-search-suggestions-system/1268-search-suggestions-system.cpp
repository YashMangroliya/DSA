class Solution {
public:
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        unordered_map<string,vector<string>> map1;
        sort(products.begin(),products.end());
        string ss="";
        for(string &product : products)
        {
            ss="";
            for(int i=0;i<product.length();i++)
            {
                ss+=product[i];
                if(map1[ss].size()<3) map1[ss].push_back(product);
            }
        }
        
        vector<vector<string>> ans;
        ss="";
        for(int i=0;i<searchWord.length();i++)
        {
            ss+=searchWord[i];
            ans.push_back(map1[ss]);
        }
        
        return ans;
    }
};