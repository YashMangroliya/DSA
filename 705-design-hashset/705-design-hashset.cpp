class MyHashSet {
public:
    int hash=10;
    vector<vector<int>> vec;
    MyHashSet() {
        for(int i=0;i<hash;i++) vec.push_back(vector<int>());
    }
    
    void add(int key) {
        int i=key%hash;
        if(find(vec[i].begin(),vec[i].end(),key)==vec[i].end()) vec[i].push_back(key);
    }
    
    void remove(int key) {
        int i=key%hash;
        if(find(vec[i].begin(),vec[i].end(),key)!=vec[i].end()) vec[i].erase(find(vec[i].begin(),vec[i].end(),key));
    }
    
    bool contains(int key) {
        int i=key%hash;
        return find(vec[i].begin(),vec[i].end(),key)!=vec[i].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */