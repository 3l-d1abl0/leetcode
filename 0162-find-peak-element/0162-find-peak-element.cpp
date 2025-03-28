class Solution {
public:
    
    int BS(vector<int> &nums, int st, int ed){
        
        if(st<ed){
            
            int mid = st +(ed-st)/2;
            
            if(nums[mid] > nums[mid+1]){
                return BS(nums, st, mid);
            }else{
                return BS(nums, mid+1, ed);
            }
            
        }
        
        return st;
    }
    
    
    int BSItr(vector<int> &nums, int st, int ed){
        
        int l=0, r= nums.size()-1;
        
        while(l<=r){
            
            int mid = l +(r-l)/2;
            
            if(nums[mid]>nums[mid+1]){ //descending
                r=mid;
            }else{
                l=mid+1;
            }
            
        }
        
        return l;
    }
    
    int method1(vector<int> &arr){
            //return any peak
            int n = arr.size(); //Size of array.

            /*
                Search space 1 - N-1
            */
            // Edge cases:
            if (n == 1) return 0;
            if (arr[0] > arr[1]) return 0;  //0 is the peak
            if (arr[n - 2] < arr[n - 1]) return n - 1;  //n-1 is peak
        
        
            int low = 1, high = n - 2;
            while (low <= high) {
                int mid = (low + high) / 2;

                //If arr[mid] is the peak:
                if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                    return mid;

                // Increasing slope
                if ( arr[mid - 1] < arr[mid]){
                    //mid could be a peak, or we can find a another peak

                    low = mid + 1;
                }else{
                    //mid-1 > mid , mid-1 can be a peak, or find another peak
                    high = mid - 1;
                }
            }
            
        // Dummy return statement        
        return -1;
    }
    
    int method2(vector<int> &nums){

        int l = -1, r= nums.size();

        while(r-l>2){

                int mid = l+(r-l)/2;

                if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
                    return mid;
                
                if(nums[mid-1]<nums[mid])
                    l=mid;
                else
                    r=mid;
        }

        cout<<l<<" "<<r<<endl;

        return r;
    }

    int findPeakElement(vector<int>& nums) {
        
        int st =0; int ed = nums.size()-1;
        
        
        //return BS(nums, st, ed);
        //return BSItr(nums, st, ed);
        
        return method1(nums);

        //trying ON ANswers
        return method2(nums);
    }
};