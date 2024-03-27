class Solution {
    private:
    //Randomized Quick Select - gives better performance than normal quick select
    int partition(vector<int> &arr, int st, int ed){

        int n= ed-st+1;
        int piv = rand() % n;
        
        swap(arr[st + piv], arr[st]);
        int partIdx = st;

        int l = st, r = ed;

        while(l<r){

            while(l<=ed && arr[l]<=arr[partIdx]) l++;

            while(r>=st && arr[r]>arr[partIdx]) r--;

            if(l<r)
                swap(arr[l],arr[r]);
        }


        swap(arr[partIdx], arr[r]);


        return r;

    }

    int kthLargest(vector<int> &arr, int k, int st, int ed){

        int n = arr.size()-1;
        int kth = n-(k-1);
        while(st<=ed){

            int idx = partition(arr, st, ed);

            if(idx ==kth){
                return arr[idx];
            }else if(idx <kth ){
                return kthLargest(arr, k, idx+1, ed);
            }else{
                return kthLargest(arr, k, st, idx-1);
            }

        }
        
        
        return -1;
    }
    
    int method1(vector<int>& arr, int K) {
        
        	priority_queue<int, vector<int> , greater<int> > minHeap(arr.begin(), arr.begin()+K);

            //for(int i=0; i<K; i++){
                //minHeap.push(arr[i]);
            //}

            for(int idx =K; idx <arr.size(); idx++){
                if(arr[idx]>minHeap.top()){
                    minHeap.pop();
                    minHeap.push(arr[idx]);
                }
            }


            return minHeap.top();
        
    }
    
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        /*
            1. Method1: Use Min heap
            TC: O(K) + O((N-K)*logK)
        */
        return method1(nums, k);
        
        
        /*
            2. Method2 : User Selection Sort
            Basically hoping the pivot lands on the Kth element
            Best: O(N)
            Avg: O(NlogN)
            Worst: O(N^2)
        */
        int n = nums.size();
        //return kthLargest(nums, k, 0, n-1);
        
    }
};