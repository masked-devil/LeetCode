class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for(int x:piles){
            sum+=x;
            pq.push(x);
        }

        while(k){
            int top = pq.top();
            pq.pop();

            sum-=top/2;
            pq.push(top-(top/2));
            k--;
        }

        return sum;
    }
};