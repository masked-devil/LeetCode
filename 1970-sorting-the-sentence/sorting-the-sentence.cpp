class Solution {
public:
    string sortSentence(string s) {
        int index=0;
        int start=0;
        string answer="";
        vector<string> v(10,"");
        while(index<s.length()){
            start=index;
            while(index<s.length() && s[index]!=' '){
                index++;
            }
            string str=s.substr(start,index-start);
            v[s[index-1]-'0']=str;

            index++;
        }

        for(string str:v){
            if(str!=""){answer+=(str.substr(0,str.length()-1));
            answer.push_back(' ');}
        }
        answer.pop_back();

        return answer;

        

    }
};