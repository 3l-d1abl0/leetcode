class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        
        int N = nums.size();
        
        vector<int> l(N);
        vector<int> r(N);
        
        l[0]= nums[0];
        r[N-1]= nums[N-1]; 
        for(int i=1; i<N-1; i++){
            l[i] = l[i-1]*nums[i];
            r[N-i-1] = r[N-i]* nums[N-i-1];
        }
        l[N-1] = l[N-2]*nums[N-1];
        r[0] = r[1]*nums[0];
        
        /*for(int i=0; i<N; i++){
            cout<<l[i]<<" ";
        }cout<<endl;
        
        for(int i=0; i<N; i++){
            cout<<r[i]<<" ";
        }cout<<endl;*/
        
        vector<int> ans;
        for(int i=0; i<N; i++){
            int lidx = i-1;
            int ridx = i+1;
            ans.push_back((lidx<0?1:l[lidx]) * (ridx>N-1?1:r[ridx]));
        }
        
        
        return ans;
    }
};