class MinStack {
public:
    vector<int> st;
    vector<int> st2;

    MinStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        if(!st2.empty()){
            int n=st2.size();

            if(val<=st2[n-1]){
                st2.push_back(val);
            }
        }
        else{
            st2.push_back(val);
        }
    }
    
    void pop() {
        int n=st.size();
        int m=st2.size();
        if(n<=0){
            return;
        }
        
        if(st[n-1]==st2[m-1]){
            st2.pop_back();
        }
      
          st.pop_back();
        
        
    }
    
    int top() {
        int n=st.size();
        return st[n-1];
        
    }
    
    int getMin() {
        int n=st2.size();
        return st2[n-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */