class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        /*2 10 14
        6 8 12
        
        2 2  5
        4   1 3
         */  
            
        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());
        
        int N = nums.size();
        long long int diff =0;
        
        vector<int> eve1, odd1;
        vector<int> eve2, odd2;
        
        for(int i=0; i<N; i++){
            
            if(nums[i]&1){
                odd1.push_back(nums[i]);
            }else{
                eve1.push_back(nums[i]);
            }
            
            if(target[i]&1){
                odd2.push_back(target[i]);
            }else{
                eve2.push_back(target[i]);
            }
            
        }
        
        int O =odd1.size();
        int E = eve1.size();
        
        
        for(int i=0; i<O; i++){
            diff += abs(odd1[i]-odd2[i]);
        }
        
        
        for(int i=0; i<E; i++){
            diff += abs(eve1[i]-eve2[i]);
        }
        
        return diff/4;
    }
};