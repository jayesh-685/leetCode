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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *p1=list1, *p2=list2, *dummy, *curr;
        dummy = new ListNode (0);
        curr = dummy;
        
        while (p1 || p2) {
            if (p1 && p2) {
                if (p1->val < p2->val) {
                    curr->next = p1;
                    p1 = p1->next;
                } else {
                    curr->next = p2;
                    p2 = p2->next;
                }
            } else if (p1) {
                curr->next = p1;
                p1 = p1->next;
            } else {
                curr->next = p2;
                p2 = p2->next;
            }
            
            curr = curr->next;
        }
        
        return dummy->next;
    }
};