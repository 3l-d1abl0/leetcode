class Solution {
public:
    
    void combRec(int idx, int target, vector<int> &arr, vector<int> &comb, vector<vector<int>> &combList){
        
        //If reached the Target
        if(target==0){
                combList.push_back(comb);
                    return ;
        }
        if(idx==arr.size()){
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
        return rec(target, candidates);
        
        //2. Method 2 - Iteration
        //return itr(target, candidates);
    }
};



/**

The time complexity of the Combination Sum problem using a backtracking approach is generally hard to express as a simple polynomial or exponential function because it depends on the number of valid combinations.

    Upper Bound: The upper bound is loose and is often cited as O(k⋅2^N) or O(k⋅N^T), where N is the number of candidates, T is the target value, and k is the average length of a combination.

    Tighter Estimate: A more practical estimate relates to the size of the search space, which involves the depth of the recursion and the branching factor.

        Let N be the number of candidates.

        Let T be the target sum.

        The depth of the recursion is at most min(arr)T​ (the shortest possible combination length) but is capped by T if candidates could be 1.

        At each step, we have two choices (include the current element or move to the next, provided arr[idx] <= target).

        Let K be the total number of valid combinations found.

        The total time is proportional to the size of the search space × the time to copy a valid combination.

The overall time complexity is approximately O(Number of Nodes in the State-Space Tree)×(Average Combination Length). Since the number of nodes can grow exponentially, a reasonable, albeit loose, practical bound is O(K⋅N⋅T) or O(K⋅L), where L is the average combination length and K is the number of solutions.


*/