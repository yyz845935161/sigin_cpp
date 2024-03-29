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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 && !l2)
        {
            return nullptr;
        }
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* head = new ListNode(-1);
        ListNode* newhead = head; 
        while(l1&&l2)
        {
            if(l1->val < l2->val)
            {
                head->next = l1;
                head=head->next;
                l1=l1->next;
            }
            else
            {
                head->next = l2;
                head=head->next;
                l2=l2->next;
            }
        }
        if(l2)
        {
            head->next=l2;
        }
        else
        {
            head->next=l1;
        }
        return newhead->next;

    }
};