class Solution {
public:
    string removeOccurrences(string s, string part) {
        int i=0;

        while(i<s.length()){
            if(s[i]==part[0]){
                if((s.substr(i,part.length()).compare(part))!=0){
                    i++;
                }
                else{
                    s.erase(i,part.length());
                    i=i-part.length()+1;
                    if(i<0){
                        i=0;
                    }
                }
            }
            else{
                i++;
            }

        }
        return s;
    }
};