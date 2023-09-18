class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        vector<int> lis(N, 1);
        
        vector<int> path(N, 0);
        for(int i=0; i<N; i++){
            path[i]=i;
        }
        
        
        int maxx_lis = lis[0];
        int start;
        for(int i=1; i<N; i++){
            
            for(int j=0; j<i; j++){
                
                if(nums[i]%nums[j]==0 && lis[i]<lis[j]+1){
                    lis[i] = lis[j]+1;
                    path[i] = j;
                }
                
            }//for j
            
            if(maxx_lis < lis[i]){
                maxx_lis = lis[i];
                start =i;
            }
            
        }//for i
        
        
        vector<int> ans;
        while(start >=0 && path[start] != start){
            
            ans.push_back(nums[start]);
            
            start = path[start];
            
        }
        
        ans.push_back(nums[start]);
        
        
        return ans;
    }
};