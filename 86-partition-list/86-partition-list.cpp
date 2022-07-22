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
    ListNode* partition(ListNode* head, int x) {
        ListNode *first = new ListNode (0);
        ListNode *second = new ListNode (0);
        ListNode *curr = head, *currF=first, *currS=second;
        while (curr) {
            if (curr->val < x) {
                currF->next = curr;
                currF = currF->next; 
            } else {
                currS->next = curr;
                currS = currS->next; 
            }
            curr = curr->next;
        }
        currF->next = second->next;
        currS->next = NULL;
        return first->next;
    }
};