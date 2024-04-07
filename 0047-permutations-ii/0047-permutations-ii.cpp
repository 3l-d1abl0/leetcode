class Solution {
public:
    
    void solve(int idx, unordered_map<int, int> &freq, vector<vector<int>> &ans, vector<int> &row, int N){
        
        if(idx==N){
            ans.push_back(row);
            return ;
        }
        
        
        for(auto pp: freq){
            
            if(freq[pp.first]==0)
                continue;
            
            freq[pp.first]--;
            row.push_back(pp.first);
            
            solve(idx+1, freq, ans, row, N);
            
            freq[pp.first]++;
            row.pop_back();
            
        }
        
    }
    
    void recur(int idx, vector<int>& nums, vector<vector<int>> &ans) {
        
        
        if(idx==nums.size()){    
            ans.push_back(nums);
            return;
        }
        
        
        for(int i=idx; i<nums.size(); i++){
            
            if(i!= idx && nums[i]==nums[idx])
                continue;
            swap(nums[idx], nums[i]);
            recur(idx+1, nums, ans);
            swap(nums[idx], nums[i]);
        }
        
    }
    
    void recurMap(int idx, vector<int>& nums, vector<vector<int>> &ans) {
        
        
        if(idx==nums.size()){    
            ans.push_back(nums);
            return;
        }
        
        //map at level idx
        unordered_set<int> uniqueSet;
        for(int i = idx; i < nums.size(); i++) {
            
            if(uniqueSet.find(nums[i])!= uniqueSet.end()) {
                continue;
            }
            
            uniqueSet.insert(nums[i]);
            
            swap(nums[i], nums[idx]);
            recurMap(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        //1. Method1
        /*vector<vector<int>> ans;
        recur(0, nums, ans);
        return ans;
        This method fails because it is able to stop swapiing 
        of an element of the same vale at idx.
        
        but it is not able to stop the swapping of multiple values different than
        'idx'
        
        eg:
        2211
        
        2[0] <-->1 [2]
        2[0] <-->1[3]
        
        Instread use Map to keep check of the elemts
        used at particular idx /level
        
        
        ///////////////
        
        //2.Medthod2
        vector<vector<int>> ans;
        recurMap(0, nums, ans);
        return ans;
        */
        
        
        //3.Method 3
        /*
            Create a frequency map
            any any position (idx) place the unique chars
        */
        int N = nums.size();
        
        vector<vector<int>> ans;
        vector<int> row;
        
        //get Freq
        unordered_map<int, int> freq;
        for(int ele: nums){
            freq[ele]++;
        }
        
        
        solve(0, freq, ans, row, N);
        
        
        return ans;
    
    }
};