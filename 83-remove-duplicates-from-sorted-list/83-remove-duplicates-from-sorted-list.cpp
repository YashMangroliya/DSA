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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *h=head;
        if(h==nullptr) return head;
        while(h->next!=nullptr)
        {
            if(h->val==h->next->val) h->next=h->next->next;
            else h=h->next;
        }
        return head;
    }
};