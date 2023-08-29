/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//我的方法  慢的先走
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;


        int l1=0;
        int l2=0;
        ListNode* ha = headA;
        ListNode* hb = headB;
        while(ha)
        {
            ha = ha->next;
            l1++;
        }
        while(hb)
        {
            hb = hb->next;
            l2++;
        }


        if(l1>l2)
        {
            while(l1>l2)
            {
                headA=headA->next;
                l1--;
            }
        }
        else
        {
            while(l1<l2)
            {
                headB=headB->next;
                l2--;
            }
        }

        while(headA!= nullptr && headB!=headA)
        {
            headB=headB->next;
            headA = headA->next;
        }

        return headA;

 
    }
};

//双指针 浪漫解法
//l1 + c + l2 = l2 +c + l1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode *n1 = headA,*n2 = headB;
        while(n1!=n2)
        {
            n1 = (n1 == nullptr? headB:n1->next);
            n2 = (n2 == nullptr? headA:n2->next);
            
        }
        return n1;

 
    }
};