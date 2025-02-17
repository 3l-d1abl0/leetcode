class Solution {
public:
    
    bool topDown(int sidx, string &s, int pidx, string &p, vector<vector<int>> &memo){
        
        //both strings finished
        if(sidx==0 && pidx<=0)
            return true;
        //string finished, patter remains with single character
        if(sidx==0 && pidx<=1)
            return false;
        
        //string remains, pattern finished
        if(sidx>0 && pidx<=0)
            return false;
        
        /*if(sidx==0 && pidx >0){
            //cout<<"-here- "<<pidx<<endl;
            
            //bool status = true;
            for(int i=pidx; i>=1 ; i-=2){
                if(p[i-1]!='*')
                    return false;
            }
            
            if(pidx==1)
                return false;
            
            return true;
        }*/
        
        if(memo[sidx][pidx]!=-1)
            return memo[sidx][pidx];
        
        
        if(s[sidx-1]== p[pidx-1] || p[pidx-1]=='.'){
            return memo[sidx][pidx] = topDown(sidx-1, s, pidx-1, p, memo);
        }else if(p[pidx-1]=='*'){
            bool exclude = topDown(sidx, s, pidx-2, p, memo);
            
            bool include =false;
            if(s[sidx-1]==p[pidx-2] || p[pidx-2]=='.'){
                include = topDown(sidx-1, s, pidx, p, memo);
            }
            
            return memo[sidx][pidx] = exclude || include;
        }
        
        return memo[sidx][pidx] = false;   
    }
    
    bool isMatch(string s, string p) {
        
        int N = s.size();
        int M = p.size();
        
        vector<vector<int>> memo(N+1, vector<int>  (M+1, -1));
        
        return topDown(N, s, M, p, memo);
    }
};