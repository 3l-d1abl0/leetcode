class Solution {
public:
    vector<vector<int>> generateMatrix(int N) {
        
        int R = N;
        int C = N;
        vector<vector<int>> mat (R, vector<int>(C, 0));
        
        vector<vector<int>> dir {{0, 1},
                         {1, 0},
                         {0, -1},
                         {-1, 0}};
        
        int x=0, y=0;
        int idx =0;
        for(int i=1; i<=R*C; i++){
            
            mat[x][y] = -i;
            
            //next step
            int xx = x + dir[idx][0];
            int yy = y + dir[idx][1];
            if(xx<0 || yy < 0 || xx >R-1 || yy >C-1 || mat[xx][yy]<0){
                idx = (idx+1)%4;
                xx = x + dir[idx][0];
                yy = y + dir[idx][1];
            }
            
            x = xx;
            y = yy;
        }
        
        
        for(auto &row : mat){
            for(int &ele: row){
                ele *=-1;
            }
        }
        return mat;
    }
};