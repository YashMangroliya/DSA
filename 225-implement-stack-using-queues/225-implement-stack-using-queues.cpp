class MyStack {
    queue<int> q;
    int peek;
public:
    MyStack() {
        peek=-1;
    }
    
    void push(int x) {
        q.push(x);
        peek=x;
    }
    
    int pop() {
        int n=q.size();
        n--;
        while(n>0)
        {
            peek = q.front();
            q.push(peek);
            q.pop();
            n--;
        }
        int num=q.front();
        q.pop();
        return num;
    }
    
    int top() {
        return peek;
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */