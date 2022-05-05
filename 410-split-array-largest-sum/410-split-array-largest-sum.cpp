class Solution {
public:
    
    int func(vector<int> &nums, int m, int maxSum){
        
        int subS = 1;
        int sum =0;
        for(int ele: nums){
            
            //if(ele>maxSum) return false;
            
            if(sum+ele<=maxSum){
                sum +=ele;
            }else{
                subS++;
                //if(subS > m) return false;
                sum = ele;
            }
        }
        return subS;
        //return subS <= m;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int l = *max_element(nums.begin(), nums.end())-1;
        int r = accumulate(nums.begin(), nums.end(), 0)+1;
        
        
        while(r-l>1){
        
            
            int mid = l+(r-l)/2;
            //predicate : mid <= max sum of a subset
            //int minMaxSum = ;
            if(func(nums, m, mid)<=m){//it can be divided into m subarrays with max subarray sum mid , also there is a chance that it might det divided into m subarrays wth max subarray sum less than mid
                r=mid;  //try to go more left
               // cout<<"mid :: "<<mid<<endl;
            }else{
                l=mid;
            }
            
        }
        
        //cout<<":: "<<l<<" "<<r<<endl;
        
        return r;
        
    }
};