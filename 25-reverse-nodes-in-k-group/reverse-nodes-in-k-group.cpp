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
    int findLength(ListNode* &head){
        ListNode* temp=head;
        int len=0;
        while(temp){
            len++;
            temp=temp->next;
        }
        return len;
    }
    ListNode* answer(ListNode* head, int k, int length){
        if(k>length || head==NULL){
            return head;
        }
        ListNode* groupHead=head;
        ListNode* prevNode=NULL;
        ListNode* currNode=head;
        

        int i=0;
        while(i<k && currNode){
            ListNode* nextNode=currNode->next;
            currNode->next=prevNode;
            prevNode=currNode;
            currNode=nextNode;
            i++;
        }
        groupHead->next=answer(currNode,k,length-k);
        return prevNode;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len=findLength(head);
        ListNode* newHead=answer(head,k,len);

        return newHead;


        
        
    }
};