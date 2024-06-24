class Solution {
public:
    void solve(int num, int currValue,vector<string>& value, vector<string>& tens,vector<string>& units,vector<string>& ans){
        if(num<=0){
            return;
        }
        int lastThree=num%1000;
        int lastTwo=num%100;
        int last=num%10;

        if(lastThree!=0) ans.push_back(value[currValue]);

        if(lastTwo>=20){
            ans.push_back(units[last]);
            ans.push_back(tens[lastTwo/10]);
        }
        else{
            ans.push_back(units[lastTwo]);
        }
        if(lastThree>=100){ans.push_back("Hundred");}
        ans.push_back(units[lastThree/100]);
        

        solve(num/1000,currValue+1,value,tens,units,ans);

        return;
}
    string numberToWords(int num) {
        if(num==0){
            return "Zero";
        }
        vector<string> ans;
        string words="";
        vector<string> value={"","Thousand","Million","Billion"};
        vector<string> tens={"","","Twenty","Thirty","Forty","Fifty",
                            "Sixty","Seventy","Eighty","Ninety"
        };
        vector<string> units={"","One","Two","Three","Four","Five",
                            "Six","Seven","Eight","Nine",
                            "Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
                            "Sixteen","Seventeen","Eighteen","Nineteen"
        };
        //int digits=ceil(log10(num));
        solve(num,0,value,tens,units,ans);
        // char empty='';
        int i=ans.size()-1;
        while(i>=0){
            words.append(ans[i]);
            if(ans[i]!="")words.append(" ");
            i--;
        }
        int start=0;
        int end=words.length()-1;
        char ch=' ';

        while(words[start]==ch){
            start++;
        }
        while(words[end]==ch){
            end--;
        }

        return words.substr(start,end-start+1);
    }
};