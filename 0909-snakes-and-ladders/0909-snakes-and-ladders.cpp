class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        
        int N = board.size(), cellNo = 1;
        //To store the row, col no
        vector<pair<int, int>> cells(N*N+1);
        
        vector<int> columns(N);
        iota(columns.begin(), columns.end(), 0);//serial number from 0 to ...
        
        //Traverse chess board to store row, col number
        for (int row = N - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[cellNo++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        
        //Default distance -1
        vector<int> dist(N*N+1, -1);
        
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        
        //BFS
        while (!q.empty()) {
            
            int sz = q.size();
            for(int i=0; i<sz; i++){
                
                int curr = q.front();
                q.pop();
                
                for (int next = curr + 1; next <= min(curr+6, N*N); next++) {
                    
                    auto [row, column] = cells[next];
                    
                    int destination = board[row][column] != -1 ? board[row][column] : next;
                    if (dist[destination] == -1) {
                        dist[destination] = dist[curr] + 1;
                        q.push(destination);
                        
                        if(destination == N*N)
                            return dist[N*N];
                    }
                }
            
            }//for 
        }//While
        
        
        return dist[N*N];
    }
};