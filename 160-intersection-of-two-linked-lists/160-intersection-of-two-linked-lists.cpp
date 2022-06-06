/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// TLE Error
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         list<ListNode*> l;
//         while(headB!=nullptr) 
//         {
//             l.push_back(headB);
//             headB=headB->next;
//         }
//         list<ListNode*>::iterator itr;
//         while(headA!=nullptr)
//         {
//             itr=find(l.begin(),l.end(),headA);
//             if(itr!=l.end()) return (*itr);
//             headA=headA->next;
//         }
//         return nullptr;
//         }
// };


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * first, *second;
        first=headA;
        second=headB;
        bool flagA=false,flagB=false;
        while(1)
        {
            if(first==second) return first;
            first=first->next;
            if(first==nullptr)
            {
                if(flagA) return nullptr;
                first=headB;
                flagA=true;
            }
            
            second=second->next;
            if(second==nullptr)
            {
                if(flagB) return nullptr;
                second=headA;
                flagB=true;
            }
        }
    }
};