class Solution {
public:
    
    int justRob(vector<int>& nums) {
     
            int N = nums.size();
        
        
            int prev2 =0, prev1 = 0, curr =0;
            
            for(int i=0; i<N; i++){
                    
                 curr = max(nums[i]+prev2, prev1);
                
                
                prev2 = prev1;
                prev1 = curr;
            }
        
        return curr;
    }
    
        int recMemo(int idx, vector<int> &nums, vector<int> &memo){
        
        if(idx<0)
            return 0;
        
        //IF we reach idx =0, it means we din not take idx=1, since have to maximize sum we include idx=0
        //if(idx==0) return nums[idx];
        
        if(memo[idx]!=-1)
            return memo[idx];
        
        
        //pick/Include
        int inSum = nums[idx]+recMemo(idx-2, nums, memo);
        
        //not pick //exclude
        int exSum = recMemo(idx-1, nums, memo);
        
        
        return memo[idx] = max(inSum, exSum);
        
    }
    
    int bottomUp(int N, vector<int> &nums){
        
        vector<int> dp(N, 0);
        
        for(int i=0; i<N; i++){
            
            int inSum =0, exSum =0;
            
            //pick/Include
                inSum = nums[i]+ ( (i-2>=0)?dp[i-2]:0);
        
            //not pick //exclude
            
                exSum = (i-1>=0)?dp[i-1]:0;
            
            dp[i]=max(inSum, exSum);
            
        }
        
        
        return dp[N-1];
        
        
    }
    
    
    int opti(vector<int> &nums){
        
            int N = nums.size();
        
        
            int prev2 =0, prev1 = 0, curr =0;
            
            for(int i=0; i<N; i++){
            
                    //(include, exclude)
                 curr = max(nums[i]+prev2, prev1);
                
                //prepare previous for the next iteration
                prev2 = prev1;
                prev1 = curr;
            }
        
        return prev1;
        
    }
    
    int rob(vector<int>& nums) {
        /*
        Since it is circular , If you pick the first element,
        you cant pick the last elemetn.
        
        ans is max of the case where you
        pick the first ans exclude the first
        */
        
        if(nums.size()==0) return 0;
        
        if(nums.size()==1) return nums[0];
        
        
        vector<int> noLast (nums.begin(), nums.end()-1);
        vector<int> noFirst (nums.begin()+1, nums.end());
        
        int N = noLast.size();
        
        //recursion +memoization
        //return max(justRob(noLast), justRob(noFirst));
        
        /*vector<int> memo(N, -1);
        vector<int> memo1(N, -1);
        
        return max(recMemo(N - 1, noLast, memo), recMemo(N - 1, noFirst, memo1));
        */
        
        
        //BottomUp -DP - Tabulation
        //return max(bottomUp(N, noLast), bottomUp(N, noFirst));
        
        
        //Space Optimization
        return max(opti(noLast), opti(noFirst));
    }
};