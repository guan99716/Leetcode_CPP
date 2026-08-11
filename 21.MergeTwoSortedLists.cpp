struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
            ListNode *res = new ListNode(0);
            ListNode *p = list1;
            ListNode *q = list2;
            ListNode *curr = res;
            while (p != nullptr && q != nullptr) {
                if (p->val < q->val) {
                    curr->next = p;
                    p = p->next;
                } else {
                    curr->next = q;
                    q = q->next;
                }
                curr = curr->next;
            }
            if (p)
                curr->next = p;
    
            else if (q)
                curr->next = q;
    
            return res->next;
        }
    };