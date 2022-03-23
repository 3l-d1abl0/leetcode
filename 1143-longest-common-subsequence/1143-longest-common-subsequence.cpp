class Solution {
public:
    int longestCommonSubsequence(string str1, string str2) {
        	int N = str1.length();
	int M = str2.length();

	vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

	for(int i=1; i<=N; i++){
		for(int j=1; j<=M; j++){

			if(str1[i-1] ==str2[j-1])
				dp[i][j]= dp[i-1][j-1]+1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}


	return dp[N][M];
    }
};