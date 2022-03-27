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
    
    
    
    
    bool safe(vector<string> &board, int row, int col){
    
        int N = board.size();
        if(row == N || col == N)
            return false;

        int r,c;


        //1.check Left
        c= col-1;
        while(c>=0){
            if(board[row][c]=='Q')
                return false;

            c--;
        }

        //2. check left-diagonal top
        r=row-1, c=col-1;
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q')  return false;
            r--; c--;
        }

        //3. check left diagonal bottom
        r=row+1, c= col-1;
        while(r<N && c>=0){

            if(board[r][c] =='Q')   return false;
            r++; c--;
        }

        //printBoard(board);
        return true;

    }
    
    
    
    
    void NQueens(vector<string> &board, int col, vector<vector<string>> &ans){

        int N = board.size();

        if(col == N){
            //printBoard(board);
            ans.push_back(board);
            return;
        }


            for(int row=0; row<N; row++ ){

                if(safe(board, row, col)){

                    board[row][col]='Q';
                    NQueens(board, col+1, ans);
                    board[row][col]='.';

                }


            }

    


}
    
    
    
    
    
    vector<vector<string>> solveNQueens(int N) {
     
        
        vector<vector<string>> ans;
        
        vector<string> board(N, string(N,'.'));

        //printBoard(board);
        NQueens(board, 0, ans);
        
        
        return ans;
    }
};