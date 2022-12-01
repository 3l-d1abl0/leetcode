class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        /*sort asc as per starting time
         if starting time equal, sort ending time descending , so that for same starting time,
          greater ending time comes first
          
          [1, 4] [2, 8] [3, 9] [3, 10]
         */
        
        sort(intervals.begin(), intervals.end(), [](const auto& x, const auto& y){
            return x[0] != y[0] ? x[0] < y[0] : x[1] > y[1];
        });
        
        
        int rightmost_b =-1;
        int cnt =0;
        
        for(auto row: intervals){
            
            if(row[1] > rightmost_b){
                
                cnt++;
                rightmost_b = row[1];
            }
            
        }
        
        return cnt;
        
        
    }
};