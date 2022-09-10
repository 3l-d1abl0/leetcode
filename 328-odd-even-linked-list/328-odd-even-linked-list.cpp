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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL)
            return head;
        
        ListNode *oddHead = head, *odd= head;
        ListNode *evenHead = head->next, *even = head->next;
        
        while(even!=NULL){
            
            odd->next = even->next;
            even->next = (even->next==NULL)?NULL:even->next->next;
            
            if(odd->next!=NULL)
                odd = odd->next;
            
            even = even->next;
        }
        
        odd->next = evenHead;
        
        return oddHead;
    }
};