class TimeMap {
private:
    map<pair<string,int>,string> map1;
    vector<int> timestamps;
    bool sorted=true;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        pair<string,int> p=make_pair(key,timestamp);
        map1[p]=value;
        // int index = upper_bound(timestamps.begin(),timestamps.end(),timestamp)-timestamps.begin();
        timestamps.insert(upper_bound(timestamps.begin(),timestamps.end(),timestamp),timestamp);
        sorted=false;
    }
    
    string get(string key, int timestamp) {
        if(map1.find(make_pair(key,timestamp))!=map1.end()) return map1[make_pair(key,timestamp)];
        // if(!sorted){
        //     sort(timestamps.begin(),timestamps.end());
        //     sorted=true;
        // }
        int index=upper_bound(timestamps.begin(),timestamps.end(),timestamp)-timestamps.begin()-1;
        //cout<<"key: "<<key<<", timestamp"<<timestamp<<", index:"<<index<<endl;
        while(index>=0)
        {
            if(map1.find(make_pair(key,timestamps[index]))!=map1.end())
            {
                return map1[make_pair(key,timestamps[index])];
            }
            index--;
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */