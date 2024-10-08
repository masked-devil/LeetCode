class Solution {
public:
    void prevSmaller(vector<int>& heights, vector<int>& prev){
        stack<int> st;
        int n=prev.size();
        st.push(-1);

        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            prev[i]=st.top();
            st.push(i);
        }
    }
    void nextSmaller(vector<int>& heights, vector<int>& next){
        stack<int> st;
        int n=next.size();
        st.push(-1);

        for(int i=n-1;i>=0;i--){
            while(st.top()!=-1 && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.top()==-1){
                next[i]=n;
            }
            else{
                next[i]=st.top();
            }        
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();

        vector<int> prev(n);
        vector<int> next(n);
        int area=0;

        prevSmaller(heights,prev);
        nextSmaller(heights,next);

        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            area=max(area,width*heights[i]);
        }

        return area;
        
    }
};