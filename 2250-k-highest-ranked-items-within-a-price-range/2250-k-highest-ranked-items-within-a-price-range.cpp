class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {

        int R = grid.size();
        int C = grid[0].size();

        //set uuup visited - false by default
        vector<vector<bool>> visited(R, vector<bool>(C, false));


        //priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int ,int>>, greater<tuple<int, int, int, int>>> pq;
        vector<tuple<int, int, int ,int>> valid;

        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        int distance =0;
        queue<tuple<int, int>> q;
        q.push({start[0], start[1]});
        

        
        while(!q.empty()){

            int size = q.size();
            //Loop through all points at a certain distance
            for(int sz=0; sz<size; sz++){

                auto [r, c] = q.front();    q.pop();

                if(visited[r][c] == true)
                    continue;

                visited[r][c] = true;
                if(grid[r][c]==0)
                    continue;


                //if grid is not a empty Cell, consider it
                if(grid[r][c]!=1){

                    //within pricing Range
                    if(grid[r][c]>= pricing[0] && grid[r][c]<=pricing[1]){
                        
                        //pq.push({distance, grid[r][c], r, c});
                        valid.push_back({distance, grid[r][c], r, c});
                    }
                }

                //loop neighbours
                for(auto xy: dir){

                    int row = r+xy[0], col = c+xy[1];
                    if(row>=0 && row<R && col>=0 && col<C){ //in board

                        q.push({row, col});
                    }
                }

            }//for

            distance++;
        }//while

        vector<vector<int>> ans;
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int ,int>>, greater<tuple<int, int, int, int>>> pq(valid.begin(), valid.end());
        //sort(valid.begin(), valid.end());
        //Top k from heap
        while(!pq.empty() && ans.size() <k){

            auto [dist, price, row, col] = pq.top(); pq.pop();
            ans.push_back({row, col});
        }

        /*for(int i=0; i< min(k, (int)valid.size()); i++){
            ans.push_back({get<2>(valid[i]), get<3>(valid[i])});
        }*/


        return ans;
    }
};