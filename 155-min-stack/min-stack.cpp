class Node{
    public:
    int data;
    int mini;
    Node(int data,int mini){
        this->data=data;
        this->mini=mini;
    }
};
class MinStack {
public:
    vector<Node> st;
    int topValue;


    MinStack() {
        topValue=-1;
        
    }
    
    void push(int val) {
        topValue++;
        if(topValue==0){
            Node newNode(val, val);
            st.push_back(newNode);
        }
        else{
            Node newNode(val, min(st[topValue-1].mini,val));
            st.push_back(newNode);

        }
        
    }
    
    void pop() {
        if(topValue!=-1){
            st.pop_back();
            topValue--;
        }
        
        
    }
    
    int top() {
        if(topValue!=-1){
            return st[topValue].data;
        }
        return -1;
    }
    
    int getMin() {
        if(topValue!=-1){
            return st[topValue].mini;
        }
        return -1;
        
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