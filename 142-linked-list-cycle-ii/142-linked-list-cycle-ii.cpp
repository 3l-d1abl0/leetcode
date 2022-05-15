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
    
    ListNode *loopStart(ListNode *head, ListNode *slow){
        
        while(head != slow){
            head = head->next;
            slow = slow->next;
        }
        
        return head;
    }
    
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *slow = head;
        ListNode *fast = head;
        
        while( fast != nullptr && fast->next!=nullptr){
            
            slow = slow->next;
            fast=fast->next->next;
            
            if(fast==slow){
                return loopStart(head, slow);
            }
            
        }
        
        return NULL;
    }
};