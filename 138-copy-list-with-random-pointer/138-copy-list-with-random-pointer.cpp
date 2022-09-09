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
    
    Node* method2(Node *l1){
        
        if(l1 == NULL)
            return l1;
        
        Node *head = l1;
        Node *nxt;
        //copy next
        while(head != NULL){
            
            nxt = head->next;
            head->next = new Node(head->val);
            head->next->next = nxt;
            
            head = nxt;
        }
        
        //copy random
        head = l1;
        while(head!= NULL){
            head->next->random = (head->random==NULL)?NULL:head->random->next;
            head = head->next->next;
        }
        
        //detangle
        head = l1;
        Node *new_head = head->next;
        
        /*while(head!=NULL){
           cout<<head->val<<" ";
            head = head->next;
        }cout<<endl;*/
        
        while(head!=NULL){
            
            Node *temp = head->next;
            head->next= temp->next;
            temp->next = (temp->next==NULL)?NULL:temp->next->next;
            
            head = head->next;
            temp = temp->next;
        }
        
        return new_head;
    }
    
    Node* copyRandomList(Node* head) {
        
        //using Maps
        //return method1(head);
        
        //use constant space;
        return method2(head);
    }
};