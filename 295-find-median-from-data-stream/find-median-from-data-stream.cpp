class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    double median;
    MedianFinder() {
        median = 0;
    }

    void calculateMedian(){
        if(left.size()==right.size()){
            median = (left.top()+right.top())/2.0;
        }
        else if(left.size()>right.size()){
            median = left.top();
        }
        else{
            median = right.top();
        }
    }
    
    void addNum(int num) {
        if(left.size() == right.size()){
            if(num<median){
                left.push(num);
            }
            else{
                right.push(num);
            }
        }
        else if(left.size() == right.size()+1){
            if(num>median){
                right.push(num);
            }
            else{
                int leftTop = left.top();
                left.pop();
                left.push(num);
                right.push(leftTop);
            }
            
        }
        else if(left.size()+1==right.size()){
            if(num<median){
                left.push(num);
            }
            else{
                int rightTop = right.top();
                right.pop();
                right.push(num);
                left.push(rightTop);
            }
        }

        calculateMedian();
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */