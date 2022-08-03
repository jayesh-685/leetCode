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
// either store all nodes in a stack or array or map and then use one by one or reverse later half of ll and then use two pointer approach
class Solution {
public:
    ListNode* reverseLL (ListNode* head) {
        if (!head || !head->next)
            return head;
        
        ListNode* newHead = reverseLL(head->next), *tail = head->next;
        tail->next = head;
        head->next = NULL;
        return newHead;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* slow=head, *fast=head;
        while (fast && fast->next) {
            fast = fast->next->next; slow = slow->next;
        }
        
        ListNode *l=head, *r = reverseLL(slow->next);
        slow->next = NULL;
        
        while (l && r) {
            ListNode *tempL=l->next, *tempR=r->next;
            l->next = r;
            l = tempL;
            r->next = l;
            r = tempR;
        }
        
    }
};