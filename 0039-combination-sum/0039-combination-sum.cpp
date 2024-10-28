class Solution {
public:
    
    void combRec(int idx, int target, vector<int> &arr, vector<int> &comb, vector<vector<int>> &combList){
        
        if(idx==arr.size()){
            if(target==0)
                combList.push_back(comb);
                    return ;
        }
        
        //If reached the Target
        if(target==0){
                combList.push_back(comb);
                    return ;
        }
        
        
        //Include
        if(arr[idx]<= target){
            comb.push_back(arr[idx]);
            //unlimited number of times- hence staying on the index
            combRec(idx, target-arr[idx], arr, comb, combList);    
            comb.pop_back();
        }
        
        combRec(idx+1, target, arr, comb, combList);    
        
    }
    
    //1. Method 1
    vector<vector<int>> rec(int target, vector<int> &arr){
        
        vector<vector<int>> combList;
        vector<int> comb;
        
        combRec(0, target, arr, comb, combList);
        
        return combList;
    }
    
    void combItr(int idx, int target, vector<int> &can, vector<int> &comb, vector<vector<int>> &combList){
        
        if(target<0)    return;
        
        if(target==0){  
            combList.push_back(comb);
            return ;
        }
        
        //start from the same Index
        for(int i=idx; i<can.size(); i++){
            
            if(can[i]<=target){
                comb.push_back(can[i]);
                combItr(i, target-can[i], can, comb, combList);
                comb.pop_back();
                
            }
            
        }
        
        
        return ;
    }
    
    vector<vector<int>> itr(int target, vector<int> &can){
        
        vector<vector<int>> combList;
        vector<int> comb;
        
        combItr(0, target, can, comb, combList);
        
        return combList;
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        //1. Method 1 - Recursion
        //return rec(target, candidates);
        
        //2. Method 2 - Iteration
        return itr(target, candidates);
    }
};