class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        
        int N= intervals.size();
        int idx;
        vector<vector<int>> ans;
        
        int i=0;
        //push the meets that occur before newInterval start time
        while(i<N && intervals[i][1]<ni[0]){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        
        //new endtime is greater than starting time of meets
        while(i<N && ni[1]>= intervals[i][0]){
            ni[0] = min(ni[0], intervals[i][0]);
            ni[1] = max(ni[1], intervals[i][1]);
            
            i++;
        }
        
        ans.push_back({ni[0], ni[1]});
        
        //push the rest
        while(i<N){
            ans.push_back({intervals[i][0], intervals[i][1]});
            i++;
        }
        
        return ans;
    }
};