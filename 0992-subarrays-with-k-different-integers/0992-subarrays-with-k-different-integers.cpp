class Solution {
public:
    
    int slidingWiondow3pointer(vector<int> &nums, int k){
        
        int lf=0, rt=0, mid=0;
        int result =0;
        unordered_map<int, int> count;
        
        for(int rt=0; rt<nums.size(); rt++){
            
            //include
            count[nums[rt]]++;
            
            //>= characters
            while(count.size() >k){
                
                count[nums[mid]]--;
                
                if(count[nums[mid]]==0)
                    count.erase(nums[mid]);
                
                mid++;
                lf=mid;
            }//while
            
            
            //If its equal to k , squeeze it
            if(count.size() ==k){
                
                while(count[nums[mid]] >1){
                    count[nums[mid]]--;
                    mid++;
                }
                
                
                result += (mid-lf+1);
            }
        
            
        }//for
        
        
        return result;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        //1. 3 pointer
        return slidingWiondow3pointer(nums, k);
        
    /*
        Idea is to find the smallest window with distinct ele k .
        Whenever the distinct ele == k , shrink the window from left
        
        all the preceding elements from left will make subarray with 
        the current min size window.
        
        Once the distcount becomes > k
        create an new windo  by movein left by 1
        as [left] freq wil lalways be one as we are maintaining
        smallest window - and the subarray will reset to zero.
        
        
    
    */
        
        
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
            
            //subarray =1;
            cout<<subarray<<" :: "<<endl;
            //Shrink the window to its min size with distinct ele e =k
            while(count[nums[lf]]>1){

                count[nums[lf]]--;
                subarray++;
                lf++;
            }

            result += (subarray+1);
            cout<<rt<<":: "<<subarray<<" "<<result<<endl;
        }
        
        //result += (subarray);
        
    }//for


    return result;
        
    }
};