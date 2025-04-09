class Solution {
public:
    static bool comp(string s1, string s2){
        int n1=s1.length();
        int n2=s2.length();

        if(s1[n1-1]<s2[n2-1]){
            return true;
        }

        return false;
    }
    string sortSentence(string s) {
        int index=0;
        int start=0;
        string answer="";
        vector<string> v;
        while(index<s.length()){
            start=index;
            while(index<s.length() && s[index]!=' '){
                index++;
            }
            string str=s.substr(start,index-start);
            v.push_back(str);

            index++;
        }
        sort(v.begin(),v.end(),comp);

        for(string str:v){
            answer+=(str.substr(0,str.length()-1));
            answer.push_back(' ');
        }
        answer.pop_back();

        return answer;

        

    }
};