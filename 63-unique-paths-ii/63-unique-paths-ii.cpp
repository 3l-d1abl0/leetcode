class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
     
        
        int M = obstacleGrid.size();
        int N = obstacleGrid[0].size();
        
        vector<vector<int>> dp(M, vector<int>(N, 0));
        
        if(obstacleGrid[0][0]==1)
            return 0;
            //dp[0][0] =0;
        else
            dp[0][0]=1;
            
        //first row will have 1 if it can be reached, 0 if there was an obstacle befre any column
        for(int i=1; i<N; i++){
            
            if(obstacleGrid[0][i]==1)
                dp[0][i] = 0;
            else
                dp[0][i]= dp[0][i-1];
        }
        
        for(int j=1; j<M; j++){
            
            if(obstacleGrid[j][0]==1)
                dp[j][0] = 0;
            else
                dp[j][0]= dp[j-1][0];
        }
        
        
        for(int i=1; i<M; i++){
            
            for(int j=1; j<N; j++){
                
                //cout<<dp[i-1][j]+dp[i][j-1]<<" ";
                //cout<<obstacleGrid[i][j]<<" ";
                
                if(obstacleGrid[i][j] ==1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                
            }
            //cout<<endl;
        }
        
        //print(obstacleGrid);
        return dp[M-1][N-1];
    }
    
    void print(vector<vector<int>> &dp){
        
        for(auto row: dp){
            
            for(int ele: row){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
};