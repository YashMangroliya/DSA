class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int> p,pp;
        bool flag=false;
        for(int i=0;i<vec.size();i++)
        {
            p=vec[i];
            if(start>=p.first && start<p.second  ||  end>p.first && end<=p.second  ||  p.first>=start && p.first<end || p.second>start && p.second<=end)
            {
                return false;
            }
            if(p.second==start)
            {
                pp=p;
                flag=true;
            }
        }
        if(flag)
        {
            remove(vec.begin(),vec.end(),pp);
            vec.push_back(make_pair(pp.first,end));
        }
        else vec.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */