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
    
    int ceilIdx(vector<int> v, int key){

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
    
    
    int lengthOfLIS(vector<int>& nums) {
        
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
};