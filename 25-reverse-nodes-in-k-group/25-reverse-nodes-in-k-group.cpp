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
        if(l1==NULL) return 0;
        
        return 1+getLen(l1->next);
    }
    
    ListNode *rev(ListNode *head, int k, int len){
        
        if(head == NULL)
            return NULL;
        
        
        if(len<k)
            return head;
        
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
        
        if(curr==NULL){ //N%k!=0
            head->next = NULL;
        }else{
            head->next = rev(curr, k, len);
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int len = getLen(head);
        return rev(head, k, len);
        
    }
};