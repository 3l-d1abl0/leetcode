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
    
    int getLength(ListNode *node){
        if(node == NULL)
            return 0;
        
        int len =0;
        while(node!=nullptr){
            node = node->next;
            len++;
        }
        
        return len;
    }
    
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        if(head == NULL)
            return vector<ListNode *> (k, NULL);
        
        int sz = getLength(head);
        int chunks = sz/k; //cout<<chunks<<endl;
        int rem = sz%k; //cout<<rem<<endl;
        
        vector<ListNode*> vec;
        ListNode *temp;
        
        for(int i=1; i<=rem; i++){
            vec.push_back(head);
            for(int j=1; j<=chunks+1; j++){
                temp = head;
                head = head->next;
            }    
            temp->next = NULL;
        }
        
        for(int i=1; i<=k-rem; i++){
            
            vec.push_back(head);
            for(int j=1; j<=chunks; j++){
                temp = head;
                head = head->next;
            }
            temp->next= NULL;
        }
        
        
        /*if(sz<k){
            for(int i=0; i<k-sz; i++)
                vec.push_back(NULL);
        }*/
        
        return vec;
        
    }
};