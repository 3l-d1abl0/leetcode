class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
            int N = nums.size();
        
            vector<vector<int> > res;
        
        
            for(int i=0; i< (1<<N); i++){
                
                vector<int> vec;
                for(int j=0; j<N; j++){
                    
                    if(i & (1<<j)){
                        vec.push_back(nums[j]);
                    }
                }
                
                res.push_back(vec);
            }
        
        return res;
    }
};