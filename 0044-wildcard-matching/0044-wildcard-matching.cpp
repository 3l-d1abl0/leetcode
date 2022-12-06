class Solution {
public:
    
    bool recur(int idx1, string &s, int N, int idx2, string &p, int M, vector<vector<int>> &memo){
        
        
        if(idx1==N && idx2==M)
                return true;
        
        if(idx2==M)
            return false;


        if(idx1==N){
            for(int i=idx2; i<M; i++){
                if(p[i]!='*')
                    return false;
            }
            return true;
        }
        
            
        
        
        if(memo[idx1][idx2]!=-1)
            return memo[idx1][idx2];
        
        bool ans = false;
        
        //cout<<s[idx1]<<" "<<p[idx2]<<endl;
        if (p[idx2]=='*'){
            ans = recur(idx1+1, s, N, idx2, p, M, memo) || recur(idx1, s, N, idx2+1, p, M, memo);
        }else if(s[idx1]==p[idx2] || p[idx2]=='?'){
                ans = recur(idx1+1, s, N, idx2+1, p, M, memo);
        }else{
                //cout<<"NOTEQUAL"<<endl;
                ans = false;
        }
        
            
        
        return memo[idx1][idx2] = ans;
        
    }
    
    bool isMatch(string s, string p) {
        
        int N = s.size();
        int M = p.size();
        
        
        vector<vector<int>> memo(N, vector<int> (M, -1));
        return recur(0, s, N, 0, p, M, memo);
    }
};