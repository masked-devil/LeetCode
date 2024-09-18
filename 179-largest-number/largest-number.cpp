class Solution {
public:
    static bool comp(string s1, string s2){
        return (s1+s2)>(s2+s1);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> numbers;

        for(int x: nums){
            string str=to_string(x);
            numbers.push_back(str);
        }
        
        sort(numbers.begin(),numbers.end(),comp);
        string ans;

        for(string s:numbers){
            
            ans.append(s);

        }
        if(ans[0]=='0'){
            return "0";
        }
        return ans;
        
    }
};