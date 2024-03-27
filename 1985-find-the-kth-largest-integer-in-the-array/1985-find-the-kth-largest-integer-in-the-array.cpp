class Solution {
public:
    
    struct Node{
        string ele;
    };
    
    struct ComparatorFn{
        
        bool operator()(const Node &lhs, const Node &rhs)const{
            
            if(lhs.ele.size() > rhs.ele.size())
                return true;
            else if (lhs.ele.size() < rhs.ele.size())
                return false;
            else{
                return lhs.ele > rhs.ele;
            }
            
        }
    };
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<Node, vector<Node> ,  ComparatorFn > minHeap;    //(arr.begin(), arr.begin()+K);
        for(int i=0; i<k; i++)
            minHeap.push(Node{nums[i]});
        
        for(int i=k; i<nums.size(); i++){
            
            minHeap.push(Node{nums[i]});
            
            if(minHeap.size() > k)
                minHeap.pop();
            
            
        }//for
        
        
        return minHeap.top().ele;
    }
};