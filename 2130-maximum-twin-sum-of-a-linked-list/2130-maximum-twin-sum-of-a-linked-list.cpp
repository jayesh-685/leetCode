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
    int pairSum(ListNode* head) {
        
        int n=0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }
        
        temp = head;
        unordered_map <int,int> mp;
        int ans=0;
        for (int i=0; i<n; i++) {
            if (i<n/2) {
                mp[i] = temp->val;
            } else {
                ans = max(ans, temp->val + mp[n-1-i]);
            }
            
            temp = temp->next;
        }
        
        return ans;
        
    }
};