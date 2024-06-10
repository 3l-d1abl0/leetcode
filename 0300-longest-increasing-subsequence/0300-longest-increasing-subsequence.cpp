class Solution {
public:
    
    int smallestAmongGreater(vector<int> &lis, int key){
        
        int left = 0, right = lis.size()-1;
        
        while(right > left+1){
            
            int mid = left + (right-left)/2;
            
            (lis[mid] >= key ? right : left) = mid;
        }
        
        return right;
        
        
    }
    
    int ceilIdx(vector<int> &v, int key){

    int n =v.size();
        
    int l=-1, r=n;
        
    while(r-l>1){

        int mid = l + (r-l)/2;
        if(v[mid]>=key){
            r=mid;
        }else{
            l=mid;
        }
    }

    if(l==-1)
        return r;//0

    return r;
}
    
    int recur(int idx, int prev_idx, vector<int> &nums, vector<vector<int>> &memo){
        
        if(idx== nums.size())
            return 0;
        
        if(memo[idx][prev_idx+1] !=-1){  //+1 coz 
            return memo[idx][prev_idx+1];
        }
        
        
        //exclude /skip
        
        int exce = 0+recur(idx+1, prev_idx, nums, memo);
        
        
        
        int inc = 0;
        if( prev_idx ==-1 || nums[idx] > nums[prev_idx]){
            inc = 1+ recur(idx+1, idx, nums, memo);
        }
        
        
        return memo[idx][prev_idx+1] = max(exce, inc);
        
        
    }
    
    int recurMemo(vector<int>& nums){
        
        int N = nums.size();
        vector<vector<int>> memo(N, vector<int> (N+1, -1));
        
        return recur(0, -1, nums, memo);
    }
    
    
    int method3(vector<int> &nums){
        
        vector<int> lis;
        lis.push_back(nums[0]);
        
        int len =1;
        
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i]<=lis[0])
                lis[0]= nums[i];
            else if(nums[i]>lis[len-1]){
                lis.push_back(nums[i]);
                len++;
            }else{
                //int idx = smallestAmongGreater(lis, nums[i]);
                int idx = ceilIdx(lis, nums[i]);
                lis[idx] = nums[i];
            }
            
            
        }
        
        
        return len;
        
        
    }
    
    
    int method2(vector<int> &nums){
        
        int N = nums.size();
        vector<int> LIS(N, 1);
 
        // Compute optimized LIS values in
        // bottom up manner
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < i; j++){
             
                if (nums[i] > nums[j] && LIS[i] < LIS[j] + 1)
                    LIS[i] = LIS[j] + 1;
                
            }
        }

        // Return maximum value in lis[]
        return *max_element(LIS.begin(), LIS.end());
    }
    
    int lengthOfLIS(vector<int>& nums) {
        
        
        
        /*1. Method 1 - Recur + Memo
        
            TC: O(N^2)
            SC: O(N^2)
        */
        //return recurMemo(nums);
        
        
        
        /*
            2. Method 2 - bottom Up
            
            TC: O(N^2)
            SC: O(N)
        */
        
        //return method2(nums);
        
        
        /*
        3. Method 3 - Binary Search
        */
        
        
        return method3(nums);
    }
};