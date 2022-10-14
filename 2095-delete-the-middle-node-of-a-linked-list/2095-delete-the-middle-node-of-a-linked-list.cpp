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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode *slow, *fast,* prev;
        slow=fast=head;
        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(slow==head) return head->next;
        prev->next=slow->next;
        return head;
    }
};