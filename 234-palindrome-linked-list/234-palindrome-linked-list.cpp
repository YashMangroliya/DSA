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
    bool isPalindrome(ListNode* head) {
        stack<int> stk1;
        int size=0;
        ListNode* tmp=head;
        while(tmp!=nullptr)
        {
            tmp=tmp->next;
            size++;
        }
        tmp=head;
        for(int i=0;i<size/2;i++) 
        {
            stk1.push(tmp->val);
            tmp=tmp->next;
        }
        if(size%2==1 && stk1.empty()==false) 
        {
            tmp=tmp->next;
        }
        for(int i=0;i<size/2 && stk1.empty()==false;i++)
        {
            if(stk1.top()!=tmp->val) return false;
            tmp=tmp->next;
            stk1.pop();
        }
        return true;
    }
};