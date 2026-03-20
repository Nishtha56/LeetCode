class MedianFinder {
public:
    priority_queue<int> Maxpq;  //maxx heap
    priority_queue<int, vector<int>, greater<int>> Minpq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        Maxpq.push(num);
        Minpq.push(Maxpq.top());
        Maxpq.pop();
        if(Minpq.size() > Maxpq.size()){
            Maxpq.push(Minpq.top());
            Minpq.pop();
        }
    
    }
    
    double findMedian() {
        double m=0;
        if(Minpq.size()<Maxpq.size()){
            m=Maxpq.top();
        }
        else{
            m=((double)Minpq.top() + (double)Maxpq.top())/2.0;
        }
        return m;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */