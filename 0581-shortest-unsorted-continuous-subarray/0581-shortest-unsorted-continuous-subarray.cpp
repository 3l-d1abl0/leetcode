class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        
        int N = nums.size();

        //1. check for pattern break from left
        int i=0;
        while(i<N-1){
            //i <i+1
            if (nums[i] >nums[i+1])
                break;
            i++;
        }

        if(i==N-1) //sorted
            return 0;

        int leftB = i;
        
        //2. Check for pattern Break from Right
        i=N-1;
        while(i>0){
            //i>i-1
            if(nums[i]<nums[i-1])
                break;
            
            i--;
        }

        int rightB = i;
        
        //3. find max and min int the rnage
        int minn = INT_MAX, maxx = INT_MIN;

        for(int i=leftB; i<=rightB; i++){

            minn = min(minn, nums[i]);
            maxx = max(maxx, nums[i]);
        }//for

        
        //4. Find >minn to the left of leftB
        for(int i=0; i<leftB; i++){
            if(nums[i]>minn){
                leftB = i;
                break;
            }
        }

        
        //5.find <maxx to the right of rightB
        for(int i=N-1; i>rightB; i--){
            if(nums[i]<maxx){
                rightB=i;
                break;
            }
        }

        return rightB-leftB+1;
        
        
    }
};