class Solution {
public:
    
    void expandCorners(string &s, int i, int j, int &maxLen, int &beg){
        
        
        int N = s.size();
        
        while(i>=0 && j<N && s[i]==s[j]){
            
            
            if(j-i+1 > maxLen){
                maxLen = j-i+1;
                beg = i;
            }
            i--; j++;
        }
        
    }
    
    string method1(string &s){
        
        int maxLen =0;
        int beg = 0;
        
        
        for(int i=0; i<s.size(); i++){
            
            expandCorners(s, i, i, maxLen, beg);//odd length
            
            expandCorners(s, i, i+1, maxLen, beg);//even length
        }
        
        //cout<<beg<<" "<<maxLen<<endl;
        
        return s.substr(beg, maxLen);
        
    }
    
    string method2(string &str){
        
        int N = str.size();
        
        vector<vector<bool>> dp(N, vector<bool> (N, false));
        
        int beg=0, maxLen = 1;
        
        //len 1
        for(int i=0; i<N; i++){
            dp[i][i] =1;
        }
        
        //len 2
        for(int i=0; i<N-1; i++){

            if(str[i]==str[i+1]){            
                dp[i][i+1] = 1;
                beg=i;
                maxLen=2;
            }
        }
        
        //len 3 onwards
        
        for(int i=3; i<=N; i++){
            
            for(int j=0; j<=N-i; j++){
                
                if(str[j]==str[j+i-1] && dp[j+1][j+i-2]){
                    dp[j][j+i-1] = true;
                    maxLen = i;
                    beg=j;
                }
                
            }
        }
        
        return str.substr(beg, maxLen);
    }
    
    
    string manacher(string &s){
    
        //cout<<"_"<<s<<"_"<<endl;
        //SUB --> #S#U#B_
        string  str = string((int)s.length() * 2 + 1, '_');
        for(int idx =0; idx<s.size(); idx++){
            str[idx*2] ='#';
            str[(idx*2)+1]= s[idx];
        }
        
        //Set last pos as #     #S#U#B_ --> #S#U#B# 
        int N = str.size();
        str[N-1]='#';

        //cout<<str<<endl;

        vector<int> P(N, 0);
        int C = 0, R = 0;

        for (int i = 1; i < N - 1; i++) {

            // Expand around i
            int mirror = 2 * C - i;
            if (i < R) {
                P[i] = min(R - i, P[mirror]);
            }

            //cout<<"#####"<<endl;
            // Expand manually
            while (i + 1 + P[i] < N && i - 1 - P[i] >= 0 && str[i + 1 + P[i]] == str[i - 1 - P[i]]) {
                P[i]++;
            }

            //cout<<"#######"<<endl;
            // Update C and R
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // Find the maximum length and start index
        int max_len = 0, start = 0;
        for (int i = 1; i < N - 1; i++) {
            if (P[i] > max_len) {
                max_len = P[i];
                start = (i - P[i]) / 2;
            }
        }

        // Convert back to the original string
        return s.substr(start, max_len);
        
    }
    
    string longestPalindrome(string s) {
        
        ///expand around corners O(n^2)
        //return method1(s);
        
        
        //DP o(n^2)
        //return method2(s);
        
        
        //3. Manacher
        return manacher(s);
        
    }
};