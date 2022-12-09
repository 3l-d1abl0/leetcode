class Solution {
public:
    
    int method1(vector<int> &A, int k){
        
        int n = A.size();
        int result = 0;
        unordered_map<int, int> hash;
        unordered_map<int, int> done;
        for(int i = 0; i < n; i++) {
            if(hash[A[i] - k] != 0 && hash[A[i]] == 0) {
                result += 1;
            }
            else if(k == 0) {
                if(hash[A[i]] == 1 && !done[A[i]]) {
                    result += 1;
                    done[A[i]] = 1;
                }
            }
            hash[A[i]]++;
        }
        return result;
        
    }
    
    int findPairs(vector<int>& nums, int k) {
        
        
        sort(nums.begin(), nums.end());
        
        return method1(nums, k);
        int N = nums.size();
        
        int i=0, j=1;
        
        
        int ctr=0;
        while(j<N){
            
            //skip same elements
            while(j < (N-1) && nums[j]==nums[j+1]){
                j++;
            }
            
            int diff = abs(nums[j]- nums[i]);
            
            if(diff==k){
                ctr++;
                
                i++, j++;
            }else if(diff < k){
                j++;
            }else{
                i++;
            }
            
            if (i == j)
			    j++;
		
            
        }
        
        
        return ctr;
    }
};