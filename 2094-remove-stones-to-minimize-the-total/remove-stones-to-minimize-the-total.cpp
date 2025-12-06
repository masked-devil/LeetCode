class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int> pq;

        for(auto x:piles){
            pq.push(x);
            sum+=x;
        }

        while(k){
            int front = pq.top();
            pq.pop();

            int newFront = front/2;
            sum-=newFront;
            pq.push(front - newFront);
            k--;
        }

        return sum;
    }
};