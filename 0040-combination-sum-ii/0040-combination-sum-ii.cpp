class Solution {
public:
    void solve(vector<int>& nums,int pos,int n,vector<int> &temp,vector<vector<int>> &ans,int target,int sum)
    {
        if(sum==target)
        {
            ans.push_back(temp);
            return;
        }
        if(sum>target)
            return;
        if(pos>=n)
            return;
        temp.push_back(nums[pos]);
        sum+=nums[pos];
        solve(nums,pos+1,n,temp,ans,target,sum);
        temp.pop_back();
        sum-=nums[pos];
        while(pos+1<n && nums[pos]==nums[pos+1]) pos++;
        solve(nums,pos+1,n,temp,ans,target,sum);
        
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        solve(nums,0,n,temp,ans,target,0);
        return ans;
    }
};