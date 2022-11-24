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


struct Node{
    int num;
    int pos;
};
struct Comparator{
    
    bool operator()(Node &lhs, Node &rhs){
        return lhs.num > rhs.num;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        //Sentinal
        ListNode *head= new ListNode(-1);
        ListNode *temp = head;
        
        int N = lists.size();
        
        priority_queue<Node, vector<Node> , Comparator> pq;
        
        
        for(int i=0; i<N; i++){
            
            if(lists[i]!=NULL){
                pq.push({lists[i]->val, i});
                lists[i] = lists[i]->next;
            }
        }
        
        int remList = N;
        while(!pq.empty()){
            
            Node tmp = pq.top();
            pq.pop();
            
            int num = tmp.num;
            int pos = tmp.pos;
            
            temp->next = new ListNode(num);
            
            if(lists[pos]!=NULL){
                pq.push({lists[pos]->val, pos});
                lists[pos] = lists[pos]->next;
            }
            
            temp = temp->next;
        }
        
        
        return head->next;
    }
};