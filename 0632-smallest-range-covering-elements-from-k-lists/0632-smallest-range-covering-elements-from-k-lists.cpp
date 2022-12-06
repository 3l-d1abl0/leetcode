struct Node{
    int val, row, col;
};

struct CompareFn{
    
    bool operator()(Node const &v1, Node const &v2){
        return v1.val > v2.val;
    }
    
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        
        int N = nums.size();
        
        vector<int> ans{(int)-1e6, (int)1e6};
        
        priority_queue<Node, vector<Node>, CompareFn> minHeap;
        
        int maxx = -1e6;
        for(int i=0; i<N; i++){
            minHeap.push({nums[i][0], i, 0});
            maxx = max(maxx, nums[i][0]);
        }
        
        
        //loop terminates when any of the list runs out of elements
        while(true){
            
            Node nodeVal = minHeap.top(); minHeap.pop();
            //cout<<nodeVal.val<<" "<<nodeVal.row<<" "<<nodeVal.col<<endl;
            if(maxx - nodeVal.val < ans[1]-ans[0]){
                ans[0] = nodeVal.val;
                ans[1] = maxx;
                //cout<<"ans ="<<ans[0]<<" "<<ans[1]<<endl;
            }
            
            //chec if any list has ended
            if(nodeVal.col+1 >= nums[nodeVal.row].size())
                return ans;
            
            //check for a new Max
            maxx = max(maxx, nums[nodeVal.row][nodeVal.col+1]);
            
            minHeap.push({nums[nodeVal.row][nodeVal.col+1], nodeVal.row, nodeVal.col+1});
            
            
        }
        
        
        return ans;
        
    }
};