struct CompareFn{
    
    bool operator()(pair<char, int> &a, pair<char, int> &b){
        return a.second < b.second; //Max Frequency First
    }
    
};

class Solution {
public:
    
    int method1(vector<char> &tasks, int n){
       /*
        if n=2
        A__A - There is a Cycle of if Size n+1, obly after n+1 terms any character can be repeated
        
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
        
        priority_queue< pair<char, int>, vector<pair<char, int>> , CompareFn > maxH (freq.begin(), freq.end());
        
        int cycle = n+1;
        int ans =0;
        
        while(!maxH.empty()) {
            
            
            int time =0;
            queue< pair<char, int> > waitQ;
            
            //process n+1 elements from Heap
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
                
                if(--front.second > 0){
                    maxH.push(front);
                }
            }
            
            
            //If heap is not empty
            ans += !maxH.empty() ? cycle : time;
        }//while
        
        
        return ans;
        
    }
    
    int method2(vector<char> &tasks, int n){ 
        
        unordered_map<char, int> mp;
        int maxFreq = 0;
        for(char ch:tasks){
            mp[ch]++;
            maxFreq = max(maxFreq, mp[ch]);
        }
        
        int maxCycles = (n+1) *(maxFreq-1);
        
        for(auto ele: mp)
            if(maxFreq == ele.second)
                maxCycles++;
        
        //cout<<maxCycles<<endl;
        //For cases where n ==1
        return max((int)tasks.size(), maxCycles);
        
        
    }
    
    int leastInterval(vector<char>& tasks, int n) {
        
        //K - max Freq 
        
        //1. method1 - O((n+1)(k)log(26))
        //return method1(tasks, n);
        
        //2. method2 - O(N)
        return method2(tasks, n);
    }
};