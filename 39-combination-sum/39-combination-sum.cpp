class Solution {
public:
    
    void combination(int idx, vector<int> &candidates, int target, vector<vector<int>> &comb, vector<int> combList){
        
        if(target < 0) return;
        
        if(idx == candidates.size()){
            
            if(target == 0) comb.push_back(combList);
            
            return ;
        }
        
        
        if(target - candidates[idx]>=0){
            
            combList.push_back(candidates[idx]);
            target -= candidates[idx];
        
            combination(idx, candidates, target, comb, combList);
            
            combList.pop_back();
            target +=candidates[idx];
            
        }
        
        //exclude
        combination(idx+1, candidates, target, comb, combList);
        
        
        return;
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        
        vector<vector<int>> comb;
        
        vector<int> combList;
        
        combination(0, candidates, target, comb, combList);
        
        return comb;
    }
};