class Solution {
public:

    string customSortString(string order, string s) {
        vector<int> priority(26,-1);
        
        int charPriority=0;
        int character;


        for(int i=0;i<order.length();i++){
            character=order[i]-'a';
            priority[character]=charPriority++;
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = 0; j <= i - 1; j++) {
                int char1=s[j]-'a';
                int char2=s[j+1]-'a';
                if (priority[char1] > priority[char2]) {
                    char temp = s[j + 1];
                    s[j + 1] = s[j];
                    s[j] = temp;
                }
            }
        }

        return s;
        
    }
};