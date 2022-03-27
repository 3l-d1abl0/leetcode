class Solution {
public:
    
    void combination(int idx, vector<int> &candidates, int target, vector<vector<int>> &comb, vector<int> combList){
        
        //if(target < 0) return;
        
            
        if(target == 0){
            comb.push_back(combList);
            return ;
        }
    
        if(idx == candidates.size() )return;
        
        for(int i=idx; i<candidates.size(); i++){   //sorted list

            if( i>idx && candidates[i] == candidates[i-1])
                continue;

            if(candidates[i] > target) break;

            combList.push_back(candidates[i]);
        
            combination(i+1, candidates, target - candidates[i], comb, combList);
            
            combList.pop_back();
            

        }
        
        
        return;
        
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                sort(candidates.begin(), candidates.end());
        vector<vector<int>> comb;
        
        vector<int> combList;
        
        combination(0, candidates, target, comb, combList);
        
        return comb;
    }
};