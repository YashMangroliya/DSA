class MyCircularQueue {
private:
    vector<int>* que;
    int front,rear,size,k;
public:
    MyCircularQueue(int k) {
        cout<<k<<endl;
        que=new vector<int>(k);
        front=0;
        rear=0;
        size=0;
        this->k=k;
    }
    
    bool enQueue(int value) {
        // cout<<"enque"<<endl;
        if(size==k) return false;
        if(size==0)
        {
            front=0;
            rear=0;
            size=1;
            (*que)[rear]=value;
            return true;
        }
        rear++;
        if(rear==k) rear=0;
        (*que)[rear]=value;
        size++;
        return true;
        
    }
    
    bool deQueue() {
        // cout<<"deque"<<endl;
        if(size==0) return false;
        front++;
        if(front==k) front=0;
        size--;
        return true;
    }
    
    int Front() {
        // cout<<"front"<<endl;
        if(size==0) return -1;
        int val=(*que)[front];
        return val;
    }
    
    int Rear() {
        // cout<<"rear"<<endl;
        if(size==0) return -1;
        int val=(*que)[rear];
        return val;
    }
    
    bool isEmpty() {
        // cout<<"isEmpty"<<endl;
        return size==0;
    }
    
    bool isFull() {
        // cout<<"isFull"<<endl;
        return size==k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */