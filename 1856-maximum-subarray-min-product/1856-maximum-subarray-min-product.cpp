class Solution {
public:
    
    struct Arr{
      
        int lmin;
        int rmin;
    };
    
    void processMin(vector<int> &nums, struct vector<Arr> &vec){
        
        stack<int> st;
        
        for(int i=0; i<nums.size(); i++){
            
            while(!st.empty() && nums[st.top()] > nums[i]){
                //cout<<i<<" "<<st.top()<<endl;
                vec[st.top()].rmin = i - st.top();
                st.pop();
            }
            
            if(!st.empty())
                vec[i].lmin = i - st.top();
            
            st.push(i);
        }
        
    }
    
    int maxSumMinProduct(vector<int>& nums) {
        
        int N = nums.size();
        vector<Arr> vec(N);
        vector<long long int> sum(N);
        
        for(int i=0; i<N; i++){
            
            if(i==0){
                sum[i] = nums[i];
            }else
                sum[i]= sum[i-1]+nums[i];
            
            vec[i].lmin = i+1;
            vec[i].rmin = N-i;
            
          //  cout<<sum[i]<<" ";
        }
        
        
        processMin(nums, vec);
        
        
        int MOD = 1e9+7;
        long long int prod =0;
        
        /*for(int i=0; i<N; i++){
            cout<<vec[i].lmin<<" ";
        }cout<<endl;
        
        for(int i=0; i<N; i++){
            cout<<vec[i].rmin<<" ";
        }cout<<endl;*/
        
        for(int i=0; i<N; i++){
         
            int left_idx  = i-vec[i].lmin+1;
            int right_idx = i+ vec[i].rmin-1;
            
            //cout<<left_idx<<" "<<right_idx<<endl;
            
            long long int sm = sum[right_idx]- (left_idx == 0 ? 0:sum[left_idx-1]);
            
            //cout<<nums[i]<<"*"<<sm<<" = "<<nums[i]*sm<<endl;
            prod = max(prod, nums[i]*sm);
        }
     
        
        return prod%MOD;
    }
};