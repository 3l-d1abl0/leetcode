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
        
        using state = tuple<int, int, int, int>;    //current_time, dx, dy, step_cost
        vector<vector<int>> dp(R, vector<int> (C, INT_MAX));
        priority_queue<state, vector<state>, greater<state> > maxH;
        
        //start from 0,0
        maxH.push({0, 0, 0, 0});
        dp[0][0] = 0;
        
        
        while(!maxH.empty()){
            
            auto [time, X, Y, prevStepCost] = maxH.top();
            maxH.pop();
            
            if(X == R-1 && Y == C-1)
                return time;
            
            for(auto dxy: dir){
                
                int xx= X + dxy[0];
                int yy= Y + dxy[1];
                
                //out of maze
                if(xx < 0 || xx >=R || yy<0 || yy >=C)
                    continue;
                
                int nextStepCost = (prevStepCost !=1 ? 1:2);
                int timeToReach = max(time, moveTime[xx][yy]) + nextStepCost;
                
                //cout<<moveTime[xx][yy]<<"::"<<prevStepCost<<" = "<<nextStepCost<<endl;
                if(timeToReach < dp[xx][yy]){
                    dp[xx][yy] = timeToReach;
                    maxH.push({timeToReach, xx, yy, nextStepCost});
                }
            }//for
            
        }//while
        
        
        return -1;

    }
};