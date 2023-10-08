class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2, 0);
        
        int N = nums.size();
        
        ans[0] = findRange(nums, 0, N-1, -1, target, true); //true == look for first index
        
        if(ans[0]==-1)
            ans[1] = -1;
        else
            ans[1] = findRange(nums, 0, N-1, -1, target, false);
        
        
        return ans;
    }
    
    
    int findRange(vector<int> nums, int st, int ed, int prevFound, int target, bool firstIdx){
        
        if(st<=ed){
            
            int mid = st +(ed-st)/2;

            if(nums[mid] == target ){
                prevFound =mid;
                
                
                if(firstIdx){
                    return findRange(nums, st, mid-1, prevFound, target, firstIdx);
                }else{
                    return findRange(nums, mid+1, ed, prevFound, target, firstIdx);
                }
                
            }else{
                
                if(target< nums[mid])
                    return findRange(nums, st, mid-1, prevFound, target, firstIdx);
                else
                    return findRange(nums, mid+1, ed, prevFound, target, firstIdx);
                
            }
            
            
        }//if
        
        
        return prevFound;
    }
    
};