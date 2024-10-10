class MyCircularDeque {
public:
    int size;
    int* arr;
    int front;
    int rear;
    MyCircularDeque(int k) {
        size=k;
        arr=new int[size];
        front=-1;
        rear=-1;
        
    }
    
    bool insertFront(int value) {
        if(this->isFull()){
            return false;
        }
        else if(front==-1){
            front++;
            rear++;
            arr[front]=value;

        }
        else if(front==0){
            front=size-1;
            arr[front]=value;
        }
        else{
            front--;
            arr[front]=value;
        }
        return true;
        
    }
    
    bool insertLast(int value) {
        if(this->isFull()){
            return false;
        }
        else if (rear==-1){
            rear++;
            front++;
            arr[rear]=value;
        }
        else if(rear==size-1){
            rear=0;
            arr[rear]=value;
        }
        else{
            rear++;
            arr[rear]=value;
        }
        return true;
        
    }
    
    bool deleteFront() {
        if(front==-1){
            return false;
        }
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        else{
            arr[front]=-1;
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        if(rear==-1){
            return false;
        }
        else if(front==rear){
            arr[rear]=-1;
            front=-1;
            rear=-1;
        }
        else if(rear==0){
            arr[rear]=-1;
            rear=size-1;
        }
        else{
            arr[rear]=-1;
            rear--;
        }
        return true;
        
    }
    
    int getFront() {
        if(front==-1){
            return -1;
        }
        return arr[front];
        
    }
    
    int getRear() {
        if(rear==-1){
            return -1;
        }
        return arr[rear];
        
    }
    
    bool isEmpty() {
        if(front==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if((front==0 && rear==size-1) || rear+1==front){
            return true;
        }
        return false;
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */