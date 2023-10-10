class Solution {
public:
    
    int func(vector<int> &nums, int m, int maxSum){
        
        int subS = 1;
        int sum =0;
        for(int ele: nums){
            
            if(ele>maxSum) return INT_MAX;
            
            if(sum+ele<=maxSum){
                sum +=ele;
            }else{
                subS++;
                if(subS > m) return INT_MAX;
                sum = ele;
            }
        }
        return subS;
        //return subS <= m;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int l = *max_element(nums.begin(), nums.end())-1; //when split =m
        int r = accumulate(nums.begin(), nums.end(), 0)+1; //when split =1
        
        
        while(r-l>1){
        
            //mid is the largest sum subarray can have
            //we need to minimize this
            int mid = l+(r-l)/2;
            //predicate : mid <= max sum of a subset
            //calculate how many sub arrays we can make with mid
            /*
                 mid(less)               mid(more)
                  k(more)                k(less)
            
            
            desired split = 850
            maxSum 10  --->>>> split 1000
            maxSum 20 -------> split 950
            maxSum 30 --------> split 900
            maxSum 35 --------> split 900
            maxSum 40 --------> split 850
            maxSum 45 ---------> split 850
            maxSum 50 ---------> split 800
            maxSum 60 ---------> split 750
            
            ANS: 40
            
            If you got the target still go for the minsum /left
            sum 30 -> 900
                30++
                
                
            sum 50 --> 800
                50--
            */
            
            
            //if(func(nums, m, mid)<=m){//it can be divided into <=m subarrays with max subarray sum mid , also there is a chance that it might det divided into m subarrays wth max subarray sum less than mid, as mid dec m inc
              //  r=mid;  //try to go more left so that m increases
               // cout<<"mid :: "<<mid<<endl;
            //}else{
              //  l=mid;
            //}
            
            if(func(nums, m, mid)>m){ //greater go to right, if ypu got split =m still go left and look for smaller Max Sum
                l=mid;
            }else{
                r=mid;
            }
            
        }
        
        
        //cout<<":: "<<l<<" "<<r<<endl;
        
        return r;
        
    }
};