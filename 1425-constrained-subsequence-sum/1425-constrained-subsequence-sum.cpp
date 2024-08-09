class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        
        int N = nums.size();
        priority_queue<pair<int, int>> mxHeap;
        mxHeap.push({nums[0], 0});
        int currMaxSum = nums[0], maxSum=nums[0];
        
        for(int idx=1; idx<N; idx++){
            
            while(!mxHeap.empty() && idx - mxHeap.top().second >k){
                mxHeap.pop();     
            }
            
            //cout<<"1. maxHeap= "<<maxSum<<endl;
            if(!mxHeap.empty())
                currMaxSum = max(nums[idx], mxHeap.top().first+nums[idx]);
            //cout<<"2. maxHeap= "<<maxSum<<endl;
            maxSum = max(currMaxSum, maxSum);
            cout<<" , "<<currMaxSum<<" ";
            mxHeap.push({currMaxSum, idx});
        }//for
        
        
        return maxSum;
    }
};