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
        
        //return max(justRob(noLast), justRob(noFirst));
        
        vector<int> memo(N, -1);
        vector<int> memo1(N, -1);
        
        return max(recMemo(N - 1, noLast, memo), recMemo(N - 1, noFirst, memo1));
        
    }
};