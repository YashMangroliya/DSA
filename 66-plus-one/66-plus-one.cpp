class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int d,carry;
        vector<int>::iterator itr=digits.end()-1;
        vector<int>::iterator begin=digits.begin();
        if(*itr!=9)
        {
            d=(digits.back())+1;
            digits.pop_back();
            digits.push_back(d);
        }
        else
        {
            while(itr>begin && *itr==9)
            {
                digits.erase(itr);
                digits.insert(itr,0);
                itr--;
            }
            d=*itr;
            digits.erase(itr);
            if(d!=9)
            {
                digits.insert(itr,d+1);
            }
            else
            {
                digits.insert(itr,0);
                digits.insert(itr,1);
            }
        }
        return digits;    
    }
};