/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    
    Node *method1(Node *head){
        
        if(head == NULL)
            return head;
        
        unordered_map<Node*, Node*> mp;
        
        Node* temp = head;
        Node* prev = NULL;
        
        while(temp!=NULL){
            mp[temp] = new Node(temp->val);
            if(prev != NULL)
                mp[prev]->next = mp[temp];
            
            prev = temp;
            temp = temp->next;
        }
        
        temp = head;
        while(temp!=NULL){
            mp[temp]->random = mp[temp->random];
            temp = temp->next;
        }
        
        return mp[head];
        
    }
    
    Node* copyRandomList(Node* head) {
        
        //using Maps
        return method1(head);
    }
};