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
    int getLen(ListNode *l1){
        int len =0;
        for(; l1!=NULL; l1=l1->next) len++;
        return len;
    }
    
    
    ListNode *rev(ListNode *head, int k, int len){
        
        if(head == NULL)
            return NULL;
        
        if(len<k)   return head;
        
        int ctr=0;
        ListNode *prev = NULL;
        ListNode *curr= head;
        ListNode *next;
        
        while(ctr<k && curr!=NULL){
            
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
            
            ctr++;
        }
        
        len -=k;
        
        head->next = rev(curr, k, len);
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = getLen(head);
        return rev(head, k, len);
        
    }
};