class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        /*
        You can travel from one cell to another cell with zero time if they are below or equal to current
        water level.
        
        if a neighbour's height is greater than the current time ,
        you will have to wait for (neigh's height - t) to swim to neight.
        
        Basically, you have
        
        For every cell store the wait time to reach the node.
        If you can reach a cell with smaller wait tiem,
        preocess it again.
        Basically Dijkastra.
        
        */
        
        int N = grid.size();
        
        //<wait_time, cell_coords>
        priority_queue< pair<int, pair<int, int>>, vector<pair<int, pair<int, int>> >,  greater<pair<int, pair<int, int>> > >minHeap;
        
        vector<vector<bool>> vis(N, vector<bool> (N, false));
        
        
        //start fron top left
        vis[0][0] = true;
        
        //maxHeightClimbed, cell coords 
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
                
                //If the height climbed is greater than the next grid heifht - just move 
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