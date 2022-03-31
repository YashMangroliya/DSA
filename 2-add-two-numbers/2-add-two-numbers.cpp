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
    ListNode * start=nullptr, * end=nullptr;
    void add(int num)
    {
        ListNode * node= new ListNode(num);
        node->val=num;
        node->next=nullptr;
        if(end==nullptr)
        {
            start=end=node;
        }
        else
        {
            end->next=node;
            end=node;
        }
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum;
        while(l1!=nullptr || l2!=nullptr)
        {
            sum=carry;
            if(l1!=nullptr) sum+=l1->val;
            if(l2!=nullptr) sum+=l2->val;
            carry=0;
            if(sum>=10)
            {
                carry=sum/10;
                sum=sum%10;
            }
            add(sum);
            if(l1!=nullptr) l1=l1->next;
            if(l2!=nullptr) l2=l2->next;
        }
        
        while(carry>0)
        {
            sum = carry%10;
            carry/=10;
            add(sum);
        }
        
        return start;
    }
};