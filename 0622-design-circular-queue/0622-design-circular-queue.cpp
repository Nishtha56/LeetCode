class MyCircularQueue {
    int front;
    int rear;
    int size;
    int* queue;

public:
    MyCircularQueue(int k) {
        front = rear = 0;
        size = k + 1;
        queue = new int[size];
    }
    
    bool enQueue(int value) {
        if (((rear + 1) % size) == front) return false;
        
        rear = (rear + 1) % size;
        queue[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if (rear == front) return false;
        
        front = (front + 1) % size;
        return true;       
    }
    
    int Front() {
        if (rear == front) return -1;
        
        return queue[(front + 1) % size];
    }
    
    int Rear() {
        if (rear == front) return -1;
        
        return queue[rear];

    }
    
    bool isEmpty() {
        return rear == front;
    }
    
    bool isFull() {
        return ((rear + 1) % size) == front;
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