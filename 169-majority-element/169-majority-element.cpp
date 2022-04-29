class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int N = nums.size();
        
        int majE;
        int cnt = 0;
        
        for (int i = 0; i < N; i++)
        {
         
            if (cnt == 0) { //not majority ele
                majE = nums[i], cnt = 1;
            }

        
            else {
                (majE == nums[i]) ? cnt++ : cnt--;
            }
        }
 
     return majE;
    }
};