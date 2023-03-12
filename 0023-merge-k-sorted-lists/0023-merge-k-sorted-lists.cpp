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
    struct myCompare {
        bool operator () (ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size())
            return NULL;
        if (lists.size() == 1)
            return lists[0];
        priority_queue <ListNode*, vector<ListNode*>, myCompare> pq;
        
        ListNode *dummy = new ListNode (0);
        ListNode *tail = dummy;
        for (auto it: lists) {
            if (it)
                pq.push(it);
        }
        
        while (!pq.empty()) {
            ListNode* curr = pq.top();  pq.pop();
            tail->next = curr; tail=curr;
            if (curr->next)
                pq.push(curr->next);
        }
        
        tail->next = NULL;
        
        return dummy->next;
    }
};