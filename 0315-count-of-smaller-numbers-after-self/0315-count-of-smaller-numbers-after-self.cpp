class Fenwick{
    
    vector<int> BIT;
    int N;
    public:
    
    Fenwick(int n){
        BIT = vector<int> (n + 1);
        N = n+1;
    }
    
    void update(int idx, int val){
        
        for(idx=idx+1; idx<N; idx+=(idx & -idx))
            BIT[idx]+=val;
    }
    
    long long int sum(int idx){

        long long sum =0;
        for(idx=idx+1; idx>0; idx -= (idx & -idx)){
            sum +=BIT[idx];
        }
        return sum;
    }
    
};

class Solution {
public:
    
    vector<int> method1(vector<int> &nums){
        
        int N = nums.size();
        vector<int> table;
        vector<int> ans(N, 0);
        
        
        for(int i=N-1; i>=0; i--){
            
            int idx= lower_bound(table.begin(), table.end(), nums[i]) - table.begin();
            ans[i] = idx;
            
            table.insert(table.begin()+idx, nums[i]);
        }
        
        
        return ans;
        
    }
    
    vector<int> method2(vector<int> &nums){
        
        int offset = 1*1e4+2;
        Fenwick *BIT = new Fenwick(2*offset);
        
        
        int N = nums.size();
        vector<int> ans(N, 0);
        
        BIT->update(offset+ nums[N-1], 1);
        
        for(int i=N-2; i>=0; i--){
            
            ans[i] = BIT->sum(offset+nums[i]-1);
            
            BIT->update(offset+nums[i], 1);
        }
        
        
        return ans;
        
    }
    
    
    vector<int> countSmaller(vector<int>& nums) {
        
        //Binary Search - O(N*(longN+ N)) TLE
        //return method1(nums);
        
        
        //Fenwick Tree
        return method2(nums);
        
    }
};