/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool checkPalindrome(string s){
        int i=0;
        int j=s.length()-1;

        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
            return true;
        }
        string str="";
        ListNode* temp=head;
        while(temp){
            str.push_back(temp->val+'0');
            temp=temp->next;
        }
        return checkPalindrome(str);

        
    }
};