class Solution {
public:
    
    void comb(int idx, vector<int> &arr, vector<vector<int>> &ans, vector<int> &combination, int target, int k){
        
        
        
        if( k == combination.size()){
            
            if(target ==0){
                
                ans.push_back(combination);
                //cout<<"idx = "<<idx<<endl;
                return;
            }
            
            return;
        }
        
        if(idx==arr.size()) return;
        
        if(target>=arr[idx]){
            combination.push_back(arr[idx]);
            comb(idx+1, arr, ans, combination, target-arr[idx], k);
            combination.pop_back();
        }
        
        comb(idx+1, arr, ans, combination, target, k);
        
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int target) {
        
        
        vector<int> arr ={1,2,3,4,5,6,7,8,9};
        
        
        vector<vector<int>> ans;
        vector<int> combination;
        
        comb(0, arr, ans, combination, target, k);
        
     
        return ans;
    }
};