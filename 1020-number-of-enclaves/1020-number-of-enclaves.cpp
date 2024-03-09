static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
     
        
        /*
            Start from the edges and mark off all the land cells
            from whiohc we can walk off the Grid
            
            
            Traverse again to check the unmarked
        */
        
        int N = grid.size();
        int M = grid[0].size();
        
        
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if((i==0 || j==0 || i==N-1 || j==M-1) && (grid[i][j]==1) )
                    dfs(i, j, grid);
        
        
        int ctr =0;
        
        for(int i=1; i<N-1; i++){
            for(int j=1; j<M-1; j++){
                
                if(grid[i][j]==1){
                    ctr++;
                    
                }
                
            }
        }
        
        
       // printdp(grid);
        return ctr;
        
    }
    
    void dfs(int i, int j, vector<vector<int>> &grid){
        
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)
            return;
        
        
        grid[i][j] = 0;
        
        
        dfs(i-1, j, grid);
        dfs(i, j+1, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
                    
    }
    
    void printdp(vector<vector<int>> &grid){
        
        
        for(auto row: grid){
            for(int ele: row){
                cout<<ele<<" ";
            }
            
            cout<<endl;
        }
    }
    
};