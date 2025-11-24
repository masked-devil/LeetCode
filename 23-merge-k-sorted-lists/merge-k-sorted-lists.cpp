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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* temp;
        priority_queue<int,vector<int>,greater<int>> minHeap;

        for(int i=0;i< lists.size();i++){
            while(lists[i]!=NULL){
                minHeap.push(lists[i]->val);
                lists[i]=lists[i]->next;
            }
        }

        if(!minHeap.empty()){
            int x = minHeap.top();
            minHeap.pop();
            head = new ListNode(x);
            temp = head;
        }

        while(!minHeap.empty()){
            int x = minHeap.top();
            minHeap.pop();
            temp->next = new ListNode(x);
            temp = temp->next;
        }

        return head;
    }
};