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
    bool isPalindrome(ListNode* head) {
        
        stack<int> st;
        
        ListNode *slow = head;
        ListNode *fast = head;
        st.push(slow->val);
        
        while(fast != nullptr && fast->next!= nullptr ){
            
            
            slow = slow->next;
            fast = fast->next->next;
            
            st.push(slow->val);
        }
        
        
        if(fast==nullptr) st.pop(); //even length
        
        
        while(slow != nullptr){
        
            
            if(slow->val != st.top())
                return false;
            
            slow = slow->next;
            st.pop();
            
        }
        while(!st.empty()){
            
            st.pop();
        }
        return true;
    }
};