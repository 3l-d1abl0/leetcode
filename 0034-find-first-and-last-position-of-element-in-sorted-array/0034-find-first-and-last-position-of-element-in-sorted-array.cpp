class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> ans(2, 0);
        
        int N = nums.size();
        
        //ans[0] = findRange(nums, 0, N-1, -1, target, true); //true == look for first index
        ans[0] = findFirst(nums, target);
        if(ans[0]==-1)
            ans[1] = -1;
        else
            ans[1] = findLast(nums, target);
            //ans[1] = findRange(nums, 0, N-1, -1, target, false);
        
        
        return ans;
    }
    

    int findFirst(vector<int> &nums, int target){

            int l=-1, r=nums.size();

            while(r-l>1){
                int mid = l+(r-l)/2;

                if(nums[mid]>=target){
                    r=mid; //go left, find 1st occurance
                }else{
                    l=mid;
                }
            }//while

            if(r==nums.size() || nums[r]!=target)
                return -1;

            return r;
    }

    int findLast(vector<int> &nums, int target){

            int l=-1, r=nums.size();

            while(r-l>1){
                int mid = l+(r-l)/2;

                if(nums[mid]<=target){
                    l=mid; //go right, find last occurance
                }else{
                    r=mid;
                }
            }//while

            if(l==-1 || nums[l]!=target)
                return -1;
                
            return l;
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