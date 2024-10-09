class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!st2.empty()){
            int k=st2.top();
            st1.push(k);
            st2.pop();
        }
        st1.push(x);
        
    }
    
    int pop() {
        while(!st1.empty()){
            int k=st1.top();
            st2.push(k);
            st1.pop();
        }
        int x=st2.top();
        st2.pop();
        return x;
        
    }
    
    int peek() {
        while(!st1.empty()){
            int k=st1.top();
            st2.push(k);
            st1.pop();
        }
        int x=st2.top();
        return x;
        
    }
    
    bool empty() {
        if(st1.empty() && st2.empty()){
            return true;
        }
        return false;
        
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */