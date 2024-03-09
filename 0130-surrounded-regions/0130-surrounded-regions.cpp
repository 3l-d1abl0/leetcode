class Solution {
public:
    void solve(vector<vector<char>>& board) {
    
        
        /*
            The node will cannote be surroundes on all sides
            are the ones lying on the edges,
            hence every node connected to it
            wont be able to get surrounded
        
        */
        
        int N = board.size();
	
	int M = board[0].size();
	
	
	vector<vector<bool> > visited (N, vector<bool> (M, false));
	
	
	//row 0
	for(int j=0; j<M; j++){
		if(board[0][j]=='O' && visited[0][j]== false)
			dfs(0, j, visited, board, N, M);
	}
	

	//row N-1
	for(int j=0; j<M; j++){
		if(board[N-1][j]=='O' && visited[N-1][j]== false)
		
			dfs(N-1, j, visited, board, N, M);
	}
	
	
	//col 0
	for(int i=1; i<=N-2; i++){
		if(board[i][0]=='O' && visited[i][0]== false)
			dfs(i, 0, visited, board, N, M);
	}

	//col M-1
	for(int i=1; i<=N-2; i++){
		if(board[i][M-1]=='O' && visited[i][M-1]== false)
			dfs(i, M-1, visited, board, N, M);
	}
	
	
    /*
    Nodes that cannot be surrounded will be unvisited as ogf now
    */
	for(int i=1; i<N-1; i++){
		for(int j=1; j<M-1; j++){
			
			if(board[i][j] =='O' && visited[i][j]==false)
				board[i][j] = 'X';
			
		}
	}
	
	//return board;
        
        
    }
    
    void dfs(int row, int col, vector<vector<bool> > &visited, vector<vector<char>> &board, int N, int M){
	//cout<<row<<"  "<<col<<endl;
	visited[row][col] = true;
	
	vector<vector<int>> dir{{-1,0},{0,1},{1,0},{0,-1}};
	
	for(int i=0; i<4; i++){
		
		if(row+dir[i][0] <0 || col+dir[i][1]<0 || row+dir[i][0]>= N || col+dir[i][1]>= M)
			continue;
		
		if(board[row+dir[i][0]][col+dir[i][1]]=='O' && visited[row+dir[i][0]][col+dir[i][1]]== false){
			dfs(row+dir[i][0], col+dir[i][1], visited, board, N, M);
		}
	}
	
	
}
};