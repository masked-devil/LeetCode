class Solution {
public:
    void add(string& num1, int p1, string& num2, int p2, int carry, string& ans){
        if(p1<0 && p2<0){
            if(carry!=0){
                ans.push_back(carry+'0');
            }
            return;
        }

        int n1 = (p1>=0 ? num1[p1]:'0')-'0';
        int n2 = (p2>=0 ? num2[p2]:'0')-'0';
        int sum = n1+n2+carry;
        int digit = sum%10;
        carry = sum/10;
        add(num1, p1-1, num2, p2-1, carry, ans);
        ans.push_back(digit+'0');

        
    }
    string addStrings(string num1, string num2) {
        string ans = "";
        add(num1,num1.length()-1,num2, num2.length()-1,0,ans);

        //reverse(ans.begin(),ans.end());

        return ans;

        
    }
};