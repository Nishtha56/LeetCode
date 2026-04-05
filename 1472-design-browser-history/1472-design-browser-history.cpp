class BrowserHistory {
public:
    string curr;
    stack<string> backward;
    stack<string> forwardS; 
    BrowserHistory(string homepage) {
        curr=homepage;
        backward.push(curr);

    }
    
    void visit(string url) {
        curr=url;
        backward.push(curr);

        while(!forwardS.empty()){
            forwardS.pop();
        }
    }
    
    string back(int steps) {
        while(steps > 0 && backward.size() > 1) {
            string a=backward.top();
            forwardS.push(a);
            backward.pop();
            steps--;
        }
        curr=backward.top();
        return curr;
      
    }
    
    string forward(int steps) {
        while(steps > 0 && forwardS.size() > 0) {
            string a =forwardS.top();
            backward.push(a);
            forwardS.pop();
            steps--;
        }
        curr=backward.top();
        return curr;
            
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */