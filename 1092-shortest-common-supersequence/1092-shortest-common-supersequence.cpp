class Solution {
public:
    
    void print2D(vector<vector<int>> &dp){
        
        for(auto row: dp){
            for(int ele: row)
                cout<<ele<<" ";
            cout<<endl;
        }
    }
    
    int findLCSLen(string &str1, int N, string &str2, int M, vector<vector<int>> &dp){
        
        //N - 0
        //M -0
        
        for(int i=0; i<=M; i++)
            dp[0][i] = 0;
        
        for(int i=0; i<=N; i++)
            dp[i][0] = 0;
        
        for(int idx1= 1; idx1<=N; idx1++){
            
            for(int idx2= 1; idx2<=M; idx2++){
                
                if(str1[idx1-1] == str2[idx2-1]){
                    dp[idx1][idx2] = 1+dp[idx1-1][idx2-1];
                }else{
                    dp[idx1][idx2] = max(dp[idx1][idx2-1], dp[idx1-1][idx2]);
                }
                
            }//for idx2
            
        }//for idx1
        
        //print2D(dp);
        return dp[N][M];
        
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        
        /*
        Take the LCS (will be common in both string)
        add rest of the characters from s1
        add rest of the characters from s2
        */
        int N = str1.size();
        int M = str2.size();
        
        vector<vector<int>> dp(N+1, vector<int> (M+1, 0));
        
        int LCSLen = findLCSLen(str1, N, str2, M, dp);
        
        //cout<<LCSLen<<endl;
        
        
        int i=N, j=M;
        string scs = "";
        
        while(i>0 && j>0){
            
            if(str1[i-1]==str2[j-1]){
                scs+=str1[i-1];
                i--; j--;
            }else{
                
                if(dp[i][j-1] >= dp[i-1][j]){
                    scs+=str2[j-1]; j--;
                }else{
                    scs += str1[i-1]; i--;
                }
                
            }
            
        }//while
        
        while(i>0){
            scs += str1[i-1];
            i--;
        }
        
        while(j>0){
            scs += str2[j-1];
            j--;
        }
        
        reverse(scs.begin(), scs.end());
        
        return scs;
    }
};