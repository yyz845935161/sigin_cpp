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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head==nullptr) return head;
        ListNode* temp = head;
        while(temp && temp->val == val)
        {
            head=head->next;
            temp=head;
        }

        ListNode* next = head->next;
        while(next)
        {
            if(next->val == val)
            {
                temp->next=next->next;
            }
            next=next->next;
            temp=temp->next;
        }
        return head;
    }
};