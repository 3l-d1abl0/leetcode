class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> dp (n, 1);
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                
                dp[j] += dp[j-1];
            }
        }
        
        //print(dp);
        return dp[n-1];
        
    }
    void print(vector<vector<int>> &dp){
        
        for(auto row: dp){
            for(int ele: row){
                cout<<ele<<" ";
            }
            cout<<endl;
        }
    }
};