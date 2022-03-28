class Solution {
public:
    
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
    
    
    
    
    int NQueens(vector<string> &board, int col, vector<bool> &rowCheck, vector<bool> &bottomleft, vector<bool> &upperLeft){

        int N = board.size();

        if(col == N){
            //printBoard(board);
            return 1;
            
        }

            int sum =0;

            for(int row=0; row<N; row++ ){

                if(safe(board, row, col, rowCheck, bottomleft, upperLeft)){

                    board[row][col]='Q';
                    rowCheck[row] = true; bottomleft[row+col] = true; upperLeft[row+ (N-col)]=true;
                    
                    sum +=NQueens(board, col+1, rowCheck, bottomleft, upperLeft);
                    
                    board[row][col]='.';
                    rowCheck[row] = false; bottomleft[row+col] = false; upperLeft[row+ (N-col)]=false;

                }


            }

    
    return sum;

}
    int totalNQueens(int N) {
     
        
        vector<bool> rowCheck(N, false);
        vector<bool> bottomleft(N, false);
        vector<bool> upperLeft(N, false);
        
        
        vector<string> board(N, string(N,'.'));

        return NQueens(board, 0, rowCheck, bottomleft, upperLeft);
        
        
    }
};