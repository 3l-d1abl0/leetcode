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

    ListNode *addSame(ListNode *l1, ListNode* l2, int &carry){
        
        ListNode* node= new ListNode();
        int sum=0;
        
        if(l1->next==NULL){
            node->next= NULL;
        }else{
            node->next = addSame(l1->next, l2->next, carry);
        }
        
        sum = l1->val+l2->val+carry;
        
        carry = sum/10;
        node->val= sum%10;
        
        return node;
        
    }
    
    ListNode *addDiff(ListNode *l1, ListNode *l2, int &carry, int diff){
        
        ListNode* node= new ListNode();
        int sum=0;
        
        if(diff==0){
            return addSame(l1, l2, carry);
        }else{
            node->next = addDiff(l1->next, l2, carry, diff-1);
        }
        
        sum = l1->val+carry;
        
        carry = sum/10;
        node->val= sum%10;
        
        return node;
        
    }
    
    
    int getLength(ListNode *node){
            
        if(node==NULL)
            return 0;
        
        return 1+getLength(node->next);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        
        if(len1 <len2){
            swap(len1, len2);
            swap(l1, l2);   
        }
        int diff = len1-len2;
        
        
        //perform
        int carry=0;
        ListNode* node= new ListNode();
        node = addDiff(l1,l2, carry, diff); 
        
        //check if there is a carry
        if(carry==0){
            return node;
        }else{
            ListNode *n1=  new ListNode();
            n1->val=carry;
            n1->next= node;
            
            return n1;
        }
    }
};