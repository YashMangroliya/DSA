class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> *v=new vector<int>;
        v->push_back(1);
        if(rowIndex==0) return *v;
        v=new vector<int>;
        v->push_back(1);
        v->push_back(1);
        if(rowIndex==1) return *v;
        int i=2,j,sz;
        vector<int> *v1;
        while(i<=rowIndex)
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
        }
        return *v1;
    }
};