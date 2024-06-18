class Solution {
public:
    
    int recur(int i, int j, vector<int> &cuts, vector<vector<int>> &memo){
        
        if(i>j)
            return 0;
        
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        int minn = 1e9;
        for(int k=i; k<=j; k++){
            int cost = cuts[j+1]- cuts[i-1];
            cost += recur(i, k-1, cuts, memo) + recur(k+1, j, cuts, memo);
            
            minn = min(minn, cost);
        }
        
        return memo[i][j] = minn;
        
    }
    
    int recMemo(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>> memo( (cuts.size()-2)+1, vector<int> ( (cuts.size()-2)+1, -1) );
        
        return recur(1, cuts.size()-2, cuts, memo);
        
    }
    
    int minCost(int n, vector<int>& cuts) {
        
        
        //1. Rec+memo
        return recMemo(n, cuts);
        
    }
};