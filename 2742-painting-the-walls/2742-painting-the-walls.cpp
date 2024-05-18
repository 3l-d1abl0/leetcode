class Solution {
public:
    
    int rec(int idx, int remainingWalls, vector<int> &cost, vector<int> &time, vector<vector<int>>  &memo){
        
        if(remainingWalls<=0)
            return 0;   //no more walls to paint
        
        if(idx<0)
            return 1e9;//cannot arrive at sol. (still looking for walls to paint, i.e walls remaing, but no walls to paint)
        
        if(memo[idx][remainingWalls] !=-1)
            return memo[idx][remainingWalls];
        
        int notPick = rec(idx-1, remainingWalls, cost, time, memo);
        
        int pick = cost[idx]+rec(idx-1, remainingWalls-1-time[idx], cost, time, memo);
        
        
        return memo[idx][remainingWalls]=min(notPick, pick);
        
        
    }
    
    int paintWalls(vector<int>& cost, vector<int>& time) {
        
        int remainingWalls = time.size();//N walls are unpainted
        
        vector<vector<int>> memo(remainingWalls+1, vector<int>(remainingWalls+1, -1));
        
        
        return rec(remainingWalls-1, remainingWalls, cost, time, memo);
        
    }
};