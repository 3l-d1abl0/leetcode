class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums;
        
        sort(nums.begin(), nums.end());
        
        int N = nums.size();
        vector<int> lis(N, 1);
        
        vector<int> path(N, 0);
        for(int i=0; i<N; i++){
            path[i]=i;
        }
        
        
        int maxx_lis = lis[0];
        int start=0;
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
        
        
        
        cout<<maxx_lis<<" "<<start<<endl;
        //return {};
        
        
        vector<int> ans;
        //ans.push_back(nums[start]);
        while(path[start] != start){
            ans.push_back(nums[start]);
            start = path[start];
            
            
        }
        
        ans.push_back(nums[start]);
        
        
        return ans;
    }
};