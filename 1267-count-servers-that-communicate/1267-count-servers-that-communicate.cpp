class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int R = grid.size();
        int C = grid[0].size();
        
        vector<int> hor(R, 0);
        vector<int> ver(C, 0);
        
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                
                if(grid[i][j]==1){
                    hor[i]++;
                    ver[j]++;
                }
            }//for j
        }//for i
        
        
        int count=0;
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j] ==1 && (hor[i]>1 || ver[j]>1) )
                    count++;
            }//for j
        }//for i
        
        
        return count;
    }
};