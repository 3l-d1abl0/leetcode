class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
     
        /*
            Normal:
                Even pos - 1st occur
                Odd pos - 2nd Occur
            Disturbed:
                Odd pos - 1st pos
                Even pos - 2nd pos
                   X  00 ev
             0  1  2  3  4  5  6  7  8
            [1, 1, 2, 3, 3, 4, 4, 8, 8]
        */
            int n=nums.size();
            int low = 0;
            int high = n - 2;
        
            while (low <= high) {
                int mid = (low + high) / 2;
                
                if (mid % 2 == 0) { //first element of the pair is at even index
                    
                    
                    if (nums[mid] != nums[mid + 1]) //Disturbed - the single element is on the left of current mid
                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                } else {
                    //mid is odd
                    if (nums[mid] == nums[mid + 1]) //Disturbed - the single element is on the left of current mid
                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half
                }
            }

            return nums[low];
        
    }
};