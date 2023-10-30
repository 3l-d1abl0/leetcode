class Solution {
public:
    
    struct CompFn{
        
        bool operator()(const pair<int, int> &a, const pair<int, int> &b){
            
            if(a.first==b.first)
                return a.second > b.second;
            else
                return a.first > b.first;
        }
    };
    
    vector<int> method1(vector<vector<int>>& intervals) {
        
        int N = intervals.size();
             
        vector<int> ans (N, -1);
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompFn> minStartHeap;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompFn> minEndHeap;
        
        for(int i=0; i<N; i++ ){
            
            minStartHeap.push({intervals[i][0], i});
            minEndHeap.push({intervals[i][1], i});
        }
        
        while(!minEndHeap.empty() && !minStartHeap.empty()){
            
            if(minStartHeap.top().first >= minEndHeap.top().first){
                ans[minEndHeap.top().second] = minStartHeap.top().second;
                minEndHeap.pop();
            }else{
                minStartHeap.pop();
            }
            
        }//while
        
        
        return ans;
        
    }
    
    
    vector<int> method2(vector<vector<int>>& intervals) {
        
        int N = intervals.size();
        
        map<int, int> start;
        
        for(int i=0; i<N; i++){
            
            start[intervals[i][0]] = i;
            
        }
        
        
        vector<int> ans(N, -1);
        
        for(int i=0; i<N; i++){
            
            //lower bound - >=
            auto itr = start.lower_bound(intervals[i][1]);
            
            if(itr == start.end())
                ans[i] = -1;
            else
                ans[i] = itr->second;
        }
        
        
        return ans;
    }
    
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        
        //Using 2 Heaps
        //return method1(intervals);
        
        
        //Using OrderedMap + Binary Search
        return method2(intervals);
     
    }
};