class MyStack {
public:
    int size;
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        size=0;
        
    }
    
    void push(int x) {
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        q1.push(x);
        size++;
    }
    
    int pop() {
        for(int i=1;i<size;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q1.pop();
        size--;
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
        
    }
    
    int top() {
        for(int i=1;i<size;i++){
            q2.push(q1.front());
            q1.pop();
        }
        int x=q1.front();
        q2.push(x);
        q1.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
        
    }
    
    bool empty() {
        if(size==0){
            return true;
        }
        return false;
        
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