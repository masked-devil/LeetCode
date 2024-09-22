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
    bool isPalindrome(ListNode* head) {
        ListNode* temp=head;

        ListNode* head2=new ListNode(temp->val);
        temp=temp->next;

        while(temp!=NULL){

            ListNode* newNode=new ListNode(temp->val);
            newNode->next=head2;
            head2=newNode;
            temp=temp->next;
        }
        temp=head;
        ListNode* temp2=head2;

        while(temp!=NULL){
            if(temp->val!=temp2->val){
                return false;
            }
            temp=temp->next;
            temp2=temp2->next;
        }
        return true;

        

        
    }
};