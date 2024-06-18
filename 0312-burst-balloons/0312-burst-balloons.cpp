class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        int N = nums.size();
        
        
        vector<vector<int>> dp(N, vector<int>(N, 0));
        
        //loop Window length from len 1 to N
        for(int len=1; len<=N; len++){
            
            
            for(int leftB=0; leftB<=N-len; leftB++){
                
                int rightB = leftB+len-1;
                
                
                for(int k=leftB; k<=rightB; k++){
                
                    int leftValue = 1;
                    int rightValue = 1;
                    
                    if(leftB!=0)
                        leftValue = nums[leftB-1];
                    
                    if(rightB!=N-1)
                        rightValue = nums[rightB+1];
                        
                    int cost = leftValue*nums[k]*rightValue;
                    
                    int leftSubWindow = (k!=leftB)? dp[leftB][k-1]:0;
                    int rightSubWindow = (k!=rightB)? dp[k+1][rightB]: 0;
                    
                    cost+= leftSubWindow+rightSubWindow;
                    
                    dp[leftB][rightB] = max(dp[leftB][rightB], cost);
                }
                
            }//for leftB
        }// len
        
        
        return dp[0][N-1];
        
    }
};