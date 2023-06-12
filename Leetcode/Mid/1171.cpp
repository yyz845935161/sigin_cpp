
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* newhead = new ListNode(0,head);
        ListNode* l = newhead->next;
        ListNode* pre = newhead;
        while(l!=nullptr)
        {
            int val=0;
            ListNode* r = l;
            bool u = true;
            while(r!=nullptr)
            {
                val+=r->val;
                if(val==0)
                {
                    // 删除
                    pre->next = r->next;
                    l = pre->next;
                    u = false;
                    break;

                }
                r = r->next;
            }

            if(u)
            {
                l=l->next;
                pre=pre->next;
            }



        }
        return newhead->next;

    }
};