class Solution {
public:
    
    void combinationRec(int idx, int target, int k, vector<int> &candidates, vector<int> &comb, vector<vector<int>> &combList){
        
        if(k==comb.size()){
            if(target == 0){
                combList.push_back(comb);
                return;
            }
        }

        if(idx == candidates.size() )
            return;


        //Include
        if(candidates[idx]<= target){

            comb.push_back(candidates[idx]);
            combinationRec(idx+1, target- candidates[idx], k, candidates, comb, combList);
            comb.pop_back();

        }

        //exclude
        combinationRec(idx+1, target, k, candidates, comb, combList);


        return;

    }
    
    
    void combinationItr(int idx, int target, int k, vector<int> &comb, vector<vector<int>> &combList){
        
        
        if(k==comb.size()){
            if(target==0){
                combList.push_back(comb);
                return;
            }
                
        }
        
        if(idx>9) return;
        
        for(int i=idx; i<=9; i++){
            
            if(i<=target){
                comb.push_back(i);
                combinationItr(i+1, target-i, k, comb, combList);
                comb.pop_back();
            }
            
        }
        
        return ;
    }
    
    vector<vector<int>> method1(int k, int n){
        
        vector<vector<int>> combList;
        vector<int> comb;
        
        vector<int> arr ={1, 2, 3, 4, 5, 6, 7, 8, 9};
        combinationRec(0, n, k, arr, comb, combList);
        
        
        return combList;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
        //1. Include+Exclude
        return method1(k,n);
        
        //combinationItr(1, n, k, comb, combList);

        //return combList;
    }
};