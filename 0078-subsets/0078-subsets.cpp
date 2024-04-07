class Solution {
public:
    
    void usingBits(vector<int> &arr, vector<vector<int>> &ans){

        int N = arr.size();
        
        
        for(int counter=0; counter<= (1<<N); counter++){
            vector<int> subset;
            for(int j=0; j<N; j++){

                if( counter & (1<<j))
                    subset.push_back(arr[j]);
            }

            ans.push_back(subset);
        }
        ans.pop_back();
    } 
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        //Method1
        usingBits(nums, ans);
        return ans;
    }
};