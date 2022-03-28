class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        if(numRows==0) return vec;
        vector<int> *v=new vector<int>;
        v->push_back(1);
        vec.push_back(*v);
        if(numRows==1) return vec;
        v=new vector<int>;
        v->push_back(1);
        v->push_back(1);
        vec.push_back(*v);
        if(numRows==2) return vec;
        int i=2,j,sz;
        vector<int> *v1;
        while(i<numRows)
        {
            v1=new vector<int>;
            (v1)->push_back(1);
            j=1;
            sz=v->size();
            while(j<sz)
            {
                v1->push_back((*v)[j]+(*v)[j-1]);
                j++;
            }
            v1->push_back(1);
            i++;
            v=v1;
            vec.push_back(*v);
        }
        return vec;
    }
};