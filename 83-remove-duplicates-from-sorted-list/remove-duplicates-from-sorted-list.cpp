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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* currNode=head;
        while(currNode->next!=NULL){
            ListNode* nextNode=currNode->next;

            if(currNode->val==nextNode->val){
                currNode->next=nextNode->next;
                nextNode->next=NULL;

                delete nextNode;
                nextNode=NULL;

            }
            else{
                currNode=currNode->next;
            }
        }
        return head;

        
    }
};