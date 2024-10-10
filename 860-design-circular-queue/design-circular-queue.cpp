class MyCircularQueue {
public:
    int size;
    int* arr;
    int front;
    int rear;

    MyCircularQueue(int k) {
        size=k;
        arr=new int[size];
        front=-1;
        rear=-1;
        
    }
    
    bool enQueue(int value) {
        if(this->isFull()){
            return false;
        }
        else if(rear==-1){
            front++;
            rear++;
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
    
    bool deQueue() {
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
    
    int Front() {
        if(front==-1){
            return -1;
        }
        return arr[front];
        
    }
    
    int Rear() {
        if(rear==-1){
            return -1;
        }
        return arr[rear];
        
    }
    
    bool isEmpty() {
        if(front==-1){
            return true;
        }
        return false;
        
    }
    
    bool isFull() {
        if((rear==size-1 && front==0) || rear+1==front){
            return true;
        }
        return false;
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