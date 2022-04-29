class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        
        int R = matrix.size();
        int C = matrix[0].size();
        
        vector<vector<int>> dir {{0, 1},
                                 {1, 0},
                                 {0, -1},
                                 {-1, 0}};
        
        vector<int> ans;
        int x=0, y=0;
        int idx =0;
        for(int i=0; i<R*C; i++){
        
            ans.push_back(matrix[x][y]);
            matrix[x][y] +=500;
            
            //next step
            int xx = x + dir[idx][0];
            int yy = y + dir[idx][1];
            if(xx<0 || yy < 0 || xx >R-1 || yy >C-1 || matrix[xx][yy]>=400){
                idx = (idx+1)%4;
                xx = x + dir[idx][0];
                yy = y + dir[idx][1];
            }
            
            x = xx;
            y = yy;
            
            
        }
        
        return ans;
    }
};