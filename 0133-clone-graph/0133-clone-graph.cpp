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
        
        
        /*
            The number of nodes in the graph is in the range [0, 100].
            1 <= Node.val <= 100
            Node.val is unique for each node.
        */
        //to keep a check if a node has been created
        vector<Node *> nodesMap(101, nullptr);
        
        
        Node *newNode = clone(node , nodesMap);
            
        
        return newNode;
    }
    
    Node* clone(Node* node, vector<Node *> &nodesMap) {
        
        if(node==nullptr)
            return node;
    
        //Check if the node have been created
        if(nodesMap[node->val]!= nullptr)
            return nodesMap[node->val];
        else{
            
           Node *cloneNode = new Node(node->val);
            
            nodesMap[node->val] = cloneNode;
        
            for(Node *ele: node->neighbors){
                cloneNode->neighbors.push_back(clone(ele, nodesMap));
            }
        
        
        
            return cloneNode;
            
        }
    
    }    
    
    
};