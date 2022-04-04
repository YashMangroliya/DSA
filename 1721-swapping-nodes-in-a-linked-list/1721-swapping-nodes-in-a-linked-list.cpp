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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * first, * second, * itr;
        int size,f,s,index,g;
        size=0;
        for(itr=head;itr!=nullptr;itr=itr->next)
        {
            size++;
        }
        index=1;
        f=k;
        s=size-k+1;
        for(itr=head;itr!=nullptr;itr=itr->next)
        {
            if(index==f) first=itr;
            if(index==s) second=itr;
            index++;
        }
        g=first->val;
        first->val=second->val;
        second->val=g;
        return head;
    }
};