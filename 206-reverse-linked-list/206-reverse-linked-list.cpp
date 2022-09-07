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
    
    ListNode* iterative(ListNode* head){
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        
        while(curr!=NULL){
            next = curr->next;
            curr->next= prev;
            
            prev=curr;
            curr=next;
        }
        
        return prev;
        
    }
    
    
    void rec(ListNode** head, ListNode* curr, ListNode* prev ){
        
        
        if(curr->next==NULL){
            curr->next = prev;
            *head = curr;
            return;
        }
        
        ListNode* next = curr->next;
        curr->next = prev;
        
        rec(head, next, curr);
    }
    
    ListNode* recursive(ListNode *head){
        if(head==NULL)
            return NULL;
        rec(&head, head, NULL);
        
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        //return iterative(head);
        return recursive(head);
    }
};