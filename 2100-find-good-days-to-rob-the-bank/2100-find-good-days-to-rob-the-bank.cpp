class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
    
        int N = sec.size();
        
        //[i] - represents how many number before this index are in decreasing order
        vector<int> before (N, 0);
        
        //[i] - represents how many number before this index are in increasing order
        vector<int> after (N, 0);
        
        
        for(int i=1; i<N; i++){
            before[i] = (sec[i-1]>=sec[i])?before[i-1]+1:0;
        }
        
        for(int i= N-2; i>=0; i--){
            after[i] = (sec[i+1]>=sec[i])?after[i+1]+1:0;
        }
        
        
        vector<int> ans;
        
        for(int i=time; i<N-time; i++){
            if(before[i]>=time && after[i]>=time)
                ans.push_back(i);
        }
        
        
        
        return ans;
    }
    
};