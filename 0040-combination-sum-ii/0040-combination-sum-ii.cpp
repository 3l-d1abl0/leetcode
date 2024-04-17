class Solution {
public:
    
    void combRec(int idx, int target, vector<int> &candidates, vector<int> &comb, vector<vector<int>> &combList){
            
        if(target==0){
            combList.push_back(comb);
            return ;
        }
        
        for(int i=idx; i<candidates.size(); i++){
            
            //Skip the other occurances of of same element 
            //as combination with it has already been considered in f(idx)
            if(i>idx && candidates[i]==candidates[i-1])
                continue;
            
            
            if(candidates[i]<=target){
                comb.push_back(candidates[i]);
                combRec(i+1, target-candidates[i], candidates, comb, combList);
                comb.pop_back();
            }
            
        }
        
        return ;
        
    }
    
    void includeExclude(int idx, int target,  vector<int> &candidates, vector<int> &comb, vector<vector<int>> &combList){
        
        if(target == 0){
            combList.push_back(comb);
            return ;   
        }
        
        if(idx==0)
            return;
        
        //Include
        if(candidates[idx-1]<=target){
            comb.push_back(candidates[idx-1]);
            includeExclude(idx-1, target-candidates[idx-1], candidates, comb, combList);
            comb.pop_back();
        }
        
        //Exclude
        /*
            If excluding this elemnet ,
            better exclude all occurance of this element, to
            avoid creating other combination
            
            [ 5, 2, 1, 1] => [5, 2, 1] [5,2,1]
            
            current idx => idx-1
        */
        //reach at the last occurance of the curernt element
        while(idx-2 >=0 && candidates[idx-2] == candidates[idx-1])
            idx--;
        
        includeExclude(idx-1, target, candidates, comb, combList);
    }
    
    vector<vector<int>> method1(vector<int> &candidates, int target){

        sort(candidates.begin(), candidates.end()); //to bring single order
        vector<vector<int>> combList;
        vector<int> comb;
        
        int N=candidates.size();
        includeExclude(N, target, candidates, comb, combList);
        
        
        return combList;
    }
    
    vector<vector<int>> method2(vector<int> &candidates, int target){
        
        sort(candidates.begin(), candidates.end()); //to bring single order
        vector<vector<int>> combList;
        vector<int> comb;
        
        combRec(0, target, candidates, comb, combList);
        return combList;
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        //1. Include + Exclude
        //return method1(candidates, target);
        

        //2. Recursion + Backtracking
        return method2(candidates, target);
        
    }
};