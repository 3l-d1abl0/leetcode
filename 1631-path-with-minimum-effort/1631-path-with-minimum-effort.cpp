class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int R = heights.size();
        int C = heights[0].size();
        
        vector<vector<int>> maxDiff(R, vector<int>(C, 1e7));
        
        queue<pair<int, int>> q;
        q.push({0,0});
        
        maxDiff[0][0]=0;
        
        vector<vector<int>> dir{ {0, -1} , {1, 0}, {0, 1}, {-1, 0}};
        
        while(!q.empty()){
            
            auto node = q.front();    q.pop();
            
            int x = node.first, y= node.second;
            
            for(vector<int> &xy: dir){
                
                int xx= x+xy[0];
                int yy= y+xy[1];
                
                if(0<=xx && xx<R && 0<=yy && yy<C){
                    
                    int max_diff_so_far = max(maxDiff[x][y], abs(heights[x][y]-heights[xx][yy]));
                    if(max_diff_so_far < maxDiff[xx][yy]){
                        q.push({xx, yy});
                        maxDiff[xx][yy] = max_diff_so_far;
                    }
                    
                    
                } //boundary
                
            
            }
        
        
        
        }//while
        
        return maxDiff[R-1][C-1];
    }
};