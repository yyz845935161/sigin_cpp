/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* q = head;
        ListNode* pre=head;
        while(k--)
        {
            q=q->next;
        }

        while(q)
        {
            q=q->next;
            pre=pre->next;
        }
        return pre;



    }
};