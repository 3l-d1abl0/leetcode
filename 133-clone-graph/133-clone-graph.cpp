/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        
        //unordered_map<int, Node *> mp;
        vector<Node *> mp(101, nullptr);
        
        
        Node *newNode = clone(node , mp);
            
        
        return newNode;
    }
    
    Node* clone(Node* node, vector<Node *> &mp) {
        
        if(node==nullptr)
            return node;
    
        if(mp[node->val]!= nullptr)
            return mp[node->val];
        else{
            
           Node *newNode = new Node(node->val);
            
            mp[node->val] = newNode;
        
            for(Node *ele: node->neighbors){
                newNode->neighbors.push_back(clone(ele, mp));
            }
        
        
        
            return newNode;
            
        }
    
    }    
    
    
};