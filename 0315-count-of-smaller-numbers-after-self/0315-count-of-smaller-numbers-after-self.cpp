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
            
            //binary - search - log(n)
            int idx= lower_bound(table.begin(), table.end(), nums[i]) - table.begin();
            ans[i] = idx;
            //insert - linear - n
            table.insert(table.begin()+idx, nums[i]);
        }// O(N+log(N))
        
        
        return ans;
        
    }
    
    vector<int> method2(vector<int> &nums){
        
        int offset = 1*1e4+2;//10002
        Fenwick *BIT = new Fenwick(2*offset);
        
        
        int N = nums.size();
        vector<int> ans(N, 0);
        
        BIT->update(offset+ nums[N-1], 1);
        
        for(int i=N-2; i>=0; i--){
            
            ans[i] = BIT->sum(offset+nums[i]-1);    //(0, num-1)
            
            BIT->update(offset+nums[i], 1);
        }
        
        
        return ans;
        
    }
    

    class SegmentTree{

        int n;  //range size [0 - n-1]
        int segSize;    //size of segment tree
        vector<int> st;

        int nextPowOfTwo(int sz){
            return pow(2, ceil(log(sz) / log(2)));
        }

        public:
        SegmentTree(int n){

            this->n=n;
            this->segSize = 2*nextPowOfTwo(n)-1;
            // cout<<"array Size:: "<<n<<endl;
            // cout<<"Size Seg:: "<<this->segSize<<endl;
            this->st.resize(this->segSize, 0);
        }

        //void build(){}

        void update(int idx, int val){
            //cout<<"UPDATE:: "<<idx<<"::"<<val<<endl;
            //tree_idx, tree_range_start, tree_range_end, source_idx, new_source_value
            update( 0, 0, this->n-1, idx, val);
        }

        void update(int idx, int rangeStart, int rangeEnd, int sourceIdx, int newVal){
        
            //Base Case - reached root node in the tree, by condition we will reach the root node where the sourceIdx is.
            if(rangeStart==rangeEnd){
                this->st[idx] += newVal;
                return;
            }

            int mid = (rangeStart+rangeEnd)/2;

            if(sourceIdx<=mid){   //if sourceIdx lies between [0-mid] 
                update(2*idx+1, rangeStart, mid,  sourceIdx, newVal);
            }else{
                update(2*idx+2, mid+1, rangeEnd, sourceIdx, newVal);
            }

            //update the Ranges
            this->st[idx] = this->st[2*idx+1]+this->st[2*idx+2];

            return;
        }
        
        int query(int l, int r){
            //seg_tree_index, tree_range_start, tree_range_end, query_left, query_right
            //cout<<"Querying: "<<l<<" "<<r<<endl;
            return query(0, 0, this->n-1, l, r);
        }

        int query(int idx, int rangeStart, int rangeEnd, int queryLeft, int queryRight){

            //1. non overlapping - both boundaries are apart
            if(queryRight<rangeStart || rangeEnd<queryLeft){
                return 0;
            }

            //2. complete overlap - query range engulfs thhe tree Range , the Segment range falls within query range
            if(queryLeft<=rangeStart && rangeEnd <=queryRight)
                return this->st[idx];

            //3. partial overlapp
            int mid = (rangeStart+rangeEnd)/2;
            int q1 = query(2*idx+1, rangeStart, mid, queryLeft, queryRight);
            int q2 = query(2*idx+2, mid+1, rangeEnd, queryLeft, queryRight);
            
            //Returbn the Summation of its range
            return q1+q2;
        }

    };


    vector<int> method3(vector<int> & nums){
        //[-10^4 , 10^4]

        int offset = 1e4;
        int n = 2*offset+2;

        int N = nums.size();
        vector<int> ans(N, 0);

        /*  [-4, 4], 9 elements
            offset = 4
            n = 10,     0-9 (10 elemets)
         */

        SegmentTree *segTree = new SegmentTree(n);  //no need to build since all the count is zero initially
        segTree->update(offset+nums[N-1], 1);   //add 1 to the rightmost element

        for(int i=N-2; i>=0; i--){
            //cout<<"i= "<<i<<endl;
            ans[i] = segTree->query(0, offset+nums[i]-1);
            segTree->update(offset+nums[i], 1);
        }//for

        return ans;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        
        //1. Binary Search + array resize - O(N*(longN+ N)) 1699 ms
        //return method1(nums);
        
        
        //2. Fenwick Tree
        //return method2(nums);

        //3. Segement Tree
        return method3(nums);
        
    }
};