class Solution {
public:
    string defangIPaddr(string address) {
        for(int i=0;address[i]!='\0';i++){
            if(address[i]=='.'){
                address.insert(i,1,'[');
                i+=2;
                address.insert(i,1,']');

            }
        }
        return address;
        
    }
};