class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        int N = nums.size();
        
        vector<int> ans;
        vector<int> noni(N, 1);
        vector<int> nond(N, 1);
        
        for(int i=N-2; i>=0; i--)
            if(nums[i]>=nums[i+1])
                noni[i]= noni[i+1]+1;
        
        for(int i=1; i<N; i++)
            if(nums[i]>= nums[i-1])
                nond[i] = nond[i-1]+1;
        
        for(int i=k; i<N-k; i++)
            if(noni[i-k]>=k && nond[i+k]>=k)
                ans.push_back(i);
        
        return ans;
    }
};