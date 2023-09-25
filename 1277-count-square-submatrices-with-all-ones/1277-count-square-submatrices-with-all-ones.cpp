class Solution {
public:
    
    void print(vector<vector<int>> &dp){
        
        for(auto row: dp){
            
            for(int ele: row){
                cout<<ele<<" ";
            }
            
            cout<<endl;
        }
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        
        
        int M = matrix.size();
        int N = matrix[0].size();
        
        vector<vector<int>> dp(M, vector<int> (N, 0));
        
        int count =0;
        //Rows
        for(int i=0; i<M; i++){
            dp[i][0] = matrix[i][0];
            count += dp[i][0];
        }
        
        //columns
        for(int i=1; i<N; i++){
            dp[0][i] = matrix[0][i];
            count += dp[0][i];
        }
        
        cout<<"cnt:: "<<count<<endl;
        for(int i=1; i<M; i++){
            for(int j=1; j<N; j++){
                
                if(matrix[i][j]==0)
                    dp[i][j] = 0;
                else{
                    dp[i][j] = 1+ min( {dp[i-1][j-1], dp[i-1][j], dp[i][j-1]} ); 
                    
                    count +=dp[i][j];
                }
            }//for j
        }//for i
        
        
        //print(dp);
        return  count;
    }
};