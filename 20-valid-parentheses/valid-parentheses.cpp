class Solution {
public:
    bool isValidMatch(char o, char c){
        if((o=='(' && c==')') || (o=='[' && c==']') || (o=='{' && c=='}')){
            return true;
        }
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char c=s[i];

            if(c=='(' || c=='[' || c=='{'){
                st.push(c);
            }
            else{
                if(st.empty() || !isValidMatch(st.top(),c)){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};