class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
                int N = nums.size();

        unordered_set<string> subsets_string;

        vector<vector<int>> res;
        
        //to maintain the order of keys
        sort(nums.begin(), nums.end());

        for (int i = 0; i < (1 << N); i++)
        {

            vector<int> vec;
            string key;

            for (int j = 0; j < N; j++)
            {

                if (i & (1 << j))
                {
                    vec.push_back(nums[j]);
                    key += to_string(nums[j]) + "-";
                }
            }

            if (subsets_string.find(key) == subsets_string.end())
            {
                res.push_back(vec);
                subsets_string.insert(key);
            }
        }

        return res;
    }
        
    
};