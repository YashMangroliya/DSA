class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int,int> p;
        for(int i=0;i<vec.size();i++)
        {
            p=vec[i];
            if(start>=p.first && start<p.second  ||  end>p.first && end<=p.second  ||  p.first>=start && p.first<end || p.second>start && p.second<=end)
            {
                return false;
            }
            // if(p.second==start)
            // {
            //     vec.erase(vec.begin()+i);
            //     vec.insert(vec.begin(),make_pair(p.first,end));
            // }
            
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