class Solution {
public:
    int rev(int num){
        
        int rev_num =0;
        
        while(num!=0){
            rev_num = rev_num*10+num%10;
            num = num /10;
        }
        
        return rev_num;
    }
    
    int countNicePairs(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        int MOD = 1e9+7;
        int cnt =0;
        for(int i=0; i<nums.size(); i++){
            
                int val = nums[i]-rev(nums[i]);
                cnt = (cnt+mp[val])%MOD;
                //cout<<"val = "<<val<<" cnt= "<<cnt<<endl;
                mp[val]++;
        }
                   
        return cnt;
    }
};