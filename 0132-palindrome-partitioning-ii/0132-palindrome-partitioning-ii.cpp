class Solution {
public:
    
    bool isPalin(int beg, int en, string &s){
        
        while(beg<en){
            if(s[beg++]!=s[en--])
                return false;
        }
        return true;
    }
    
    
    int minPartDp(string &s){
        
        if(s.size()==0) return 0;
        
        int N = s.size();
        vector<int> dp(N+1, 1e8);
        
        
        dp[N] = 0;
        
        for(int i=N-1; i>=0; i--){
            
            int minn = INT_MAX;
            
            for(int j=i; j<N; j++){

                if(isPalin(i, j, s)){

                    minn = min(minn, dp[j+1]+1);
                }
            }
        
            dp[i]=minn;
        }
        
        /*for(int ele: dp){
            cout<<ele<<" ";
        }cout<<endl;
        */
        return dp[0]-1;
        
    }
    
    int minCut(string s) {
        
        
        //vector<int> memo(s.size(), -1);
        //return minpart(0, s, memo)-1;
        
        return minPartDp(s);
    }
};