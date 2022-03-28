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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *listNodeItr=nullptr;
        ListNode *l3;
        if(l1==nullptr && l2==nullptr) return nullptr;
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l1->val<l2->val)
            {
                listNodeItr=l1;
                l1=l1->next;
            }
            else
            {
                listNodeItr=l2;
                l2=l2->next;
            }
        l3=listNodeItr;
        while(l1!=nullptr && l2!=nullptr)        
        {
            if(l1->val<l2->val)
            {
                listNodeItr->next=l1;
                listNodeItr=listNodeItr->next;
                l1=l1->next;
            }
            else
            {
                listNodeItr->next=l2;
                listNodeItr=listNodeItr->next;
                l2=l2->next;
            }
        }
        while(l1!=nullptr)
        {
            listNodeItr->next=l1;
            listNodeItr=listNodeItr->next;
            l1=l1->next;
        }
        while(l2!=nullptr)
        {
            listNodeItr->next=l2;
            listNodeItr=listNodeItr->next;
            l2=l2->next;
        }
        return l3;
    }
};