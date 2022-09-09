class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int count=0;
        sort(properties.begin(),properties.end(),[](vector<int>& v1,vector<int>& v2){
            if(v1[0]!=v2[0]) return v1[0]<v2[0];
            return v1[1]>v2[1];
        });
        // int last=properties[properties.size()-1][0];
        int maxTillNow=properties[properties.size()-1][1];
        for(int i=properties.size()-2;i>=0;i--)
        {
            if(properties[i][1]<maxTillNow) count++;
            else maxTillNow=properties[i][1];
        }
        return count;
    }
};