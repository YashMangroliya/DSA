class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](const vector<int> & v1, const vector<int> &v2){
            if(v1[0]!=v2[0]) return v1[0]>v2[0];
            else return v1[1]<v2[1];
        });
        for(vector<int> &v : people) cout<<v[0]<<","<<v[1]<<endl;
        vector<vector<int>> ans;
        for(vector<int> & v : people)
        {
            ans.insert(ans.begin()+v[1],v);
        }
        return ans;
    }
};