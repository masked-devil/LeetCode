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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* prevNode=NULL;
        ListNode* currNode=head;
        ListNode* nextNode=head->next;

        while(currNode!=NULL){
            currNode->next=prevNode;

            prevNode=currNode;
            currNode=nextNode;
            if(nextNode!=NULL){
                nextNode=nextNode->next;
            }
            
        }
        head=prevNode;

        return head;
        
    }
};