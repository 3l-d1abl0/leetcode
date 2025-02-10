class Solution {
public:
    
    vector<vector<int>> bfs(vector<vector<int>> &heights, queue<pair<int, int>> &q, vector<vector<bool>> &O1, vector<vector<bool>> &O2){
        
        
        /*
        Call1 - queue has all the edge node which is touching 
        Pacific Ocean
        O1 - pacific Ocean
        O2 = Atlantic Ocean
        */
        
        int R= heights.size();
        int C = heights[0].size();
        int cnt =0;
        vector<pair<int, int>> dir { {-1, 0}, {0, 1}, {1,0}, {0, -1}};
        vector<vector<int>> ans;
        
        while(!q.empty()){
            
            auto [r, c] = q.front();
            q.pop();
            
            /*
                For 1st call - O2 will be atlantic Ocean, all false

                For 2nd round of BFS,
                O2 will be pacific Ocean, Some True
                check the if the current cell
                is visited by other sea
            */
            if(O2[r][c] == true)
                ans.push_back({r,c});
            
            
            for(auto [dr, dc]: dir){
                
                int nr =r+dr;
                int nc =c+dc;
                
                //out of bound or already visited
                if(nr<0 || nc <0 || nr>=R || nc>=C || O1[nr][nc] == true || heights[r][c] > heights[nr][nc])
                    continue;
                
                q.push({r+dr, c+dc});
                O1[r+dr][c+dc]=true;
            }    
            
            
        }//while
        
        return ans;
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int R = heights.size();
        int C = heights[0].size();
        
        vector<vector<bool>> PO(R, vector<bool>(C, false));
        vector<vector<bool>> AO(R, vector<bool>(C, false));
        queue<pair<int, int>> q;
        
        //Look for nodes visited by Pacific Ocean (Reachability)
        //set the zeroth Columns
        for(int r=0; r<R; r++){
            q.push({r, 0});
            PO[r][0]=true;
        }
        //set the zeroth Row
        for(int c=1; c<C; c++){
            q.push( {0, c});
            PO[0][c]=true;
        }
        

        vector<vector<int>> ans = bfs(heights, q, PO, AO);
        
        //Look for nodes visted by Atlantic Ocean
        for(int r=0; r<R; r++){
            q.push({r, C-1});
            AO[r][C-1] =true;
        }
        
        for(int c=0; c<C-1; c++){
            q.push( {R-1, c});
            AO[R-1][c]=true;
        }
        
        ans = bfs(heights, q, AO, PO);//Order of oceans Changed
        
        return ans;
    }
};