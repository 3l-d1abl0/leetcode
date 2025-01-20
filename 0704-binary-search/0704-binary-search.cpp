class Solution {
public:

    int method1(vector<int> &nums, int target){

        int N= nums.size();
        int l =-1, r=N;


        while(r-l>1){

                int mid = l+(r-l)/2;

                if(nums[mid]<=target)
                    l=mid;
                else
                    r=mid;
        }

        if(l==-1 || nums[l]!=target)
            return -1;
        else
            return l;
        
    }

    int search(vector<int>& nums, int target) {

        //Binary Search on Answers
        return method1(nums, target);
        
        int N = nums.size();
        int left =0; int right = N-1;
        
        while(left <= right){
            
            if(left==right){
                if(nums[left]==target)
                    return left;
                else
                    return -1;
            }else{
                
                
                int mid = left + (right-left/2);
                
                if(nums[mid]==target){
                    return mid;
                }else if (nums[mid]<target){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
                
                
            }//else
            
            
        }//while
        
        
        return -1;
        
    }
};