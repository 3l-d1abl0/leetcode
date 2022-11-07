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
    ListNode *revList(ListNode *head){
        
        if(head==NULL) return NULL;
        
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *nxt = head;
        
        
        while(nxt!= NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        
        return prev;
    }
    
    void print(ListNode *node){
        
        
        ListNode *temp=node;
        
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    
    void reorderList(ListNode* head) {
        
        if(head->next==NULL)
            return;
        
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        
        while(fast != NULL && fast->next!= NULL){
            prev = slow;
            slow = slow->next;
            fast= fast->next->next;
        }
        
        prev->next = NULL;
        ListNode *half= revList(slow);
        //print(head);
        //print(half);
        
        ListNode *sentinel = new ListNode(-1);
        ListNode *newHead = sentinel;
        while(head!= NULL && half!=NULL){
            
            ListNode *temp1 = head->next;
            ListNode *temp2 = half->next;
            
            head->next = half;
            
            newHead->next = head;
            newHead= newHead->next->next;
            
            head = temp1;
            half = temp2;
        }
        
        //print(sentinel);
        
    }
};