class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        st.push(0);
        int n=prices.size();
        vector<int> answer(n);

        for(int i=n-1;i>=0;i--){
            int num=prices[i];
            if(st.top()<=num){
                answer[i]=prices[i]-st.top();
                st.push(num);
            }
            else{
                while(st.top()>num){
                    st.pop();
                }
                answer[i]=prices[i]-st.top();
                st.push(num);
            }
        }

        return answer;
        
    }
};