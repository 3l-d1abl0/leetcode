class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
     
            int M = matrix.size();
            int N = matrix[0].size();

            vector<vector<int>> dp(M, vector<int> (N, 0));

            int maxSide =0;
            //Rows
            for(int i=0; i<M; i++){
                dp[i][0] = int(matrix[i][0])-48;
                maxSide = max(maxSide, dp[i][0]);
            }

            //columns
            for(int i=1; i<N; i++){
                dp[0][i] = int(matrix[0][i])-48;
                maxSide = max(maxSide, dp[0][i]);
            }

            //cout<<"cnt:: "<<maxSide<<endl;
            for(int i=1; i<M; i++){
                for(int j=1; j<N; j++){

                    if(matrix[i][j]=='0')
                        dp[i][j] = 0;
                    else{
                        dp[i][j] = 1+ min( {dp[i-1][j-1], dp[i-1][j], dp[i][j-1]} ); 

                        maxSide = max(maxSide, dp[i][j]);
                    }
                }//for j
            }//for i


            //print(dp);
            return  maxSide*maxSide;
        
    }
};