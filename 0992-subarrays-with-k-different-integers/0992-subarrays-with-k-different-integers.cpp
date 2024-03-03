class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        
    unordered_map<int, int> count;
    //lf -rt
    int subarray =0, lf=0, result =0;
    for(int rt=0; rt<nums.size(); rt++){

        //process the incoming element
        int inc = nums[rt];
        count[inc]++;

        //if distinct elements are > k
        if(count.size() > k){

            //freq of [lf] is always 1
            count.erase(nums[lf]);
            lf++;
            subarray=0;
        }


        if(count.size() ==k){
            //Shrink the window to its min size with distinct ele e =k
            while(count[nums[lf]]>1){

                count[nums[lf]]--;
                subarray++;
                lf++;
            }

            result += (subarray+1);
        }
    }//for


    return result;
        
    }
};