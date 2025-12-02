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
class Compare {
public:
	bool operator()(ListNode* a, ListNode* b) {
		if(a->val > b->val) {
			return true;
		}
		return false;
	}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=NULL;
        ListNode* temp = NULL;
        ListNode* current = NULL;
        priority_queue<ListNode*,vector<ListNode*>,Compare> minHeap;

        for(auto x:lists){
            if(x) minHeap.push(x);
        }

        while(!minHeap.empty()){
            ListNode* front = minHeap.top();
            minHeap.pop();
            if(front->next){
                minHeap.push(front->next);
            }

            temp = new ListNode(front->val);
            if(!head){
                head = temp;
            }
            if(current){
                current->next = temp;
            }
            current=temp;
        }

        return head;
    }
};