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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL && l2 == NULL)
            return NULL;
        
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        
        if(l1->val > l2->val)
            swap(l1, l2);
        
        ListNode* head = l1;
        ListNode* prev = NULL;
        
        while(l1!=NULL && l2!=NULL){
            
            if(l1->val<=l2->val){
                prev = l1;
                l1=l1->next;
            }else{
                prev->next = l2;
                l2=l2->next;
                prev->next->next=l1;
                prev= prev->next;
            }
        }
        
        while(l2!=NULL){
            prev->next = l2;
            prev=l2;
            l2=l2->next;
        }
        
        return head;
        
    }
};