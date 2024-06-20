class Solution {
public:
    
    int method1(vector<int> &nums){
        
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
    
    
    int recurMemo(int leftb, int rightb, vector<int> &nums, vector<vector<int>> &memo){
        
        if(leftb==0 || leftb==nums.size()-1)
            return 0;
        
        if(rightb==0 || rightb==nums.size()-1)
            return 0;
        
        if(leftb>rightb)
            return 0;
        
        if(memo[leftb][rightb]!=-1)
            return memo[leftb][rightb];
        
        int maxPoints = INT_MIN;    
        //the bulloon candidate for this level
        for(int i=leftb; i<=rightb; i++){
            
            int cost = nums[leftb-1]* nums[i]* nums[rightb+1];
            
            int rem = recurMemo(leftb, i-1, nums, memo)+cost+recurMemo(i+1, rightb, nums, memo);
            
            
            maxPoints = max(maxPoints, rem);
        }
        
        
        return memo[leftb][rightb] = maxPoints;
    }
    
    int recur(vector<int> &nums){
        
        
        int N = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>> memo(N + 2, vector<int>(N + 2, -1));
        
        //ledtb, rightb , arr   
        return recurMemo(1, N, nums, memo);
    }
    
    int maxCoins(vector<int>& nums) {

        //1. Method1 - recristion memo
        return recur(nums);
        
        //DP
        //return method1(nums);        
    }
};