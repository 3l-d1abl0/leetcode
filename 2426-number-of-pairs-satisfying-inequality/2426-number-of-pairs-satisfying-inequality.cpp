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

class SegmentTree{

    private:
        vector<int> st;
        int N;
    public:

    SegmentTree(int n){
        this->N = n;
        st.resize(4*N, 0);
    }

    void build(int start, int ending, int node, vector<int> &v){

        if(start==ending){
            st[node] = v[start];
            return;
        }

        int mid = (start+ending)/2;
        
        //leftSubtree
        build(start, mid, 2*node+1, v);

        //rightSubtree
        build(mid+1, ending, 2*node+2, v);

        st[node] = st[2*node+1]+st[2*node+2];
    }

    void build(vector<int> &v){
        build(0, N-1, 0, v);
    }

    int query(int start, int ending, int l, int r, int node){
        //non overlapping
        if(ending<l || start >r){
            return 0;
        }

        //complete overlap- ql start ending qr
        if(l<=start && ending <=r)
            return st[node];

        //partial overlapp
        int mid = (start+ending)/2;
        int q1 = query(start, mid, l, r, 2*node+1);
        int q2 = query(mid+1, ending, l, r, 2*node+2);
        
        return q1+q2;
    }

    int query(int l, int r){
        return query(0, N-1, l, r, 0);
    }

    void update(int start, int ending, int node, int idx, int val){
        //start case
        if(start==ending){
            st[node]++;
            return;
        }

        int mid = (start+ending)/2;
        if(idx<=mid){
            update(start, mid, 2*node+1, idx, val);
        }else{
            update(mid+1, ending, 2*node+2, idx, val);
        }

        st[node] = st[2*node+1]+st[2*node+2];

        return;
    }

    void update(int idx, int val){
        update(0, N-1, 0, idx, val);
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
    
    long long method2(vector<int> &nums1, vector<int> &nums2, int diff){
        
        int offset = 3*1e4+5;
        
        SegmentTree tree(2*offset);
        tree.update(offset+ nums1[0]-nums2[0], 0);
        
        int N = nums1.size();
        long long int pairs =0;
        for(int i=1; i<N; i++){
            
            pairs += tree.query(0, offset+nums1[i]-nums2[i]+diff);
            tree.update(offset+ nums1[i]-nums2[i], 0);
        }
        
        return pairs;
        
    }
    
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        //Fenwick Tree
        //return method1(nums1, nums2, diff);
        
        //Segment Tree
        return method2(nums1, nums2, diff);
        
    }
};