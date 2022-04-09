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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // Method 1
        
        // int size=0;
        // ListNode * t, * prev, * curr;
        // t=head;
        // while(t!=nullptr)
        // {
        //     size++;
        //     t=t->next;
        // }
        // int i=0;
        // prev=nullptr;
        // curr=head;
        // while(i<(size-n))
        // {
        //     prev=curr;
        //     curr=curr->next;
        //     i++;
        // }
        // if(prev!=nullptr && curr!=nullptr)
        // {
        //     prev->next=curr->next;
        //     return head;
        // }
        // else if(prev==nullptr && curr!=nullptr)
        // {
        //     head=head->next;
        //     return head;
        // }
        // else return nullptr;
        
        
        
        // Method 2
        
        ListNode *slow,*fast;
        fast=slow=head;
        int i=0;
        while(i<n)
        {
            fast=fast->next;
            i++;
        }
        if(fast==nullptr) return head->next;
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;
        
    }
};