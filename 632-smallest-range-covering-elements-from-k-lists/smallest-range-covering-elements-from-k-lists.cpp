
class Info{
public:
    int data;
    int globalIndex;
    int localIndex;

    Info(int a,int b, int c){
        data=a;
        globalIndex=b;
        localIndex=c;
    }
};
class Compare{
public:
    bool operator()(Info* f, Info* s){
        return f->data > s->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*, vector<Info*>, Compare> pq;
        int maxi = INT_MIN;
        for(int i=0;i<nums.size();i++){
            int data = nums[i][0];
            int globalIndex = i;
            int localIndex = 0;
            maxi = max(maxi, data);
            Info* temp = new Info(data, globalIndex, localIndex);
            pq.push(temp);
        }
        vector<int> ans(2);
        int diff = INT_MAX;
        while(!pq.empty()){
            Info* top = pq.top();
            pq.pop();

            int data = top->data;
            int globalIndex = top->globalIndex;
            int localIndex = top->localIndex;
            
            if(maxi - data < diff){
                ans[0]=data;
                ans[1]=maxi;

                diff = maxi - data;
            }
            if(localIndex < nums[globalIndex].size()-1){
                Info* temp = new Info(nums[globalIndex][localIndex+1], globalIndex,localIndex+1);
                pq.push(temp);
                maxi = max(maxi, nums[globalIndex][localIndex+1]);
            }else{
                break;
            }
            delete top;

        }
        return ans;
    }
};