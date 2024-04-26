class Solution {
public: 
    
    bool topDown(int idx, int sum, vector<int> &arr, vector<vector<int>> &memo) {

        if(sum ==0)
            return true;

        if(idx==0)
            return sum == arr[0];

        if(memo[idx][sum]!=-1)
            return memo[idx][sum];

        bool exclude = topDown(idx-1, sum, arr, memo);

        bool include = false;
        if(arr[idx]<=sum)
            include = topDown(idx-1, sum-arr[idx], arr, memo);


        return memo[idx][sum] = exclude | include;
    }
    
    void generateSubsetSum(vector<int> &nums, vector<vector<int>> &left_half, vector<vector<int>> &right_half){
        
        int N = nums.size()/2;
        
        //storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<N); ++mask){
        
            int sz = 0, l = 0, r = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            left_half[sz].push_back(l);
            right_half[sz].push_back(r);
        }//for mask
    }
    
    int meetInTheMiddle(vector<int> &nums){
        
        int N = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        
        int n = N/2;
        
        if(n==1){
            return abs(nums[0]-nums[1]);
        }
        
        vector<vector<int>> left_half(n+1), right_half(n+1);
        
        //  |---------N/2----------| |-----------N/2------------|
        
            //Generate subset sum of various sizes for both half
            generateSubsetSum(nums, left_half, right_half);
        
        
        int min_diff = min(abs(sum-2*left_half[n][0]), abs(sum-2*right_half[n][0])); 
        int half_sum = sum/2;
        
        //return -1;
        for(int k=1; k<n ;++k){
            
            //subsets with size n-k from right half
            //right_half[n-k];
            //sort inorder to to binary search
            sort(right_half[n-k].begin(), right_half[n-k].end());
            
            for(auto &a : left_half[k]){
                
                int rem = half_sum - a;
                //cout<<"rem: "<<rem<<endl;
                
                /*
                for(int ele: right_half[n-k]){
                    cout<<ele<<" ";
                }
                cout<<endl;
                */
                
                // >= rem
                auto it = lower_bound( right_half[n-k].begin(), right_half[n-k].end(), rem); 
                
                if(it!= right_half[n-k].end()){
                    int sum1 = a+(*it);
                    int sum2 = sum - (sum1);
                    min_diff = min(min_diff, abs(sum2-sum1));
                    
                    
                    //min_diff = min(min_diff, abs(sum-2*(a+(*it))));
                    //cout<<min_diff<<endl;
                }
            }//for
        }//for
        

        return min_diff;
    }
    
    int minimumDifference(vector<int>& nums) {
        
        /*
        int sum =0, max_ele=-1;
        for(int ele: nums){
            sum+=ele;
            max_ele = max(max_ele, ele);
        }
        cout<<sum<<endl;
        
        
        int max_sum_poss = max(max_ele, (sum/2)+1);
        vector<vector<int>> memo (nums.size(), vector<int> (max_sum_poss+1, -1));
        
        for(int sm = max_sum_poss; sm>=0; sm--){
            
            if( topDown(nums.size()-1, sm, nums, memo) ){
                cout<<sum<<" "<<sm<<endl;
                return abs((sum-sm)-sm);
            }
        }
        
        return -1;
        
        
        This wont work as generating all subsets will cost around
        2^30, which will lead to TLE
        
        also neagtive sum , will be problematic in Tabulation
        
        
        
        trying meet in the middle
        */
        
        
        return meetInTheMiddle(nums);
    }
};