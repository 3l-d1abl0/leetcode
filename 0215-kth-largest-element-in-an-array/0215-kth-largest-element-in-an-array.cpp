class Solution {
    private:
    //Randomized Quick Select - gives better performance than normal quick select
    int partition(vector<int> &arr, int st, int ed){

        //......[st ... ed]....
        
        int n= ed-st+1;//number of elements
        int piv = rand() % n;   //0-n-1
        
        //pull the pivot in the start
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

    int kthLargest(vector<int> &data, int k, int start, int end){

        if (start >= end) return data[start];
        
        int rng = (rand() % (end-start+1) ) + start;
        swap(data[rng], data[end]);
        
        auto pv = data[end];
        int i = start;
        int j = start;
        while (i < end) {
            if (data[i] > pv) {
                swap(data[i++], data[j++]);
            } else {
                ++i;
            }
        }
        swap(data[j], data[end]);
        
        int num = j - start + 1;
        if (num == k)
            return data[j];
        else if (num < k) {
            return kthLargest(data, k-num, j + 1, end);
        } else {
            return kthLargest(data, k, start, j - 1);
        }
        
        
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
        //return method1(nums, k);
        
        
        /*
            2. Method2 : User Selection Sort
            Basically hoping the pivot lands on the Kth element
            Best: O(N)
            Avg: O(NlogN)
            Worst: O(N^2)
        */
        int N = nums.size();
        return kthLargest(nums, k, 0, N-1);
        
    }
};