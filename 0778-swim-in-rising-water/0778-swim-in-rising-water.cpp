class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        
        int N = grid.size();
        
        
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>> >,  greater<pair<int, pair<int, int>> > >minHeap;
        
        vector<vector<bool>> vis(N, vector<bool> (N, false));
        
        
        //start fron top left
        vis[0][0] = true;
        minHeap.push( {grid[0][0], {0, 0} });   //height, {x, y}
        
        
        vector<int> dx = {0, -1, 0, 1};
        vector<int> dy = {-1, 0, 1, 0};
        
        while(!minHeap.empty()){
            
            auto node = minHeap.top();
            minHeap.pop();
            
            int maxHeight = node.first;
            pair<int, int> coord = node.second;
            
            if(coord.first == N-1 && coord.second == N-1)
                return maxHeight;
            
            
            for(int i=0; i<4; i++){
                
                int xx = coord.first+dx[i];
                int yy = coord.second+dy[i];
                
                if(xx <0 || xx >= N || yy <0 || yy>=N || vis[xx][yy]==true)
                    continue;
                
                
                vis[xx][yy] = true;
                if(maxHeight >= grid[xx][yy]){
                    minHeap.push({maxHeight, {xx, yy}});
                }else{
                    minHeap.push({grid[xx][yy], {xx, yy}});
                }
                
            }//for
            
            
        }//while
        
        return -1;
    }
};