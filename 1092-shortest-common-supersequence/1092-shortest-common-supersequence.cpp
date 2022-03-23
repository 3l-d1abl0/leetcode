class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
     	int N = str1.length();
	int M = str2.length();

	vector< vector<int> > dp(N+1, vector<int>(M+1, 0));

	for(int i=0; i<=N; i++){

		for(int j=0; j<=M; j++){

				if(i==0){
					dp[i][j] = j;
					continue;
				}

				if(j==0){
					dp[i][j]=i;
					continue;
				}


				if(str1[i-1]==str2[j-1])
					dp[i][j] = dp[i-1][j-1] +1;
				else
					dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1);
		}
	}


	int index_scs = dp[N][M];

	int i=N, j=M;

	string str(index_scs,'\0');


	while(i>0 && j>0){

		if(str1[i-1]==str2[j-1]){
			str[index_scs-1] = str1[i-1];
			i--;
			j--;
			index_scs--;
		}else if(dp[i-1][j] < dp[i][j-1]){
			str[index_scs-1] = str1[i-1];
			i--;
			index_scs--;
		}else{
			str[index_scs-1] = str2[j-1];
			j--;
			index_scs--;
		}

	}

	while(i >0){
		str[index_scs-1] = str1[i-1];
		i--; index_scs--;
	}

	while(j>0){
		str[index_scs-1] = str2[j-1];
		j--; index_scs--;
	}

	return str;
        
        
        
        
    }
};