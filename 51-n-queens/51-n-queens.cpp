class Solution {
public:
    
    void printBoard( vector<string> &board){


    for(auto row: board){

        for(auto ele: row){
            cout<<ele<<" ";
        }

        cout<<endl;
    }

    cout<<endl<<endl<<endl;
}
    
    
    
    
    bool safe(vector<string> &board, int row, int col, vector<bool> &rowCheck, vector<bool> &bottomleft, vector<bool> &upperLeft){
    
    int N = board.size();

    if(rowCheck[row]==true)
        return false;

    if(bottomleft[row+col]==true)
        return false;

    if(upperLeft[row+ (N-col)]== true)
        return false;

    //printBoard(board);
    return true;

    }
    
    
    
    
    void NQueens(vector<string> &board, int col, vector<vector<string>> &ans, vector<bool> &rowCheck, vector<bool> &bottomleft, vector<bool> &upperLeft){

        int N = board.size();

        if(col == N){
            //printBoard(board);
            ans.push_back(board);
            return;
        }


            for(int row=0; row<N; row++ ){

                if(safe(board, row, col, rowCheck, bottomleft, upperLeft)){

                    board[row][col]='Q';
                    rowCheck[row] = true; bottomleft[row+col] = true; upperLeft[row+ (N-col)]=true;
                    
                    NQueens(board, col+1, ans, rowCheck, bottomleft, upperLeft);
                    
                    board[row][col]='.';
                    rowCheck[row] = false; bottomleft[row+col] = false; upperLeft[row+ (N-col)]=false;

                }


            }

    


}
    
    
    
    
    
    vector<vector<string>> solveNQueens(int N) {
     
        
        vector<bool> rowCheck(N, false);
        vector<bool> bottomleft(N, false);
        vector<bool> upperLeft(N, false);
        
        vector<vector<string>> ans;
        
        vector<string> board(N, string(N,'.'));

        //printBoard(board);
        NQueens(board, 0, ans, rowCheck, bottomleft, upperLeft);
        
        
        return ans;
    }
};