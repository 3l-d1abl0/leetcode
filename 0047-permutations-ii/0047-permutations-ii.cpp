class Solution {
public:
    
    void solve(int idx, unordered_map<int, int> &freq, vector<vector<int>> &ans, vector<int> &row, int N){
        
        if(idx==N){
            ans.push_back(row);
            return ;
        }
        
        // from o - N
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
            /*
                If the next number to be swapped has been swapped 
                previously
            */
            if(i!= idx && nums[i]==nums[i-1])
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
        
        //map at level idx- keep track of the numbers processed at this level
        unordered_set<int> processed;
        for(int i = idx; i < nums.size(); i++) {
            
            if(processed.find(nums[i])!= processed.end()) {
                continue;
            }
            
            processed.insert(nums[i]);
            
            swap(nums[i], nums[idx]);
            recurMap(idx+1, nums, ans);
            swap(nums[i], nums[idx]);
            
        }
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        //1. Method1
        /*
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans1;
        recur(0, nums, ans1);
        return ans1;
    
        This method fails because it is able to stop swapiing 
        of an element which is same as the previous.
        
        But will faisl since after swapping , the order of same numbers will change
        (we cannot swap at lower level)
        eg [0, 0, 1, 9]
        
        [ 0,1,9]    [conti] [1 0,0,9]   [9 0,1,0]
        
                                        [9,0  1,0]  [9,1  0,0]  [9,0  1,0]
        

        
        Instread use Map to keep check of the elemts
        used at particular idx /level
        
        
        ///////////////
        
        //2.Medthod2 - 3ms
        vector<vector<int>> ans2;
        recurMap(0, nums, ans2);
        return ans2;
        */
        
        
        /*3.Method 3 - 4ms
        
          //  Create a frequency map
          //  any any position (idx) place the unique chars
          
            O(N×N!)
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