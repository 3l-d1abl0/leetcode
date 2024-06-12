class Solution {
public:

    
    int method1(vector<int> &arr, int n){

        /* Allocate memory for LIS[] and initialize LIS values as 1 for
          all indexes */
        vector<int> lis(n,1);

       /* Compute LIS values from left to right */
       for (int i = 1; i < n; i++)
          for (int j = 0; j < i; j++)
             if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

       /* Allocate memory for lds and initialize LDS values for
          all indexes */
        vector<int> lds(n, 1);

       /* Compute LDS values from right to left */
       for (int i = n-2; i >= 0; i--)
          for (int j = n-1; j > i; j--)
             if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;


       /* Return the maximum value of lis[i] + lds[i] - 1*/
       int maxx = 0;
       for (int i = 1; i < n-1; i++){

           if(lis[i]>1 && lds[i]>1)
             maxx = max( maxx, lis[i] + lds[i] - 1);
       }

       return n-maxx;

    }

    int ceilIdx(vector<int> &lis, int key){
        
        if(lis.size()==0)
            return 0;
        
        int left = 0, right = lis.size()-1;
        
        while(right > left+1){
            
            int mid = left + (right-left)/2;
            
            (lis[mid] >= key ? right : left) = mid;
        }
        
        return right;
        
        
    }
    
    
    int method2(vector<int> &nums,int n ){
    
        vector<int> l;
        l.push_back(nums[0]);
        int len =1;
        
        vector<int> dp1(n, 0);
        dp1[0] =len;
        
        //LIS   
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i]<=l[0])
                l[0]= nums[i];
            else if(nums[i]>l[len-1]){
                l.push_back(nums[i]);
                len++;
            }else{
                //int idx = smallestAmongGreater(lis, nums[i]);
                int idx = ceilIdx(l, nums[i]);
                l[idx] = nums[i];
            }
            
            dp1[i] =len;
        }
        
        
        vector<int> r;
        r.push_back(nums[n-1]);
        len =1;
        vector<int> dp2(n, 0);
        dp2[n-1] = len;
        
        //LDS 
        for(int i=n-2; i>=0; i--){
            
            if(nums[i]<=r[0])
                r[0]= nums[i];
            else if(nums[i]>r[len-1]){
                r.push_back(nums[i]);
                len++;
            }else{
                //int idx = smallestAmongGreater(lis, nums[i]);
                int idx = ceilIdx(r, nums[i]);
                r[idx] = nums[i];
            }
            
            dp2[i] =len;
        }
        

        /* Return the maximum value of lis[i] + lds[i] - 1*/
       int maxx = 0;
    
       //cout<<dp1[0]<<", "<<dp2[0]<<endl;
       for (int i = 1; i < n-1; i++){

           //cout<<dp1[i]<<" "<<dp2[i]<<endl;
           
           if(dp1[i]>1 && dp2[i]>1)
             maxx = max( maxx, dp1[i] + dp2[i] - 1);
       }
        
        //cout<<dp1[n-1]<<", "<<dp2[n-1]<<endl;
        
        
        return n-maxx;
    }
    
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        /*
            Compute the length of the longest Bitonic Subsequence
            subtract from N
        
        */
        
        int N = nums.size();
        
        //
        return method1(nums, N); //O(n^2)
        
        return method2(nums, N); //O(2NlonN + N)
    }
};