class Solution {
public:
    
    
    bool isValid(int row, int col, char c, vector < vector < char >> & board) {
      
        for (int i = 0; i < 9; i++) {
        if (board[i][col] == c)
              return false;

            if (board[row][i] == c)
              return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
              return false;
         }
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        
        for(int r=0; r< board.size(); r++){
            
            for(int c=0; c<board[0].size(); c++){
                
                //empty need to fill
                if(board[r][c]=='.'){
                    
                    for(char ch='1'; ch<='9'; ch++){
                        
                        if(isValid(r, c, ch, board)){
                            
                            //put the char
                            board[r][c]=ch;
                            if( solve(board) )
                                return true;
                            else
                                board[r][c]='.';    //undo the box
                        }
                    }//for - all possible char for this block
                    
                    return false;
                }
            }
        }
        
        //base case - all are set
        return true;
        
    }//solve
    
    void solveSudoku(vector<vector<char>>& board) {
        
        
        
        solve(board);
        
        
    }
};