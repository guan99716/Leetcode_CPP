struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return nullptr;
        int n = 1;
        // find end and count num of nodes
        ListNode * curr = head;
        while(curr->next){
            n++;
            curr = curr->next;
        }
        ListNode * end = curr;
        end->next = head;

        // find where to truncate
        curr = end;
        for(int i = 0; i < n-k;i++){
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next=nullptr;
        return newHead;
    }
};