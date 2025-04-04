class Solution {
public:

    int twoPointers(vector<int>& nums, int k){

        int count =0;
        int sum=0;
        for(int lf=0, rt=0; rt<nums.size(); rt++){

            sum+=nums[rt];

            /*
                [-1,-1,1]
                k = 0
                O/P : 1

                The shrinking condiftion doesn't work in this case as,
                we are shringing only when the sum is greater than the required.
                What if therea are -ive nums in array and the sum is less than required,
                in that case we have to shrink/eliminiate window
            */
            while(sum>k && lf<nums.size()){
                sum-=nums[lf];
                lf++;
            }

            if(sum==k && lf<=rt)
                count++;
        }
        return count;
    }
    int subarraySum(vector<int>& nums, int k) {


        //return twoPointers(nums, k);
        
        
        int ans =0, sum=0;
        unordered_map<int, int> mp;
        mp[0]=1;
        for(int ele: nums){
            
            sum +=ele;
            ans += mp[sum-k];
            
            mp[sum]++;
        }
        
        return ans;
    }
};