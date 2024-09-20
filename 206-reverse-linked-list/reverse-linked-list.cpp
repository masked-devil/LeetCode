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
    ListNode* reverseLL(ListNode* prev, ListNode* curr){
        if(curr==NULL){
            return prev;
        }

        ListNode* nextNode=curr->next;

        curr->next=prev;
        return reverseLL(curr,nextNode);
        
    }
    ListNode* reverseList(ListNode* head) {
        // ListNode* prev=NULL;


        return reverseLL(NULL,head);
        
    }
};