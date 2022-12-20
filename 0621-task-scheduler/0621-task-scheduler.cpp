struct CompareFn{
    
    bool operator()(pair<char, int> &a, pair<char, int> &b){
        return a.second < b.second;
    }
    
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        
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
            for(int i=1; i<=cycle; i++){
                
                if(!maxH.empty()){
                    waitQ.push(maxH.top());
                    maxH.pop();

                    time++;
                }
                
            }
            
            //clear the waiting Queue
            while(!waitQ.empty()){
                auto front = waitQ.front();
                waitQ.pop();
                
                if(--front.second > 0){
                    maxH.push(front);
                }
            }
            
            
            ans += !maxH.empty() ? cycle : time;
        }//while
        
        
        return ans;
    }
};