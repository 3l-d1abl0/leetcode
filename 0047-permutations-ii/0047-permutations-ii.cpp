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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
     
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