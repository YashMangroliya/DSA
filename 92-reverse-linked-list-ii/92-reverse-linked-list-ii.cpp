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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode * tmp=head;
        ListNode * start,* end, * prevToStart=nullptr,* curr,* next,* prev;
        int i=1;
        while(tmp!=nullptr && i<left)
        {
            prevToStart=tmp;
            tmp=tmp->next;
            i++;
        }
        if(tmp==nullptr) return head;
        start=tmp;
        while(tmp!=nullptr && i<right)
        {
            tmp=tmp->next;
            i++;
        }
        if(tmp==nullptr) return head;
        end=tmp;
        
        curr=start;
        prev=end->next;
        next=curr->next;
        while(1)
        {
            curr->next=prev;
            if(curr==end) break;
            prev=curr;
            curr=next;
            if(next!=nullptr) next=next->next;
            
            
            // curr->next=prev;
            // tmp=next->next;
            // next->next=curr;
            // prev=curr;
            // curr=next;
            // next=tmp;
        }
        if(prevToStart!=nullptr) prevToStart->next=curr;
        if(start==head) return end;
        return head;
    }
};