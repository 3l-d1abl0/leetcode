class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
     
        //the variables r1, c1, c2 uniquely determine 2 people who have walked the same r1 + c1 number of steps
        int N = grid.size();
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(N, vector<int>(N, -1)));
        
        return max(0, pickUp(grid, 0,0,0,N, memo));
        
    }
    
    
    int pickUp(vector<vector<int>>& grid, int r1,int c1, int r2, int N, vector<vector<vector<int>>>& memo){
        
        int c2 = r1+c1-r2;
        
        
        //if out of bound or thorn
        if(r1>=N || c1>=N || r2>=N || c2>=N || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return INT_MIN;//Unreachable
        
        //If already solved
        if(memo[r1][c1][r2]!=-1)
            return memo[r1][c1][r2];
        
        
        if(r1==N-1 && c1==N-1){ //other person would have reached N-1, N-1 or out of bound
            return grid[r1][c1];
        }
        
        
        int cherry =0;
        
        if(r1==r2 && c1==c2){
            cherry = grid[r1][c1];  //both on same Spot
        }else{
            cherry = grid[r1][c1]+grid[r2][c2];
        }
        
        
        //Traverse all possibel Path- R-R D-D R-D D-R
        cherry += max({ pickUp(grid, r1, c1+1, r2, N, memo),
                        pickUp(grid, r1+1, c1, r2+1, N, memo),
                        pickUp(grid, r1, c1+1, r2+1, N, memo),
                        pickUp(grid, r1+1 ,c1, r2, N, memo)
                       });
        
        
        return memo[r1][c1][r2] = cherry;
        
    }//int
};