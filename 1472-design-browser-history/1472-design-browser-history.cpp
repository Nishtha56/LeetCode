class BrowserHistory {
public:
    string curr;
    stack<string> backward;
    stack<string> forwardS; 
    BrowserHistory(string homepage) {
        curr=homepage;
        backward.push(curr);

    }
    // stack is used beacuse we track past data/historu doubly ll also can be used 
    void visit(string url) {
        curr=url;
        backward.push(curr);

        while(!forwardS.empty()){
            forwardS.pop();
        }
    }
    //We do not empty backward stack because we have to return always top element in case steps is higher than stack
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

    //We have to empty forward stack because from poping in forward we are storing in backward and in the end we retrurn top element in a backward stack
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