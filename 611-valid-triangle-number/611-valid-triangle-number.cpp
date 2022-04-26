class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //a+b > k
        
        int N = nums.size();
        sort(nums.begin(), nums.end());
        int count =0;
        for(int k = N-1; k>=1; k--){
            
            int a = 0, b=k-1;
            
            while(a<b){
                
                if(nums[a]+nums[b]>nums[k]){
                    count += b-a;
                    b--;
                }else{
                    a++;
                }
                
            }
            
            
        }//for
        
        
        return count;
    }//int
};