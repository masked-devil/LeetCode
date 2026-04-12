class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> flights(n+1,0);
        vector<int> ans(n,0);

        for(auto &booking:bookings){
            int start = booking[0];
            int end = booking[1];
            int seats = booking[2];

            flights[start-1]+=seats;
            flights[end]-=seats;
        }
        ans[0]=flights[0];
        for(int i=1;i<n;i++){
            ans[i] = ans[i-1]+flights[i];
        }
        return ans;
    }
};