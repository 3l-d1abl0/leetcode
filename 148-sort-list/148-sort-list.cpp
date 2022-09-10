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
    
    ListNode *merge(ListNode *l1, ListNode *l2){
        
        if(l1 == NULL)  return l2;
        if(l2 == NULL)  return l1;
        
        ListNode *head = new ListNode();
        ListNode *temp = head;
        
        while(l1 != NULL && l2 != NULL){
            
            if(l1->val > l2->val){            
                temp->next = l2;
                l2 = l2->next;
            }else{
                temp->next = l1;
                l1 = l1->next;
            }
            
            temp = temp->next;
        }
        
        if(l2==NULL) temp->next = l1;
        if(l1==NULL) temp->next = l2;
        
        temp = head->next;
        delete(head);
        
        return temp;
    }
    
    
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next==NULL)
            return head;
           
        ListNode *prev = head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast != NULL && fast->next!= NULL){
            
            prev =slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        prev->next = NULL;
        
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        
        return merge(l1, l2);
        
        
    }
    
    
};