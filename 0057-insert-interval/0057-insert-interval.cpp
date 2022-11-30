class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        
        int N= intervals.size();
        vector<vector<int>> list;
        bool flag = false;
        
        if(N==0)
            return {ni};
        
        
        int i, idx;
        if(intervals[i][0]<= ni[0]){
            list.push_back({intervals[i][0], intervals[i][1]});
            i=1;
        }else{
            list.push_back({ni[0], ni[1]});
            i=0; flag =true;
        }
        
        
        idx=0;
        
        while(flag==false){
            
            if(i<N && intervals[i][0]<= ni[0]){
                
                if(list[idx][0] <= intervals[i][0] && intervals[i][0] <= list[idx][1]){
                    list[idx][0] = min(list[idx][0], intervals[i][0] );
                    list[idx][1] = max(list[idx][1], intervals[i][1] );
                }else{
                    list.push_back({intervals[i][0], intervals[i][1]});
                    idx++;
                }
                
                i++;
                
            }else{
                
                if(list[idx][0] <= ni[0] && ni[0] <= list[idx][1]){
                    list[idx][0] = min(list[idx][0], ni[0] );
                    list[idx][1] = max(list[idx][1], ni[1] );
                }else{
                    list.push_back({ni[0], ni[1]});
                    idx++;
                }
                
                flag = true;
            }
            
        }
        
        
        while(i<N){
            
            if(list[idx][0] <= intervals[i][0] && intervals[i][0] <= list[idx][1]){
                list[idx][0] = min(list[idx][0], intervals[i][0] );
                list[idx][1] = max(list[idx][1], intervals[i][1] );
                
            }else{
                list.push_back({intervals[i][0], intervals[i][1]});
                idx++;
            }
            
            i++;
            
        }
        
        
        return list;
    }
};