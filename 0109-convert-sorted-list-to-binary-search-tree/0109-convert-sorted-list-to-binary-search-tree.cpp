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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
        if(head==nullptr)
            return NULL;
        
        if(head->next == nullptr)
            return new TreeNode(head->val);
        
        //Find middle ground
        ListNode *slow = head;
        ListNode *fast = head->next->next;//one step head
        while(fast!= nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *newNode = new TreeNode(slow->next->val);
        
        ListNode *rightHalf = slow->next->next;
        newNode->right = sortedListToBST(rightHalf);
        
        slow->next = nullptr;
        newNode->left = sortedListToBST(head);
        
        
        return newNode;
    }
};