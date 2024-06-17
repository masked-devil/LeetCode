class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<bool> appearance(27,false);
        vector<char> mapping;

        for(int i=0;i<key.length();i++){
            int alphabet = key[i]-'a';
            if(key[i]==' '){
                continue;
            }
            if(appearance[alphabet]!=true){
                appearance[alphabet]=true;
                mapping.push_back(key[i]);
            }
        }
        for(int i=0;i<message.length();i++){
            int alphabet = message[i];
            if(message[i]==' '){
                continue;
            }
            else{
                int index=find(mapping.begin(),mapping.end(),alphabet)-mapping.begin();
                message[i]= index+'a';
            }
        }
        return message;

    }
};