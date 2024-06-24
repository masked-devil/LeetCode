class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());

        int i=0;
        int carry=0;
        string ans="";
        while(i<num1.length() && i<num2.length()){
            int sum=(num1[i]-'0')+(num2[i]-'0')+carry;
            if(sum>=10){
                ans.push_back(sum%10+'0');
                carry=1;
            }
            else{
                ans.push_back(sum+'0');
                carry=0;
            }
            i++;
        }
        int index=i;
        while(index<num1.length()){
            int sum=(num1[index]-'0')+carry;
            ans.push_back(sum%10+'0');
            if(sum<10){
                carry=0;
            }
            index++;

        }
        while(i<num2.length()){
            int sum=(num2[i]-'0')+carry;
            ans.push_back(sum%10+'0');
            if(sum<10){
                carry=0;
            }
            i++;

        }
        if(carry==1){
            ans.push_back('1');
        }
        reverse(ans.begin(),ans.end());

        return ans;

        
    }
};