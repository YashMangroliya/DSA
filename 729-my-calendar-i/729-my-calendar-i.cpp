class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        bool flag=false;
        pair<int,int> pp;
        for(pair<int,int> p : vec)
        {
            if(start>=p.first && start<p.second  ||  end>p.first && end<=p.second  ||  p.first>=start && p.first<end || p.second>start && p.second<=end)
            {
                flag = true;
                pp=p;
                break;
            }
            
        }
        if(flag)
        {
            return false;
        }
        
        vec.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */