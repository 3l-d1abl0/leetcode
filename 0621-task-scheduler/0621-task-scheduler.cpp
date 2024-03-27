struct CompareFn{
    
    bool operator()(pair<char, int> &a, pair<char, int> &b){
        return a.second < b.second; //Max Frequency First, descending
    }
    
};

class Solution {
public:
    
    int method1(vector<char> &tasks, int n){
       /*
        if n=2
        A__A - There is a Batch of if Size n+1 cycles, only after n+1 terms any character can be repeated
        
        pick (n+1) characters (at max) from the Heap
        
        put them in a Wait Q.
        pick each ele in waitQ , subtract their freq and add them back to the heap
        
        if the heap is empty, no more elements to process
        > the cycle might no thave been completerd
        
        if heap is not empty 
        > full cycle has been completed
       
       */ 
        
        unordered_map<char, int> freq;
        for(char ch: tasks)
                freq[ch]++;
        
        //Create a maxHeap of all tasks, element with max freq is at Top.
        priority_queue< pair<char, int>, vector<pair<char, int>> , CompareFn > maxH (freq.begin(), freq.end());
        
        int cycle = n+1;
        int ans =0;
        
        while(!maxH.empty()) {
            
            
            int time =0;
            queue< pair<char, int> > waitQ;
            
            //process n+1 elements from Heap asn push them to waitQ - Fill a Batch
            for(int i=1; i<=cycle && !maxH.empty(); i++){
                
                //if(!maxH.empty()){
                    waitQ.push(maxH.top());
                    maxH.pop();

                    time++;
                //}
                
            }
            
            //clear the waiting Queue
            while(!waitQ.empty()){
                auto front = waitQ.front();
                waitQ.pop();
                
                //decrease a the freq by 1 asn push it back on Heap
                if(--front.second > 0){
                    maxH.push(front);
                }
            }
            
            
            /*
            If heap is empty , time will give the count of elements processed in this bacth.
            Otherwise ente n+1 cycle was processed in the4Batch
            */
            ans += !maxH.empty() ? cycle : time;
        }//while
        
        
        return ans;
        
    }
    
    int method2(vector<char> &tasks, int n){ 
        
        
        /*  n - cooling time
            1 2 3 4 5 6 ... n n+1
            1 2 3 4 5 6 ... n n+1
        */
        
        
        unordered_map<char, int> mp;
        int maxFreq = 0;
        //Get the frequency of each Task
        for(char ch:tasks){
            mp[ch]++;
            maxFreq = max(maxFreq, mp[ch]);
        }
        
        //Calculate for 1 less batch
        int maxCycles = (n+1) *(maxFreq-1);
        
        /*
        number of task which has the feq,
        same as maxFreq will contribute to
        1 more cycle
        */
        for(auto ele: mp)
            if(maxFreq == ele.second)
                maxCycles++;
        
        //For cases where n ==1
        return max((int)tasks.size(), maxCycles);
        
        
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        
        //K - max Freq 
        
        //1. method1 - O((n+1)(k)log(26))
        return method1(tasks, n);
        
        //2. method2 - O(N)
        //return method2(tasks, n);
    }
};