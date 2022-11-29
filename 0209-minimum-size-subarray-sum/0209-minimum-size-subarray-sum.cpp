class Solution {
public:
    int twoPointer(int target, vector<int> &nums){
        
                int N = nums.size();
        
        int minLen = 1e9;
        long long sum =0;
        int left=0;
        for(int right=0; right<N; right++){
            
            sum += nums[right];
            
            while(sum>=target){
                minLen = min(minLen, right-left+1);
                sum -= nums[left];
                left++;
                //cout<<minLen<<" ";
            }
        }
        
        
        if(minLen==1e9)
            return 0;
        else
            return minLen;

    }
    
    bool sumOfLength(vector<int> &nums, int target, int len){
        //sliding window
        
        long long sum = 0;
        for(int i=0; i<len; i++){
            sum += nums[i];
        }
        
        int l =0, r= len-1;
        
        while(r!= nums.size()-1){
            
            r++;
            sum += nums[r];
            
            sum -=nums[l];
            l++;
            
            if(target == sum) return true;
        }
        
        return false;
            
    }
    
    int binarySearch(int target, vector<int> &nums){
        
        int l=0, r= nums.size(); //possible length
        bool minLen = false;
        while(l<r){
            
            int mid = l+(r-l)/2;
            //cout<<mid<<endl;
            if(sumOfLength(nums, target, mid)==true){
                r=mid;
                minLen = true;    
                //cout<<"len = "<<mid<<endl;
            }else{
                l=mid+1;
            }
            
        }
        
        
        if(minLen == true)
            return l;
        else return 0;
        
    }
    
    int minSubArrayLen(int target, vector<int>& nums) {
             
        
        return twoPointer(target, nums);
        
        //return binarySearch(target, nums);
        
    }
};