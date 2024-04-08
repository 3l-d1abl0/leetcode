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
    
    vector<vector<int>> bitwisePowerSet(vector<int> &nums){
        
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
    
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        
        //Method1 - bitset
        return bitwisePowerSet(nums);
        
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> ans;
        
        /*
        Key a set
        create string key , concatenating athe keys in a Subset
        
        Similar thing can be done with Inclue _Exlude Method
        */
        subsetsRecursion(0, nums, ans, res);

        return res;
    }
    
};