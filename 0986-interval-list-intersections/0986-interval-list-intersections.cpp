class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& fL, vector<vector<int>>& sL) {
     
        int i=0, j=0;
        
        vector<vector<int>> ans;
        
        while(i<fL.size() && j<sL.size()){
            
            int low = max(fL[i][0], sL[j][0]);
            int high = min(fL[i][1], sL[j][1]);
            
            
            if(low<=high)
                ans.push_back({low, high});
            
            //interval with max ending time stays
            if(fL[i][1]<sL[j][1]){
                i++; 
            }else{
                j++;
            }
            
        }//while
        
        
        return ans;
        
    }
};