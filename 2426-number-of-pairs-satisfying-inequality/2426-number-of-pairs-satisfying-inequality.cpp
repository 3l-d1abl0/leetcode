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
    
    long long method1(vector<int> &nums1, vector<int> &nums2, int diff){
        
        int offset = 3*1e4+5;
        
        Fenwick *BIT = new Fenwick(2*offset);
        
        
        BIT->update(offset+ nums1[0]-nums2[0], 1);
        
        int N = nums1.size();
        long long int pairs =0;
        for(int i=1; i<N; i++){
            
            pairs +=BIT->sum(offset+nums1[i]-nums2[i]+diff);
            
            BIT->update(offset+ nums1[i]-nums2[i], 1);
        }
        
        return pairs;
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        
        return method1(nums1, nums2, diff);
        
    }
};