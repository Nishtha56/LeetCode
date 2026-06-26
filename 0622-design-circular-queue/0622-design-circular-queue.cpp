class MyCircularQueue {
public:
    int f, r, sz, cap;
    vector<int> v;
    MyCircularQueue(int k) {
        v.resize(k);
        f=0;
        r=0;
        sz=0;
        cap=k;
    }
    
    bool enQueue(int value) {
        if(sz==cap){
            return false;
        }
        v[r]=value;
        sz++;
        r++;
        r=r%cap;
        return true;
    }
    
    bool deQueue() {
        if(sz==0) return false;
        f++;
        sz--;
        f=f%cap;
        return true;
        
    }
    
    int Front() {
        if(sz==0) return -1;

        return v[f];
    }
    
    int Rear() {
        if(sz==0) return -1;
        if(r==0) return v[cap-1];
        return v[r-1];
    }
    
    bool isEmpty() {
        return sz==0;
    }
    
    bool isFull() {
        return sz==cap;
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