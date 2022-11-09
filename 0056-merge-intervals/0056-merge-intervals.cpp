class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int N = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        int idx;
        vector<vector<int>> ans;
        for(int i=0; i<N; i++){
            
            if(i==0){
             ans.push_back({intervals[i][0], intervals[i][1]});   
                idx=0;
            }else{
                
                if(ans[idx][0]<=intervals[i][0] && intervals[i][0]<=ans[idx][1]){
                    
                    ans[idx][0] = min(ans[idx][0], intervals[i][0]);
                    ans[idx][1] = max(ans[idx][1], intervals[i][1]);
                    
                }else{
                    ans.push_back({intervals[i][0], intervals[i][1]});
                    idx++;
                }
                
            }
            
        }
        
        return ans;
    }
};