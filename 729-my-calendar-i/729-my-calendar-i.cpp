class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(pair<int,int> p : vec)
        {
            if(start>=p.first && start<p.second) return false;
            if(end>p.first && end<=p.second) return false;
            
            if(p.first>=start && p.first<end) return false;
            if(p.second>start && p.second<=end) return false;
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