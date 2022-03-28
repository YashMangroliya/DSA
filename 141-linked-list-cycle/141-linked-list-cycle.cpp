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
    bool hasCycle(ListNode *head) {
        while(head!=nullptr && head->val!=INT_MIN)
        {
            head->val=INT_MIN;
            head=head->next;
        }
        if(head==nullptr) return false;
        else return true;
    }
};