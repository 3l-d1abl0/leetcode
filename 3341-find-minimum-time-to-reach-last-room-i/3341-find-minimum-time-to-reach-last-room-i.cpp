class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        
        int R = moveTime.size();
        int C = moveTime[0].size();
        
        //dir 
        vector<vector<int>> dir {
            {0, -1},
            {0, 1},
            {1, 0},
            {-1, 0}
        };
        
        
        vector<vector<int>> dp(R, vector<int> (C, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>> > >maxH;
        
        //start from 0,0
        maxH.push({0, {0,0}});
        dp[0][0] = 0;
        
        
        while(!maxH.empty()){
            
            auto pp = maxH.top();
            maxH.pop();
            
            int time = pp.first;
            pair<int, int> co = pp.second;
            
            if(co.first == R-1 && co.second == C-1)
                return time;
            
            for(auto dxy: dir){
                
                int xx= co.first + dxy[0];
                int yy= co.second + dxy[1];
                
                if(xx < 0 || xx >=R || yy<0 || yy >=C)
                    continue;
                
                int timeToReach = 1+ max(time, moveTime[xx][yy]);
                
                if(timeToReach < dp[xx][yy]){
                    dp[xx][yy] = timeToReach;
                    maxH.push({timeToReach, {xx, yy}});
                }
            }//for
            
        }//while
        
        
        return -1;
    }
};