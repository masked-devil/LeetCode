class Solution {
public:
    int stringToMin(string s){
        int hours=(s[0]-'0')*10+(s[1]-'0');
        int minutes=(s[3]-'0')*10+(s[4]-'0');

        return 60*hours+minutes;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        int n=timePoints.size();
        for(int i=0;i<n;i++){
            minutes.push_back(stringToMin(timePoints[i]));
        }
        sort(minutes.begin(),minutes.end());
        int i=1;
        int j=2;
        int ans=minutes[1]-minutes[0];
        while(j<minutes.size()){
            ans=min(ans,minutes[j]-minutes[i]);
            i++;
            j++;
        }
        int totalMinutes=24*60;
        ans=min(ans,totalMinutes-(minutes[n-1]-minutes[0]));

        return ans;

        
    }
};