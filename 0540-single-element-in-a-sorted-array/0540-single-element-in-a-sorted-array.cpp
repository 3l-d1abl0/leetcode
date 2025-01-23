class Solution {
public:

    int method2(vector<int> &arr){

        int n = arr.size(); //size of the array.

        //Edge cases:
        if (n == 1) return arr[0];
        if (arr[0] != arr[1]) return arr[0];
        if (arr[n - 1] != arr[n - 2]) return arr[n - 1];

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            //if arr[mid] is the single element:
            if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
                return arr[mid];
            }

            //we are in the left:
            if ((mid % 2 == 1 && arr[mid] == arr[mid - 1])
                    || (mid % 2 == 0 && arr[mid] == arr[mid + 1])) {
                //eliminate the left half:
                low = mid + 1;
            }
            //we are in the right:
            else {
                //eliminate the right half:
                high = mid - 1;
            }
        }

        // dummy return statement:
        return -1;

    }

    int singleNonDuplicate(vector<int>& nums) {

        return method2(nums);
     
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
                    
                    
                    if (nums[mid] == nums[mid + 1]) //Disturbed - the single element is on the right of current mid
                        low = mid + 1; //Shrinking the left half
                    else
                        high = mid - 1; //Shrinking the right half,  mid is the second element in the Pair
                } else {
                    //mid is odd
                    if (nums[mid] == nums[mid + 1]) //Disturbed - the single element is on the left of current mid
                        high = mid - 1; //Shrinking the right half
                    else
                        low = mid + 1; //Shrinking the left half, mid is the second element in the Pair
                }
            }
            
            //cout<<nums[low]<<" "<<nums[high];
            return nums[low];
        
    }
};