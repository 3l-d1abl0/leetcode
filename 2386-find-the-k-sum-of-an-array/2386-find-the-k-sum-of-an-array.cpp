class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        
        
        int N = nums.size();
        sort(nums.begin(), nums.end(), [](int a, int b){  return abs(a)<abs(b);  });
        
        long long int mxSum =0;
        for(int ele: nums){
            
            mxSum += max(ele, 0); //sum of onlu pos elements
        }
        
        priority_queue<pair<long long int, int>> pq;
        
        
        pq.push({mxSum-abs(nums[0]), 0});
        k--;
        
        while(k--){
            
            auto [sum, i] = pq.top();
            pq.pop();
            
            
            mxSum = sum;
            //cout<<ans<<endl;
            if(i+1<N){
                
                pq.push({sum + abs(nums[i]) - abs(nums[i+1]), i+1});
                
                pq.push({sum-abs(nums[i+1]), i+1});
            }
        }
        
        
        return mxSum;
    }
};