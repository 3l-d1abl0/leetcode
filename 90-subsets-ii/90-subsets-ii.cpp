class Solution {
public:
     void subsetsRecursion(int idx, vector<int> &nums, vector<int> &ans, vector<vector<int>> &res){

        res.push_back(ans);

                if (nums.size() == idx)
            return;


        for(int i=idx; i<nums.size(); i++){

            if(i>idx && nums[i]==nums[i-1]) continue;

            ans.push_back(nums[i]);
            subsetsRecursion(i+1, nums, ans, res);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> ans;

        subsetsRecursion(0, nums, ans, res);

        return res;
    }
    
};